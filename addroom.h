#ifndef ADDROOM_H
#define ADDROOM_H

#include <QDialog>
#include "databaseheader.h"

namespace Ui {
class AddRoom;
}

class AddRoom : public QDialog
{
    Q_OBJECT

public:
    explicit AddRoom(QWidget *parent = nullptr);
    ~AddRoom();

private slots:
    void on_btnSave_clicked();

private:
    Ui::AddRoom *ui;
};

#endif // ADDROOM_H
