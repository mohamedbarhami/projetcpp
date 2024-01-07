#ifndef FINDROOM_H
#define FINDROOM_H

#include <QDialog>
#include <QSqlQueryModel>
#include "databaseheader.h"
#include "ui_findroom.h"



namespace Ui {
class FindRoom;


}

class FindRoom : public QDialog
{
    Q_OBJECT

public:
    explicit FindRoom(QWidget *parent = nullptr);
    ~FindRoom();


private slots:
    void on_btnFindRoom_clicked();

private:
    Ui::FindRoom *ui;
     QSqlQueryModel *model;
};


#endif // FINDROOM_H
