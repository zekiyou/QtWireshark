#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    showNetworkCard();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::showNetworkCard()
{
    int n = pcap_findalldevs(&all_device, errbuf);

    if (n==-1) {
        ui->comboBox->addItem("error: " + QString(errbuf));
    } else {
        ui->comboBox->clear();
        ui->comboBox->addItem("pls choose card");

        for (auto device = all_device; device!=nullptr; device = device->next) {
            QString device_name = device->name;
            device_name.replace("\\Device\\", "");
            QString device_des = device->description;
            QString item = device_name + device_des;
            ui->comboBox->addItem(item);
        }
    }

}
