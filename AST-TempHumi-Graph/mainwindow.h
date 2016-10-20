#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QtGui/QMainWindow>
#include <QtGui/QLabel>

#include "qcustomplot.h"

class QUdpSocket;

#define _TXT_START_SERVER_ "Start"
#define _TXT_STOP_SERVER_ "Stop"


#define _LINE_TEMP_ 0
#define _LINE_HUMI_ 1
#define _LINE_TEMP2_ 2

#define _DOT_TEMP_ 3
#define _DOT_HUMI_ 4
#define _DOT_TEMP2_ 5

typedef union {
    int16_t f1;
    int8_t fdata[12];
}st_float;


namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT
private slots:
    void readPendingDatagrams();
    void on_bt_start_server_clicked();
    void on_bt_save_clicked();

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private:
    Ui::MainWindow *ui;
    int SOCKET_STATE;
    QUdpSocket *udpSocket;
    QTextStream *outStream;
    QFile *outputFile;
    QLabel *openFileNameLabel;
    bool startf;
    QTime heure;
    QString *sauvtext;

    void initSocket(int port);
    QString process_data(QByteArray data);

    void graph_data_update(QCustomPlot *customPlot,int16_t temp,int16_t humi, int16_t temp2);
    void setupRealtimeDataDemo(QCustomPlot *customPlot);
};

#endif // MAINWINDOW_H
