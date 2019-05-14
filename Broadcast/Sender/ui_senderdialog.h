/********************************************************************************
** Form generated from reading UI file 'senderdialog.ui'
**
** Created by: Qt User Interface Compiler version 5.4.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SENDERDIALOG_H
#define UI_SENDERDIALOG_H

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
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_SenderDialog
{
public:
    QVBoxLayout *verticalLayout;
    QSpacerItem *verticalSpacer;
    QGridLayout *gridLayout;
    QLabel *label;
    QLineEdit *messageEdit;
    QLabel *label_2;
    QLineEdit *portEdit;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer;
    QPushButton *pushButton;
    QSpacerItem *horizontalSpacer_2;
    QSpacerItem *verticalSpacer_2;

    void setupUi(QDialog *SenderDialog)
    {
        if (SenderDialog->objectName().isEmpty())
            SenderDialog->setObjectName(QStringLiteral("SenderDialog"));
        SenderDialog->resize(345, 235);
        QFont font;
        font.setPointSize(20);
        SenderDialog->setFont(font);
        verticalLayout = new QVBoxLayout(SenderDialog);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalSpacer = new QSpacerItem(20, 25, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer);

        gridLayout = new QGridLayout();
        gridLayout->setSpacing(6);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        label = new QLabel(SenderDialog);
        label->setObjectName(QStringLiteral("label"));

        gridLayout->addWidget(label, 0, 0, 1, 1);

        messageEdit = new QLineEdit(SenderDialog);
        messageEdit->setObjectName(QStringLiteral("messageEdit"));

        gridLayout->addWidget(messageEdit, 0, 1, 1, 1);

        label_2 = new QLabel(SenderDialog);
        label_2->setObjectName(QStringLiteral("label_2"));

        gridLayout->addWidget(label_2, 1, 0, 1, 1);

        portEdit = new QLineEdit(SenderDialog);
        portEdit->setObjectName(QStringLiteral("portEdit"));

        gridLayout->addWidget(portEdit, 1, 1, 1, 1);


        verticalLayout->addLayout(gridLayout);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        pushButton = new QPushButton(SenderDialog);
        pushButton->setObjectName(QStringLiteral("pushButton"));

        horizontalLayout->addWidget(pushButton);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_2);


        verticalLayout->addLayout(horizontalLayout);

        verticalSpacer_2 = new QSpacerItem(20, 25, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer_2);


        retranslateUi(SenderDialog);

        QMetaObject::connectSlotsByName(SenderDialog);
    } // setupUi

    void retranslateUi(QDialog *SenderDialog)
    {
        SenderDialog->setWindowTitle(QApplication::translate("SenderDialog", "\345\271\277\346\222\255\345\217\221\351\200\201\347\253\257", 0));
        label->setText(QApplication::translate("SenderDialog", "\345\271\277\346\222\255\346\266\210\346\201\257:", 0));
        messageEdit->setText(QApplication::translate("SenderDialog", "\344\273\212\345\244\251\346\230\257\346\230\237\346\234\237\344\270\200", 0));
        label_2->setText(QApplication::translate("SenderDialog", "\345\271\277\346\222\255\347\253\257\345\217\243:", 0));
        portEdit->setText(QApplication::translate("SenderDialog", "8888", 0));
        pushButton->setText(QApplication::translate("SenderDialog", "\345\274\200\345\247\213\345\271\277\346\222\255", 0));
    } // retranslateUi

};

namespace Ui {
    class SenderDialog: public Ui_SenderDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SENDERDIALOG_H
