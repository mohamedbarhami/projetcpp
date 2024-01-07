#include "findroom.h"
#include "ui_findroom.h"
#include <QSqlQueryModel>

FindRoom::FindRoom(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::FindRoom),
   model(new QSqlQueryModel)
{
    ui->setupUi(this);
}

FindRoom::~FindRoom()
{
    delete ui;
    delete model;
}


void FindRoom::on_btnFindRoom_clicked()
{
    QString RoomName = ui->txtRoomName->text();
      qDebug() << "Room Name :" << RoomName;
    QSqlDatabase database = QSqlDatabase ::addDatabase("QSQLITE");
    database.setDatabaseName("C:/Users/barhami mohamed/Documents/projet/database/MyHotelManager.db");
    if(QFile::exists("C:/Users/barhami mohamed/Documents/projet/database/MyHotelManager.db")){
        qDebug() <<"Database file exists";
    } else{
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
       query.prepare("select * from Room Name where RoomName like '%"+ RoomName + "%'");
       query.exec();
       qDebug() << "last query : "<<query.lastQuery();
     qDebug() << "last Error : " << query.lastError().text();
       if(model==NULL){
           model = new QSqlQueryModel();
       }

       model->setQuery(std::move(query));
      ui->txtDescription->setModel(model);
       ui->txtDescription->setColumnWidth(0,200);
       ui->txtDescription->setColumnWidth(1,200);
       ui->txtDescription->setColumnWidth(2,200);
       database.close();

}
