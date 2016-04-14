/********************************************************************************
** Form generated from reading UI file 'mainWin.ui'
**
** Created by: Qt User Interface Compiler version 5.5.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWIN_H
#define UI_MAINWIN_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPlainTextEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_qttestClass
{
public:
    QWidget *centralWidget;
    QWidget *verticalLayoutWidget;
    QVBoxLayout *verticalLayout_5;
    QPlainTextEdit *plainTextEdit;
    QPushButton *pushButton_3;
    QPushButton *pushButton_2;
    QPushButton *train;
    QPushButton *selectpic;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *qttestClass)
    {
        if (qttestClass->objectName().isEmpty())
            qttestClass->setObjectName(QStringLiteral("qttestClass"));
        qttestClass->resize(193, 392);
        centralWidget = new QWidget(qttestClass);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        verticalLayoutWidget = new QWidget(centralWidget);
        verticalLayoutWidget->setObjectName(QStringLiteral("verticalLayoutWidget"));
        verticalLayoutWidget->setGeometry(QRect(10, 0, 171, 331));
        verticalLayout_5 = new QVBoxLayout(verticalLayoutWidget);
        verticalLayout_5->setSpacing(6);
        verticalLayout_5->setContentsMargins(11, 11, 11, 11);
        verticalLayout_5->setObjectName(QStringLiteral("verticalLayout_5"));
        verticalLayout_5->setContentsMargins(0, 0, 0, 0);
        plainTextEdit = new QPlainTextEdit(verticalLayoutWidget);
        plainTextEdit->setObjectName(QStringLiteral("plainTextEdit"));

        verticalLayout_5->addWidget(plainTextEdit);

        pushButton_3 = new QPushButton(verticalLayoutWidget);
        pushButton_3->setObjectName(QStringLiteral("pushButton_3"));

        verticalLayout_5->addWidget(pushButton_3);

        pushButton_2 = new QPushButton(verticalLayoutWidget);
        pushButton_2->setObjectName(QStringLiteral("pushButton_2"));

        verticalLayout_5->addWidget(pushButton_2);

        train = new QPushButton(verticalLayoutWidget);
        train->setObjectName(QStringLiteral("train"));

        verticalLayout_5->addWidget(train);

        selectpic = new QPushButton(verticalLayoutWidget);
        selectpic->setObjectName(QStringLiteral("selectpic"));

        verticalLayout_5->addWidget(selectpic);

        qttestClass->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(qttestClass);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 193, 23));
        qttestClass->setMenuBar(menuBar);
        mainToolBar = new QToolBar(qttestClass);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        qttestClass->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(qttestClass);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        qttestClass->setStatusBar(statusBar);

        retranslateUi(qttestClass);
        QObject::connect(pushButton_3, SIGNAL(clicked()), qttestClass, SLOT(OpenImageClicked()));
        QObject::connect(pushButton_2, SIGNAL(clicked()), qttestClass, SLOT(pictureCapture()));

        QMetaObject::connectSlotsByName(qttestClass);
    } // setupUi

    void retranslateUi(QMainWindow *qttestClass)
    {
        qttestClass->setWindowTitle(QApplication::translate("qttestClass", "qttest", 0));
        pushButton_3->setText(QApplication::translate("qttestClass", "\345\212\240\350\275\275\350\247\206\351\242\221", 0));
        pushButton_2->setText(QApplication::translate("qttestClass", "\346\210\252\345\233\276", 0));
        train->setText(QApplication::translate("qttestClass", "\350\256\255\347\273\203", 0));
        selectpic->setText(QApplication::translate("qttestClass", "\347\255\233\351\200\211\346\240\267\346\234\254", 0));
    } // retranslateUi

};

namespace Ui {
    class qttestClass: public Ui_qttestClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWIN_H
