#ifndef STUDENTDIALOG_H
#define STUDENTDIALOG_H

#include <QDialog>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlQueryModel>
#include <QSqlError>
#include <QDebug>

namespace Ui {
class StudentDialog;
}

class StudentDialog : public QDialog
{
    Q_OBJECT

public:
    explicit StudentDialog(QWidget *parent = 0);
    ~StudentDialog();
private:
    void createDB(void);
    void createTable(void);
    void queryTable(void);

private slots:
    void on_insertButton_clicked();//insert

    void on_deleteButton_clicked();//delete

    void on_updateButton_clicked();//update

    void on_sortButton_clicked();//sort

private:
    Ui::StudentDialog *ui;
    QSqlDatabase db;
    QSqlQueryModel model;

};

#endif // STUDENTDIALOG_H
