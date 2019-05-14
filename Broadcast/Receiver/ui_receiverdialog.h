/********************************************************************************
** Form generated from reading UI file 'receiverdialog.ui'
**
** Created by: Qt User Interface Compiler version 5.4.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_RECEIVERDIALOG_H
#define UI_RECEIVERDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_ReceiverDialog
{
public:
    QVBoxLayout *verticalLayout;
    QListWidget *listWidget;
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    QLineEdit *lineEdit;
    QHBoxLayout *horizontalLayout_2;
    QSpacerItem *horizontalSpacer;
    QPushButton *pushButton;
    QSpacerItem *horizontalSpacer_2;

    void setupUi(QDialog *ReceiverDialog)
    {
        if (ReceiverDialog->objectName().isEmpty())
            ReceiverDialog->setObjectName(QStringLiteral("ReceiverDialog"));
        ReceiverDialog->resize(326, 375);
        QFont font;
        font.setPointSize(22);
        ReceiverDialog->setFont(font);
        verticalLayout = new QVBoxLayout(ReceiverDialog);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        listWidget = new QListWidget(ReceiverDialog);
        listWidget->setObjectName(QStringLiteral("listWidget"));

        verticalLayout->addWidget(listWidget);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        label = new QLabel(ReceiverDialog);
        label->setObjectName(QStringLiteral("label"));

        horizontalLayout->addWidget(label);

        lineEdit = new QLineEdit(ReceiverDialog);
        lineEdit->setObjectName(QStringLiteral("lineEdit"));

        horizontalLayout->addWidget(lineEdit);


        verticalLayout->addLayout(horizontalLayout);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer);

        pushButton = new QPushButton(ReceiverDialog);
        pushButton->setObjectName(QStringLiteral("pushButton"));

        horizontalLayout_2->addWidget(pushButton);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_2);


        verticalLayout->addLayout(horizontalLayout_2);


        retranslateUi(ReceiverDialog);

        QMetaObject::connectSlotsByName(ReceiverDialog);
    } // setupUi

    void retranslateUi(QDialog *ReceiverDialog)
    {
        ReceiverDialog->setWindowTitle(QApplication::translate("ReceiverDialog", "\345\271\277\346\222\255\346\216\245\346\224\266\347\253\257", 0));
        label->setText(QApplication::translate("ReceiverDialog", "\346\216\245\346\224\266\345\271\277\346\222\255\347\253\257\345\217\243:", 0));
        lineEdit->setText(QApplication::translate("ReceiverDialog", "8888", 0));
        pushButton->setText(QApplication::translate("ReceiverDialog", "\345\274\200\345\247\213\346\216\245\346\224\266", 0));
    } // retranslateUi

};

namespace Ui {
    class ReceiverDialog: public Ui_ReceiverDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_RECEIVERDIALOG_H
