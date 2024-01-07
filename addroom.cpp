#include "addroom.h"
#include "ui_addroom.h"
#include <QDialog>
#include <QDebug>

AddRoom::AddRoom(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AddRoom)
{
    ui->setupUi(this);
}

AddRoom::~AddRoom()
{
    delete ui;
}

void AddRoom::on_btnSave_clicked()
{
    QString RoomName = ui->txtRoomName->text();
    QString RoomDescription = ui->txtDescription->toPlainText();
    QString Amount = ui->txtAmount->text();
    qDebug() << "Room Name :"<< RoomName <<"Room Description :"<< RoomDescription << "Amount :"<< Amount;
    QSqlDatabase database = QSqlDatabase ::addDatabase("QSQLITE");
    database.setDatabaseName("C:/Users/barhami mohamed/Documents/projet/database/MyHotelManager.db");
    if(QFile::exists("C:/Users/barhami mohamed/Documents/projet/database/MyHotelManager.db")){
        qDebug() <<"Database file exists";
    }

    else{
     qDebug() << "database file doesn't exist";
     return;
    }
    if(!database.open()){
        qDebug() <<"Error: Unable to open Database";
        return;
    }
    else{
        qDebug() << "Database open successfully";
    }
    QSqlQuery query;

    query.prepare("insert into Room (RoomName ,RoomDescription , Amount) values ('"+ RoomName + "','" + RoomName +"','"+ Amount + "')");
    query.exec();
    qDebug() <<"last erroe"<< query.lastError().text();
    database.close();

}
