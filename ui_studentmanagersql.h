/********************************************************************************
** Form generated from reading UI file 'studentmanagersql.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_STUDENTMANAGERSQL_H
#define UI_STUDENTMANAGERSQL_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_StudentManagerSql
{
public:
    QWidget *centralwidget;
    QVBoxLayout *verticalLayout_6;
    QLabel *label_2;
    QVBoxLayout *verticalLayout;
    QLabel *label;
    QListWidget *listWidget;
    QHBoxLayout *horizontalLayout_7;
    QSpacerItem *horizontalSpacer;
    QVBoxLayout *verticalLayout_5;
    QHBoxLayout *horizontalLayout_2;
    QHBoxLayout *horizontalLayout;
    QVBoxLayout *verticalLayout_2;
    QLabel *label_3;
    QLabel *label_4;
    QLabel *label_9;
    QVBoxLayout *verticalLayout_3;
    QLineEdit *name_edit;
    QLineEdit *age_edit_3;
    QLineEdit *class_edit_2;
    QGroupBox *groupBox;
    QVBoxLayout *verticalLayout_4;
    QRadioButton *radioButton;
    QRadioButton *radioButton_2;
    QPushButton *add;
    QPushButton *modify;
    QPushButton *delete_2;
    QHBoxLayout *horizontalLayout_4;
    QHBoxLayout *horizontalLayout_6;
    QLabel *label_7;
    QLineEdit *query_edit_6;
    QPushButton *query;
    QHBoxLayout *horizontalLayout_3;
    QSpacerItem *horizontalSpacer_2;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *StudentManagerSql)
    {
        if (StudentManagerSql->objectName().isEmpty())
            StudentManagerSql->setObjectName(QString::fromUtf8("StudentManagerSql"));
        StudentManagerSql->resize(980, 747);
        StudentManagerSql->setMinimumSize(QSize(980, 0));
        StudentManagerSql->setMaximumSize(QSize(980, 16777215));
        centralwidget = new QWidget(StudentManagerSql);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        verticalLayout_6 = new QVBoxLayout(centralwidget);
        verticalLayout_6->setObjectName(QString::fromUtf8("verticalLayout_6"));
        label_2 = new QLabel(centralwidget);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        QFont font;
        font.setPointSize(35);
        label_2->setFont(font);
        label_2->setAlignment(Qt::AlignCenter);

        verticalLayout_6->addWidget(label_2);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        label = new QLabel(centralwidget);
        label->setObjectName(QString::fromUtf8("label"));
        QFont font1;
        font1.setPointSize(23);
        label->setFont(font1);

        verticalLayout->addWidget(label);

        listWidget = new QListWidget(centralwidget);
        listWidget->setObjectName(QString::fromUtf8("listWidget"));

        verticalLayout->addWidget(listWidget);


        verticalLayout_6->addLayout(verticalLayout);

        horizontalLayout_7 = new QHBoxLayout();
        horizontalLayout_7->setObjectName(QString::fromUtf8("horizontalLayout_7"));
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_7->addItem(horizontalSpacer);

        verticalLayout_5 = new QVBoxLayout();
        verticalLayout_5->setObjectName(QString::fromUtf8("verticalLayout_5"));
        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        label_3 = new QLabel(centralwidget);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        verticalLayout_2->addWidget(label_3);

        label_4 = new QLabel(centralwidget);
        label_4->setObjectName(QString::fromUtf8("label_4"));

        verticalLayout_2->addWidget(label_4);

        label_9 = new QLabel(centralwidget);
        label_9->setObjectName(QString::fromUtf8("label_9"));

        verticalLayout_2->addWidget(label_9);


        horizontalLayout->addLayout(verticalLayout_2);

        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        name_edit = new QLineEdit(centralwidget);
        name_edit->setObjectName(QString::fromUtf8("name_edit"));

        verticalLayout_3->addWidget(name_edit);

        age_edit_3 = new QLineEdit(centralwidget);
        age_edit_3->setObjectName(QString::fromUtf8("age_edit_3"));

        verticalLayout_3->addWidget(age_edit_3);

        class_edit_2 = new QLineEdit(centralwidget);
        class_edit_2->setObjectName(QString::fromUtf8("class_edit_2"));

        verticalLayout_3->addWidget(class_edit_2);


        horizontalLayout->addLayout(verticalLayout_3);


        horizontalLayout_2->addLayout(horizontalLayout);

        groupBox = new QGroupBox(centralwidget);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        verticalLayout_4 = new QVBoxLayout(groupBox);
        verticalLayout_4->setObjectName(QString::fromUtf8("verticalLayout_4"));
        radioButton = new QRadioButton(groupBox);
        radioButton->setObjectName(QString::fromUtf8("radioButton"));
        radioButton->setChecked(true);

        verticalLayout_4->addWidget(radioButton);

        radioButton_2 = new QRadioButton(groupBox);
        radioButton_2->setObjectName(QString::fromUtf8("radioButton_2"));

        verticalLayout_4->addWidget(radioButton_2);


        horizontalLayout_2->addWidget(groupBox);

        add = new QPushButton(centralwidget);
        add->setObjectName(QString::fromUtf8("add"));

        horizontalLayout_2->addWidget(add);

        modify = new QPushButton(centralwidget);
        modify->setObjectName(QString::fromUtf8("modify"));

        horizontalLayout_2->addWidget(modify);

        delete_2 = new QPushButton(centralwidget);
        delete_2->setObjectName(QString::fromUtf8("delete_2"));

        horizontalLayout_2->addWidget(delete_2);


        verticalLayout_5->addLayout(horizontalLayout_2);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));

        verticalLayout_5->addLayout(horizontalLayout_4);

        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setObjectName(QString::fromUtf8("horizontalLayout_6"));
        label_7 = new QLabel(centralwidget);
        label_7->setObjectName(QString::fromUtf8("label_7"));

        horizontalLayout_6->addWidget(label_7);

        query_edit_6 = new QLineEdit(centralwidget);
        query_edit_6->setObjectName(QString::fromUtf8("query_edit_6"));

        horizontalLayout_6->addWidget(query_edit_6);

        query = new QPushButton(centralwidget);
        query->setObjectName(QString::fromUtf8("query"));

        horizontalLayout_6->addWidget(query);


        verticalLayout_5->addLayout(horizontalLayout_6);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));

        verticalLayout_5->addLayout(horizontalLayout_3);


        horizontalLayout_7->addLayout(verticalLayout_5);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_7->addItem(horizontalSpacer_2);


        verticalLayout_6->addLayout(horizontalLayout_7);

        StudentManagerSql->setCentralWidget(centralwidget);
        menubar = new QMenuBar(StudentManagerSql);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 980, 26));
        StudentManagerSql->setMenuBar(menubar);
        statusbar = new QStatusBar(StudentManagerSql);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        StudentManagerSql->setStatusBar(statusbar);

        retranslateUi(StudentManagerSql);

        QMetaObject::connectSlotsByName(StudentManagerSql);
    } // setupUi

    void retranslateUi(QMainWindow *StudentManagerSql)
    {
        StudentManagerSql->setWindowTitle(QCoreApplication::translate("StudentManagerSql", "StudentManagerSql", nullptr));
        label_2->setText(QCoreApplication::translate("StudentManagerSql", "\345\255\246\347\224\237\344\277\241\346\201\257\347\256\241\347\220\206\347\263\273\347\273\237", nullptr));
        label->setText(QCoreApplication::translate("StudentManagerSql", "ID       \345\247\223\345\220\215      \346\200\247\345\210\253      \345\271\264\351\276\204      \347\217\255\347\272\247", nullptr));
        label_3->setText(QCoreApplication::translate("StudentManagerSql", "\350\276\223\345\205\245\345\247\223\345\220\215", nullptr));
        label_4->setText(QCoreApplication::translate("StudentManagerSql", "\345\271\264\351\276\204", nullptr));
        label_9->setText(QCoreApplication::translate("StudentManagerSql", "\347\217\255\347\272\247", nullptr));
        groupBox->setTitle(QCoreApplication::translate("StudentManagerSql", "\346\200\247\345\210\253", nullptr));
        radioButton->setText(QCoreApplication::translate("StudentManagerSql", "\347\224\267", nullptr));
        radioButton_2->setText(QCoreApplication::translate("StudentManagerSql", "\345\245\263", nullptr));
        add->setText(QCoreApplication::translate("StudentManagerSql", "\346\267\273\345\212\240", nullptr));
        modify->setText(QCoreApplication::translate("StudentManagerSql", "\344\277\256\346\224\271", nullptr));
        delete_2->setText(QCoreApplication::translate("StudentManagerSql", "\345\210\240\351\231\244", nullptr));
        label_7->setText(QCoreApplication::translate("StudentManagerSql", "\350\276\223\345\205\245ID\346\210\226\345\247\223\345\220\215", nullptr));
        query->setText(QCoreApplication::translate("StudentManagerSql", "\346\237\245\350\257\242", nullptr));
    } // retranslateUi

};

namespace Ui {
    class StudentManagerSql: public Ui_StudentManagerSql {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_STUDENTMANAGERSQL_H
