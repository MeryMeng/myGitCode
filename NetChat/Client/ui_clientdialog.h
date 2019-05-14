/********************************************************************************
** Form generated from reading UI file 'clientdialog.ui'
**
** Created by: Qt User Interface Compiler version 5.6.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CLIENTDIALOG_H
#define UI_CLIENTDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_ClientDialog
{
public:
    QVBoxLayout *verticalLayout;
    QListWidget *listWidget;
    QHBoxLayout *horizontalLayout;
    QLineEdit *messageEdit;
    QPushButton *sendButton;
    QGridLayout *gridLayout;
    QLabel *label;
    QLineEdit *serverIpEdit;
    QLabel *label_2;
    QLineEdit *serverPortEdit;
    QLabel *label_3;
    QLineEdit *usernameEdit;
    QPushButton *connectButton;

    void setupUi(QDialog *ClientDialog)
    {
        if (ClientDialog->objectName().isEmpty())
            ClientDialog->setObjectName(QStringLiteral("ClientDialog"));
        ClientDialog->resize(336, 502);
        QFont font;
        font.setPointSize(20);
        ClientDialog->setFont(font);
        verticalLayout = new QVBoxLayout(ClientDialog);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        listWidget = new QListWidget(ClientDialog);
        listWidget->setObjectName(QStringLiteral("listWidget"));

        verticalLayout->addWidget(listWidget);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        messageEdit = new QLineEdit(ClientDialog);
        messageEdit->setObjectName(QStringLiteral("messageEdit"));

        horizontalLayout->addWidget(messageEdit);

        sendButton = new QPushButton(ClientDialog);
        sendButton->setObjectName(QStringLiteral("sendButton"));
        sendButton->setEnabled(false);

        horizontalLayout->addWidget(sendButton);


        verticalLayout->addLayout(horizontalLayout);

        gridLayout = new QGridLayout();
        gridLayout->setSpacing(6);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        label = new QLabel(ClientDialog);
        label->setObjectName(QStringLiteral("label"));

        gridLayout->addWidget(label, 0, 0, 1, 1);

        serverIpEdit = new QLineEdit(ClientDialog);
        serverIpEdit->setObjectName(QStringLiteral("serverIpEdit"));

        gridLayout->addWidget(serverIpEdit, 0, 1, 1, 1);

        label_2 = new QLabel(ClientDialog);
        label_2->setObjectName(QStringLiteral("label_2"));

        gridLayout->addWidget(label_2, 1, 0, 1, 1);

        serverPortEdit = new QLineEdit(ClientDialog);
        serverPortEdit->setObjectName(QStringLiteral("serverPortEdit"));

        gridLayout->addWidget(serverPortEdit, 1, 1, 1, 1);

        label_3 = new QLabel(ClientDialog);
        label_3->setObjectName(QStringLiteral("label_3"));

        gridLayout->addWidget(label_3, 2, 0, 1, 1);

        usernameEdit = new QLineEdit(ClientDialog);
        usernameEdit->setObjectName(QStringLiteral("usernameEdit"));

        gridLayout->addWidget(usernameEdit, 2, 1, 1, 1);


        verticalLayout->addLayout(gridLayout);

        connectButton = new QPushButton(ClientDialog);
        connectButton->setObjectName(QStringLiteral("connectButton"));

        verticalLayout->addWidget(connectButton);


        retranslateUi(ClientDialog);

        QMetaObject::connectSlotsByName(ClientDialog);
    } // setupUi

    void retranslateUi(QDialog *ClientDialog)
    {
        ClientDialog->setWindowTitle(QApplication::translate("ClientDialog", "\350\201\212\345\244\251\345\256\244\345\256\242\346\210\267\347\253\257", 0));
        sendButton->setText(QApplication::translate("ClientDialog", "\345\217\221\351\200\201", 0));
        label->setText(QApplication::translate("ClientDialog", "\346\234\215\345\212\241\345\231\250\345\234\260\345\235\200:", 0));
        serverIpEdit->setText(QApplication::translate("ClientDialog", "172.40.0.137", 0));
        label_2->setText(QApplication::translate("ClientDialog", "\346\234\215\345\212\241\345\231\250\347\253\257\345\217\243:", 0));
        serverPortEdit->setText(QApplication::translate("ClientDialog", "8080", 0));
        label_3->setText(QApplication::translate("ClientDialog", "\350\201\212\345\244\251\345\256\244\346\230\265\347\247\260:", 0));
        usernameEdit->setText(QApplication::translate("ClientDialog", "Jerry", 0));
        connectButton->setText(QApplication::translate("ClientDialog", "\350\277\236\346\216\245\346\234\215\345\212\241\345\231\250", 0));
    } // retranslateUi

};

namespace Ui {
    class ClientDialog: public Ui_ClientDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CLIENTDIALOG_H
