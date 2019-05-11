#include "studentdialog.h"
#include "ui_studentdialog.h"

StudentDialog::StudentDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::StudentDialog)
{
    ui->setupUi(this);
    createDB();
    createTable();
    queryTable();

}
StudentDialog::~StudentDialog()
{
    delete ui;
}
//insert
void StudentDialog::on_insertButton_clicked()
{
    QSqlQuery query;
    int id=ui->idEdit->text().toInt();
    QString name=ui->nameEdit->text();
    double score=ui->scoreEdit->text().toDouble();
    QString str=QString(
                "insert into student values(%1,'%2',%3)").arg(id).arg(name).arg(score);
    if(query.exec(str)==false)
    {
        qDebug() << str;
    }
    else
    {
        qDebug() << "Insert Success ...";
        queryTable();
    }
}
//delete
void StudentDialog::on_deleteButton_clicked()
{
    QSqlQuery query;
    int id=ui->idEdit->text().toInt();
    QString str=QString("delete from student where id=%1").arg(id);
    if(query.exec(str)==false)
    {
        qDebug() << str;
    }
    else
    {
        qDebug() << "Delete Success ...";
        queryTable();
    }
}
//update
void StudentDialog::on_updateButton_clicked()
{
    QSqlQuery query;
    int id=ui->idEdit->text().toInt();
    double score=ui->scoreEdit->text().toDouble();
    QString str=QString("update student set score=%1 where id=%2"
                        ).arg(score).arg(id);
    if(query.exec(str)==false)
    {
        qDebug() << str;
    }
    else
    {
        qDebug() << "Update Success ...";
        queryTable();
    }
}
//paixu
void StudentDialog::on_sortButton_clicked()
{
    QString value=ui->valuecomboBox->currentText();
    QString condition;
    if(ui->condcomboBox->currentIndex()==0){
        condition="ASC";
    }
    else{
        condition="DESC";
    }
    QString str=QString("select * from student order by %1 %2").arg(value).arg(condition);
    model.setQuery(str);
    ui->tableView->setModel(&model);
    //while (1) {}

}
void StudentDialog::createDB(void){
    db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("student.db");
    if(db.open()==false){
        qDebug() << db.lastError().text();
    }
    else
    {
        qDebug() << "Create Database Success...";
    }
}
void StudentDialog::createTable(void){
    QSqlQuery query;
    QString str=QString(
                "create table student("
                "id int primary key not null,"
                "name text not null,"
                "score real not null)");
    if(query.exec(str)==false){
        qDebug() << str;
    }
    else {
        qDebug() << "Create table success....";
    }
}
void StudentDialog::queryTable(void){
    QString str=QString("select *from student");
    model.setQuery(str);
    ui->tableView->setModel(&model);
}

