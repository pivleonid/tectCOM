/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.9.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QGridLayout *gridLayout_7;
    QGridLayout *gridLayout_3;
    QGridLayout *gridLayout;
    QLabel *label_4;
    QSpacerItem *horizontalSpacer;
    QGridLayout *gridLayout_2;
    QPushButton *connectBtn;
    QLabel *label;
    QComboBox *serialPortInfoBox;
    QLabel *label_2;
    QComboBox *boudrateBox;
    QPushButton *disconnectBtn;
    QLabel *label_3;
    QSpacerItem *horizontalSpacer_2;
    QGridLayout *gridLayout_4;
    QPushButton *hightBtn;
    QLineEdit *lineEdit;
    QPushButton *lowBtn;
    QPushButton *ClearBtn;
    QGridLayout *gridLayout_5;
    QLabel *label_5;
    QLineEdit *timerLE;
    QSpacerItem *horizontalSpacer_3;
    QGridLayout *gridLayout_6;
    QPushButton *startBtn;
    QPushButton *stopBtn;
    QSpacerItem *horizontalSpacer_4;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(745, 258);
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(MainWindow->sizePolicy().hasHeightForWidth());
        MainWindow->setSizePolicy(sizePolicy);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        gridLayout_7 = new QGridLayout(centralWidget);
        gridLayout_7->setSpacing(6);
        gridLayout_7->setContentsMargins(11, 11, 11, 11);
        gridLayout_7->setObjectName(QStringLiteral("gridLayout_7"));
        gridLayout_3 = new QGridLayout();
        gridLayout_3->setSpacing(6);
        gridLayout_3->setObjectName(QStringLiteral("gridLayout_3"));
        gridLayout = new QGridLayout();
        gridLayout->setSpacing(6);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        label_4 = new QLabel(centralWidget);
        label_4->setObjectName(QStringLiteral("label_4"));

        gridLayout->addWidget(label_4, 0, 0, 1, 1);

        horizontalSpacer = new QSpacerItem(298, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer, 0, 1, 1, 1);


        gridLayout_3->addLayout(gridLayout, 0, 0, 1, 2);

        gridLayout_2 = new QGridLayout();
        gridLayout_2->setSpacing(6);
        gridLayout_2->setObjectName(QStringLiteral("gridLayout_2"));
        connectBtn = new QPushButton(centralWidget);
        connectBtn->setObjectName(QStringLiteral("connectBtn"));

        gridLayout_2->addWidget(connectBtn, 0, 4, 1, 1);

        label = new QLabel(centralWidget);
        label->setObjectName(QStringLiteral("label"));

        gridLayout_2->addWidget(label, 0, 0, 1, 1);

        serialPortInfoBox = new QComboBox(centralWidget);
        serialPortInfoBox->setObjectName(QStringLiteral("serialPortInfoBox"));

        gridLayout_2->addWidget(serialPortInfoBox, 0, 1, 1, 1);

        label_2 = new QLabel(centralWidget);
        label_2->setObjectName(QStringLiteral("label_2"));

        gridLayout_2->addWidget(label_2, 0, 2, 1, 1);

        boudrateBox = new QComboBox(centralWidget);
        boudrateBox->setObjectName(QStringLiteral("boudrateBox"));

        gridLayout_2->addWidget(boudrateBox, 0, 3, 1, 1);

        disconnectBtn = new QPushButton(centralWidget);
        disconnectBtn->setObjectName(QStringLiteral("disconnectBtn"));

        gridLayout_2->addWidget(disconnectBtn, 0, 5, 1, 1);


        gridLayout_3->addLayout(gridLayout_2, 1, 0, 1, 2);

        label_3 = new QLabel(centralWidget);
        label_3->setObjectName(QStringLiteral("label_3"));

        gridLayout_3->addWidget(label_3, 2, 0, 1, 1);

        horizontalSpacer_2 = new QSpacerItem(319, 17, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_3->addItem(horizontalSpacer_2, 2, 1, 1, 1);


        gridLayout_7->addLayout(gridLayout_3, 0, 0, 1, 1);

        gridLayout_4 = new QGridLayout();
        gridLayout_4->setSpacing(6);
        gridLayout_4->setObjectName(QStringLiteral("gridLayout_4"));
        hightBtn = new QPushButton(centralWidget);
        hightBtn->setObjectName(QStringLiteral("hightBtn"));

        gridLayout_4->addWidget(hightBtn, 0, 1, 1, 1);

        lineEdit = new QLineEdit(centralWidget);
        lineEdit->setObjectName(QStringLiteral("lineEdit"));

        gridLayout_4->addWidget(lineEdit, 0, 2, 1, 1);

        lowBtn = new QPushButton(centralWidget);
        lowBtn->setObjectName(QStringLiteral("lowBtn"));

        gridLayout_4->addWidget(lowBtn, 0, 0, 1, 1);

        ClearBtn = new QPushButton(centralWidget);
        ClearBtn->setObjectName(QStringLiteral("ClearBtn"));

        gridLayout_4->addWidget(ClearBtn, 0, 3, 1, 1);


        gridLayout_7->addLayout(gridLayout_4, 1, 0, 1, 1);

        gridLayout_5 = new QGridLayout();
        gridLayout_5->setSpacing(6);
        gridLayout_5->setObjectName(QStringLiteral("gridLayout_5"));
        label_5 = new QLabel(centralWidget);
        label_5->setObjectName(QStringLiteral("label_5"));

        gridLayout_5->addWidget(label_5, 0, 0, 1, 1);

        timerLE = new QLineEdit(centralWidget);
        timerLE->setObjectName(QStringLiteral("timerLE"));
        sizePolicy.setHeightForWidth(timerLE->sizePolicy().hasHeightForWidth());
        timerLE->setSizePolicy(sizePolicy);

        gridLayout_5->addWidget(timerLE, 0, 1, 1, 1);

        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_5->addItem(horizontalSpacer_3, 0, 2, 1, 1);


        gridLayout_7->addLayout(gridLayout_5, 2, 0, 1, 1);

        gridLayout_6 = new QGridLayout();
        gridLayout_6->setSpacing(6);
        gridLayout_6->setObjectName(QStringLiteral("gridLayout_6"));
        startBtn = new QPushButton(centralWidget);
        startBtn->setObjectName(QStringLiteral("startBtn"));

        gridLayout_6->addWidget(startBtn, 0, 0, 1, 1);

        stopBtn = new QPushButton(centralWidget);
        stopBtn->setObjectName(QStringLiteral("stopBtn"));

        gridLayout_6->addWidget(stopBtn, 0, 1, 1, 1);

        horizontalSpacer_4 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_6->addItem(horizontalSpacer_4, 0, 2, 1, 1);


        gridLayout_7->addLayout(gridLayout_6, 3, 0, 1, 1);

        MainWindow->setCentralWidget(centralWidget);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "\320\242\320\265\321\201\321\202\320\270\321\200\320\276\320\262\320\260\320\275\320\270\320\265 COM \320\277\320\276\321\200\321\202\320\276\320\262 v.1.0.0.0.", Q_NULLPTR));
        label_4->setText(QApplication::translate("MainWindow", "\320\235\320\260\321\201\321\202\321\200\320\276\320\271\320\272\320\260 COM \320\277\320\276\321\200\321\202\320\260:", Q_NULLPTR));
        connectBtn->setText(QApplication::translate("MainWindow", "Connect", Q_NULLPTR));
        label->setText(QApplication::translate("MainWindow", "\320\222\321\213\320\261\321\200\320\260\321\202\321\214 COM \320\277\320\276\321\200\321\202:", Q_NULLPTR));
        label_2->setText(QApplication::translate("MainWindow", "\320\241\320\272\320\276\321\200\320\276\321\201\321\202\321\214 \320\277\320\265\321\200\320\265\320\264\320\260\321\207\320\270:", Q_NULLPTR));
        boudrateBox->clear();
        boudrateBox->insertItems(0, QStringList()
         << QApplication::translate("MainWindow", "1200", Q_NULLPTR)
         << QApplication::translate("MainWindow", "2400", Q_NULLPTR)
         << QApplication::translate("MainWindow", "4800", Q_NULLPTR)
         << QApplication::translate("MainWindow", "9600", Q_NULLPTR)
         << QApplication::translate("MainWindow", "19200", Q_NULLPTR)
         << QApplication::translate("MainWindow", "38400", Q_NULLPTR)
         << QApplication::translate("MainWindow", "57600", Q_NULLPTR)
         << QApplication::translate("MainWindow", "115200", Q_NULLPTR)
        );
        disconnectBtn->setText(QApplication::translate("MainWindow", "Disconnect", Q_NULLPTR));
        label_3->setText(QApplication::translate("MainWindow", "\320\244\320\276\321\200\320\274\320\270\321\200\320\276\320\262\320\260\320\275\320\270\320\265 \320\277\320\276\321\201\321\213\320\273\320\272\320\270:", Q_NULLPTR));
        hightBtn->setText(QApplication::translate("MainWindow", "\"1\"", Q_NULLPTR));
        lineEdit->setText(QApplication::translate("MainWindow", "10101100", Q_NULLPTR));
        lowBtn->setText(QApplication::translate("MainWindow", "\"0\"", Q_NULLPTR));
        ClearBtn->setText(QApplication::translate("MainWindow", "\320\236\321\207\320\270\321\201\321\202\320\272\320\260", Q_NULLPTR));
        label_5->setText(QApplication::translate("MainWindow", "\320\243\321\201\321\202\320\260\320\275\320\276\320\262\320\272\320\260 \321\202\320\260\320\271\320\274\320\265\321\200\320\260, \320\274\320\241 :", Q_NULLPTR));
        startBtn->setText(QApplication::translate("MainWindow", "C\321\202\320\260\321\200\321\202", Q_NULLPTR));
        stopBtn->setText(QApplication::translate("MainWindow", "\320\241\321\202\320\276\320\277", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
