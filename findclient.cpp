#include "findclient.h"
#include "ui_findclient.h"
#include <QSqlQueryModel>

FindClient::FindClient(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::FindClient)
{
    ui->setupUi(this);
}

FindClient::~FindClient()
{
    delete ui;

}

void FindClient::on_btnFind_clicked()
{
    QString ClientName = ui->txtClientName->text();
      qDebug() << "Client Name :" << ClientName;
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
       query.prepare("select * from Client Name where FirstName like '%"+ ClientName + "%'");
       query.exec();
       qDebug() << "last query : "<<query.lastQuery();
     qDebug() << "last Error : " << query.lastError().text();
       if(model==NULL){
           model = new QSqlQueryModel();
       }

       model->setQuery(std::move(query));
      ui->tableView->setModel(model);

       database.close();
}
