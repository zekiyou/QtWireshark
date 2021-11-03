#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <sys/socket.h>
#include "pcap.h"
#include "Packet32.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    void showNetworkCard();

private:
    Ui::MainWindow *ui;
    pcap_if_t* all_device;
    pcap_if_t* m_device;
    pcap_t* pointer;
    char errbuf[PCAP_ERRBUF_SIZE];
};

#endif // MAINWINDOW_H
