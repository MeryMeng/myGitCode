/********************************************************************************
** Form generated from reading UI file 'studentdialog.ui'
**
** Created by: Qt User Interface Compiler version 5.4.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_STUDENTDIALOG_H
#define UI_STUDENTDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTableView>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_StudentDialog
{
public:
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QComboBox *valuecomboBox;
    QComboBox *condcomboBox;
    QPushButton *sortButton;
    QTableView *tableView;
    QGridLayout *gridLayout;
    QLabel *label;
    QLineEdit *idEdit;
    QLabel *label_2;
    QLineEdit *nameEdit;
    QLabel *label_3;
    QLineEdit *scoreEdit;
    QHBoxLayout *horizontalLayout_2;
    QPushButton *insertButton;
    QPushButton *deleteButton;
    QPushButton *updateButton;

    void setupUi(QDialog *StudentDialog)
    {
        if (StudentDialog->objectName().isEmpty())
            StudentDialog->setObjectName(QStringLiteral("StudentDialog"));
        StudentDialog->resize(436, 631);
        verticalLayout = new QVBoxLayout(StudentDialog);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        valuecomboBox = new QComboBox(StudentDialog);
        valuecomboBox->setObjectName(QStringLiteral("valuecomboBox"));

        horizontalLayout->addWidget(valuecomboBox);

        condcomboBox = new QComboBox(StudentDialog);
        condcomboBox->setObjectName(QStringLiteral("condcomboBox"));

        horizontalLayout->addWidget(condcomboBox);

        sortButton = new QPushButton(StudentDialog);
        sortButton->setObjectName(QStringLiteral("sortButton"));

        horizontalLayout->addWidget(sortButton);


        verticalLayout->addLayout(horizontalLayout);

        tableView = new QTableView(StudentDialog);
        tableView->setObjectName(QStringLiteral("tableView"));

        verticalLayout->addWidget(tableView);

        gridLayout = new QGridLayout();
        gridLayout->setSpacing(6);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        label = new QLabel(StudentDialog);
        label->setObjectName(QStringLiteral("label"));

        gridLayout->addWidget(label, 0, 0, 1, 1);

        idEdit = new QLineEdit(StudentDialog);
        idEdit->setObjectName(QStringLiteral("idEdit"));

        gridLayout->addWidget(idEdit, 0, 1, 1, 1);

        label_2 = new QLabel(StudentDialog);
        label_2->setObjectName(QStringLiteral("label_2"));

        gridLayout->addWidget(label_2, 1, 0, 1, 1);

        nameEdit = new QLineEdit(StudentDialog);
        nameEdit->setObjectName(QStringLiteral("nameEdit"));

        gridLayout->addWidget(nameEdit, 1, 1, 1, 1);

        label_3 = new QLabel(StudentDialog);
        label_3->setObjectName(QStringLiteral("label_3"));

        gridLayout->addWidget(label_3, 2, 0, 1, 1);

        scoreEdit = new QLineEdit(StudentDialog);
        scoreEdit->setObjectName(QStringLiteral("scoreEdit"));

        gridLayout->addWidget(scoreEdit, 2, 1, 1, 1);


        verticalLayout->addLayout(gridLayout);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        insertButton = new QPushButton(StudentDialog);
        insertButton->setObjectName(QStringLiteral("insertButton"));

        horizontalLayout_2->addWidget(insertButton);

        deleteButton = new QPushButton(StudentDialog);
        deleteButton->setObjectName(QStringLiteral("deleteButton"));

        horizontalLayout_2->addWidget(deleteButton);

        updateButton = new QPushButton(StudentDialog);
        updateButton->setObjectName(QStringLiteral("updateButton"));

        horizontalLayout_2->addWidget(updateButton);


        verticalLayout->addLayout(horizontalLayout_2);


        retranslateUi(StudentDialog);

        QMetaObject::connectSlotsByName(StudentDialog);
    } // setupUi

    void retranslateUi(QDialog *StudentDialog)
    {
        StudentDialog->setWindowTitle(QApplication::translate("StudentDialog", "StudentManage", 0));
        valuecomboBox->clear();
        valuecomboBox->insertItems(0, QStringList()
         << QApplication::translate("StudentDialog", "ID", 0)
         << QApplication::translate("StudentDialog", "Name", 0)
         << QApplication::translate("StudentDialog", "Score", 0)
        );
        condcomboBox->clear();
        condcomboBox->insertItems(0, QStringList()
         << QApplication::translate("StudentDialog", "ASC", 0)
         << QApplication::translate("StudentDialog", "DESC", 0)
        );
        sortButton->setText(QApplication::translate("StudentDialog", "paixu", 0));
        label->setText(QApplication::translate("StudentDialog", "No:", 0));
        idEdit->setText(QString());
        label_2->setText(QApplication::translate("StudentDialog", "Name:", 0));
        nameEdit->setText(QString());
        label_3->setText(QApplication::translate("StudentDialog", "Score:", 0));
        insertButton->setText(QApplication::translate("StudentDialog", "Insert", 0));
        deleteButton->setText(QApplication::translate("StudentDialog", "Delete", 0));
        updateButton->setText(QApplication::translate("StudentDialog", "Update", 0));
    } // retranslateUi

};

namespace Ui {
    class StudentDialog: public Ui_StudentDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_STUDENTDIALOG_H
