#ifndef STUDENTMANAGERSQL_H
#define STUDENTMANAGERSQL_H

#include <QMainWindow>
#include "sqlmanager.h"

#include <QWidget>
#include <QLabel>
#include <QHBoxLayout>

class StudentWidget : public QWidget {
    Q_OBJECT

public:
    explicit StudentWidget(const StudentDatabase::Student& student, QWidget* parent = nullptr)
        : QWidget(parent), m_student(student) {
        // 设置 QWidget 的 id 属性
        this->setProperty("studentId", m_student.id);

        // 创建显示学生信息的控件


        QLabel* id = new QLabel(QString::number(m_student.id));
       
        QLabel* nameLabel = new QLabel(m_student.name);

        QLabel* sex= new QLabel(m_student.gender);

        QLabel* age = new QLabel(QString::number(m_student.age));

        QLabel* classLabel = new QLabel(m_student.className);

        QHBoxLayout* layout = new QHBoxLayout;
        layout->addWidget(id);
        layout->addWidget(nameLabel);
        layout->addWidget(sex);
        layout->addWidget(age);
        layout->addWidget(classLabel);

        setLayout(layout);
    }

    // 获取学生 ID
    QString getStudentId() const {
        return m_student.id;
    }

private:
    StudentDatabase::Student m_student;  // 保存学生信息
};


QT_BEGIN_NAMESPACE
namespace Ui { class StudentManagerSql; }
QT_END_NAMESPACE

class StudentManagerSql : public QMainWindow
{
    Q_OBJECT

public:
    StudentManagerSql(QWidget *parent = nullptr);
    ~StudentManagerSql();

private slots:
    void on_add_clicked();

    void on_modify_clicked();

    void clearInput();
    void on_delete_2_clicked();

    void on_query_clicked();

    void onItemSelected();

    void showStudentsInListWidget(const QList< StudentDatabase::Student>& students);

private:
    // 创建 StudentDatabase 实例
    StudentDatabase* studentDb = nullptr;
    Ui::StudentManagerSql *ui;
};
#endif // STUDENTMANAGERSQL_H
