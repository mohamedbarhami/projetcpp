#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "addroom.h"
#include "registreclient.h"
#include "findroom.h"
#include "findclient.h"
namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_4_clicked();

private:
    Ui::MainWindow *ui;
    AddRoom *ptrAddRoom;
    RegistreClient *ptrRegistreClient;
    FindRoom *ptrFindRoom;
    FindClient *ptrFindClient;
};

#endif // MAINWINDOW_H
