#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ptrAddRoom= new AddRoom();
    ptrRegistreClient = new RegistreClient();
    ptrFindRoom = new FindRoom();
    ptrFindClient = new FindClient();

}

MainWindow::~MainWindow()
{
    delete ptrAddRoom;
    delete ptrRegistreClient;
    delete ptrFindRoom;
    delete ptrFindClient;

    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
    ptrAddRoom->show();
}

void MainWindow::on_pushButton_2_clicked()
{
    ptrRegistreClient->show();
}

void MainWindow::on_pushButton_3_clicked()
{
    ptrFindRoom->show();
}

void MainWindow::on_pushButton_4_clicked()
{
    ptrFindClient->show();
}
