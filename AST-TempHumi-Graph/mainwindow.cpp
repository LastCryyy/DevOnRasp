#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QtNetwork/QUdpSocket>
#include <QtNetwork/QHostAddress>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    sauvtext = new QString();
    outStream = new QTextStream(sauvtext);
    SOCKET_STATE = 0;
    setupRealtimeDataDemo(ui->graph);

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::initSocket(int port)
 {
     udpSocket = new QUdpSocket(this);
     //udpSocket->bind(QHostAddress::Broadcast, port);
     udpSocket->bind(QHostAddress::Any, port);
     connect(udpSocket, SIGNAL(readyRead()),
             this, SLOT(readPendingDatagrams()));
     qDebug() << "ouvert";
 }

 void MainWindow::readPendingDatagrams()
 {
     QString ret_txt = "";
     while (udpSocket->hasPendingDatagrams())
     {
         QByteArray datagram;
         datagram.resize(udpSocket->pendingDatagramSize());
         QHostAddress sender;
         quint16 senderPort;

         udpSocket->readDatagram(datagram.data(), datagram.size(),
                                 &sender, &senderPort);

         ret_txt = process_data(datagram);
     }
     //qDebug() << "reçu ?";
 }


QString MainWindow::process_data(QByteArray data)
{
    st_float Acx;
    st_float Acy;
    st_float Acz;
    QString Acx_txt = "";
    QString Acy_txt = "";
    QString Acz_txt = "";
    QString heuretxt = "";
    int curtime;

    int8_t i = 0;

    for(i = 0; i < 2; i++)
    {
        Acx.fdata[i] = data.at(i);
    }


    for(i = 0; i < 2; i++)
    {
        Acy.fdata[i] = data.at(2 + i);
    }

    for(i = 0; i < 2; i++)
    {
        Acz.fdata[i] = data.at(4 + i);
    }
    //graph_data_update(ui->graph,Acx.f1,Acy.f1,Acz.f1);
    Acx_txt.setNum(Acx.f1);
    Acy_txt.setNum(Acy.f1);
    Acz_txt.setNum(Acz.f1);
     qDebug() << Acz.fdata[0] << "," << Acz.fdata[1];

    curtime = heure.elapsed();
    heuretxt.setNum(curtime);
    *outStream << curtime << "," << Acx.f1 << "," << Acy.f1 << "," << Acz.f1 << "\n";


    //modifications pour calcul de traitement a partir des donnees brutes ci dessous
    ui->txt_output->append(heuretxt + ";"  + Acx_txt + " ; " + Acy_txt + " ; " + Acz_txt);
    //qDebug() << temp_txt;
    return "";
}

void MainWindow::on_bt_start_server_clicked()
{

    if(SOCKET_STATE == 0)   //connect
    {
        heure.start();
        int port = ui->txt_port->text().toInt();
        if(port > 0 && port < 65535)
        {
            initSocket(port);
            ui->bt_start_server->setText(_TXT_STOP_SERVER_);
            SOCKET_STATE = 1;
        }
        else
        {

        }
    }
    else
    {
        this->udpSocket->close();
        ui->bt_start_server->setText(_TXT_START_SERVER_);
        SOCKET_STATE = 0;
    }


}



void MainWindow::graph_data_update(QCustomPlot *customPlot,int16_t temp,int16_t humi,int16_t temp2)
{

    static double lastPointKey = 0;
    static  double key = QDateTime::currentDateTime().toMSecsSinceEpoch()/1000.0;
    key++;

    //if (key-lastPointKey > 0.01) // at most add point every 10 ms
    //{
        //double humi2 = qSin(key);
        //double temp2 = qCos(key);
        customPlot->graph(_LINE_TEMP_)->addData(key,humi);
        customPlot->graph(_LINE_HUMI_)->addData(key,temp);
        customPlot->graph(_LINE_TEMP2_)->addData(key,temp2);

        // set data of dots:
        customPlot->graph(_DOT_TEMP_)->clearData();
        customPlot->graph(_DOT_TEMP_)->addData(key,humi);
        customPlot->graph(_DOT_HUMI_)->clearData();
        customPlot->graph(_DOT_HUMI_)->addData(key,temp);
        customPlot->graph(_DOT_TEMP2_)->clearData();
        customPlot->graph(_DOT_TEMP2_)->addData(key,temp2);

        // remove data of lines that's outside visible range:
        customPlot->graph(_LINE_TEMP_)->removeDataBefore(key-100);
        customPlot->graph(_LINE_HUMI_)->removeDataBefore(key-100);
        customPlot->graph(_LINE_TEMP2_)->removeDataBefore(key-100);

        // rescale value (vertical) axis to fit the current data:
        customPlot->graph(_LINE_TEMP_)->rescaleValueAxis(true);
        customPlot->graph(_LINE_HUMI_)->rescaleValueAxis(true);
        customPlot->graph(_LINE_TEMP2_)->rescaleValueAxis(true);
        lastPointKey = key;
    //}
    customPlot->xAxis->setRange(key+0.25,80, Qt::AlignRight);
    customPlot->replot();

    static double lastFpsKey;
    static int frameCount;
    ++frameCount;
    if (key-lastFpsKey > 2) // average fps over 2 seconds
    {

      lastFpsKey = key;
      frameCount = 0;
    }

}

