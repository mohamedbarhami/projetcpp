#include "registreclient.h"
#include "ui_registreclient.h"
#include <QDebug>
#include <QDialog>
#include <QFile>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlError>
#include <QSqlDatabase>

RegistreClient::RegistreClient(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::RegistreClient)
{
    ui->setupUi(this);
}

RegistreClient::~RegistreClient()
{
    delete ui;
}

void RegistreClient::on_btnSave_clicked()
{

    QString firstName = ui->txtFirstName->text();
     QString middleName = ui->txtMiddleName->text();
     QString lastName = ui->txtLastName->text();
     QString passportNo = ui->txtPasportNo->text();
     QString contactNo = ui->txtContactNo->text();
     QString Address = ui->txtAdresse->text();
     QString RoomName = ui->cmbChooseRoom->currentText();
     qDebug() << "first Name :"<< firstName <<"middleName :"<< middleName << "lastName :"<< lastName << "passportNo :"<< passportNo << "contactNo :"<< contactNo << "Address :"<< Address << "RoomName :"<< RoomName;
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
        QSqlQuery query(database);
        query.prepare("insert into Client (FirstName, MiddleName, LastName, PasportNo, ContactNo, Adresse, RoomName) "
                              "values('" + firstName + "','" + middleName + "','" + lastName + "', '" + passportNo + "','" + contactNo + "','" + Address + "','" + RoomName +"')");
              query.exec();
              query.finish();query.clear();
              qDebug() << "Last error : "<< query.lastQuery();
              qDebug() << "Last error : "<< query.lastError().text();
               database.close();
}



void RegistreClient::on_btnReset_clicked()
{

}

void RegistreClient::on_cmbChooseRoom_activated(const QString &arg1)
{

}
