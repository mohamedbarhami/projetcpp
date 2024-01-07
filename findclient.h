#ifndef FINDCLIENT_H
#define FINDCLIENT_H

#include <QDialog>
#include "databaseheader.h"
#include <QSqlQueryModel>
namespace Ui {
class FindClient;
}

class FindClient : public QDialog
{
    Q_OBJECT

public:
    explicit FindClient(QWidget *parent = nullptr);
    ~FindClient();

private slots:
    void on_btnFind_clicked();

private:
    Ui::FindClient *ui;
    QSqlQueryModel *model;
};

#endif // FINDCLIENT_H
