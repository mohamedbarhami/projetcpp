#ifndef REGISTRECLIENT_H
#define REGISTRECLIENT_H

#include <QDialog>

namespace Ui {
class RegistreClient;
}

class RegistreClient : public QDialog
{
    Q_OBJECT

public:
    explicit RegistreClient(QWidget *parent = nullptr);
    ~RegistreClient();

private slots:
    void on_btnSave_clicked();

    void on_btnReset_clicked();

    void on_cmbChooseRoom_activated(const QString &arg1);

private:
    Ui::RegistreClient *ui;
};

#endif // REGISTRECLIENT_H