void MainWindow::setupRealtimeDataDemo(QCustomPlot *customPlot)
{

    customPlot->addGraph(); // blue line
    customPlot->graph(_LINE_TEMP_)->setPen(QPen(Qt::blue));
    customPlot->graph(_LINE_TEMP_)->setAntialiasedFill(false);
    customPlot->addGraph(); // red line
    customPlot->graph(_LINE_HUMI_)->setPen(QPen(Qt::red));
    customPlot->graph(0)->setChannelFillGraph(customPlot->graph(1));
    customPlot->addGraph(); // red line
    customPlot->graph(_LINE_TEMP2_)->setPen(QPen(Qt::gray));
    customPlot->graph(1)->setChannelFillGraph(customPlot->graph(2));

    customPlot->addGraph(); // blue dot
    customPlot->graph(_DOT_TEMP_)->setPen(QPen(Qt::blue));
    customPlot->graph(_DOT_TEMP_)->setLineStyle(QCPGraph::lsNone);
    customPlot->graph(_DOT_TEMP_)->setScatterStyle(QCPScatterStyle::ssDisc);
    customPlot->addGraph(); // red dot
    customPlot->graph(_DOT_HUMI_)->setPen(QPen(Qt::red));
    customPlot->graph(_DOT_HUMI_)->setLineStyle(QCPGraph::lsNone);
    customPlot->graph(_DOT_HUMI_)->setScatterStyle(QCPScatterStyle::ssDisc);
    customPlot->addGraph(); // red dot
    customPlot->graph(_DOT_TEMP2_)->setPen(QPen(Qt::gray));
    customPlot->graph(_DOT_TEMP2_)->setLineStyle(QCPGraph::lsNone);
    customPlot->graph(_DOT_TEMP2_)->setScatterStyle(QCPScatterStyle::ssDisc);

    customPlot->xAxis->setTickLabelType(QCPAxis::ltDateTime);
    customPlot->xAxis->setDateTimeFormat("hh:mm:ss");
    customPlot->xAxis->setDateTimeSpec(Qt::UTC);


    customPlot->xAxis->setAutoTickStep(false);
    customPlot->xAxis->setTickStep(2);

    customPlot->axisRect()->setupFullAxesBox();

    // make left and bottom axes transfer their ranges to right and top axes:
    connect(customPlot->xAxis, SIGNAL(rangeChanged(QCPRange)), customPlot->xAxis2, SLOT(setRange(QCPRange)));
    connect(customPlot->yAxis, SIGNAL(rangeChanged(QCPRange)), customPlot->yAxis2, SLOT(setRange(QCPRange)));

}

void MainWindow::on_bt_save_clicked()
{
    QString fileName;
        QFileDialog::Options options;
        int frameStyle = QFrame::Sunken | QFrame::Panel;
        QLabel *criticalLabel = new QLabel;
            criticalLabel->setFrameStyle(frameStyle);
            QLabel *saveFileNameLabel = new QLabel("resultats.csv");
            QString selectedFilter;
            fileName = QFileDialog::getSaveFileName(this,
                                        tr("QFileDialog::getSaveFileName()"),
                                        saveFileNameLabel->text(),
                                        tr("All Files (*);;CSV Files (*.csv)"),
                                        &selectedFilter,
                                        options);
            if (!fileName.isEmpty())
                saveFileNameLabel->setText(fileName);
            QFile file(fileName);
            if (!file.open(QFile::WriteOnly | QFile::Text)) {
                    QMessageBox::warning(this, tr("Application"),
                                         tr("Cannot write file %1:\n%2.")
                                         .arg(fileName)
                                         .arg(file.errorString()));
                    return;
                }
            QTextStream outF(&file);
            outF << outStream->readAll();
}
