#include "studentmanagersql.h"
#include "ui_studentmanagersql.h"
#include <QButtonGroup>
#include <QMessageBox>

StudentManagerSql::StudentManagerSql(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::StudentManagerSql)
{
    ui->setupUi(this);

    studentDb = new StudentDatabase("students.db");

    // 创建一个 QButtonGroup
    QButtonGroup* buttonGroup = new QButtonGroup(this);

    // 将两个按钮添加到 QButtonGroup 中
    buttonGroup->addButton(ui->radioButton);
    buttonGroup->addButton(ui->radioButton_2);

    // 查询学生
    QString queryName = QString::fromLocal8Bit("");
    QList<StudentDatabase::Student> students = studentDb->fetchStudentByIdOrName("", queryName);
    for (const auto& student : students) {
        qDebug() << student.id << student.name << student.gender << student.age << student.className;
    }


    showStudentsInListWidget(students);

    // 连接信号和槽函数，当用户选择列表项时触发 onItemSelected() 槽函数
    connect(ui->listWidget, &QListWidget::itemSelectionChanged, this, &StudentManagerSql::onItemSelected);
}

StudentManagerSql::~StudentManagerSql()
{
    delete ui;
}


void StudentManagerSql::on_add_clicked()
{
    if (ui->name_edit->text().isEmpty())
    {
        // 弹出提示框
        QMessageBox::warning(this, QString::fromLocal8Bit("输入提示"), QString::fromLocal8Bit("请输入有效的 姓名!"));
        return;
    }

    StudentDatabase::Student student;
    student.age = ui->age_edit_3->text().toInt();
    student.className = ui->class_edit_2->text();
    student.name = ui->name_edit->text();
    student.gender = ui->radioButton->isChecked() ? QString::fromLocal8Bit("男") : QString::fromLocal8Bit("女");

    if (studentDb->addStudent(student))
    {
        QMessageBox::warning(this, QString::fromLocal8Bit("提示"), QString::fromLocal8Bit("添加成功"));
    }
    else
    {
        QMessageBox::warning(this, QString::fromLocal8Bit("输入提示"), QString::fromLocal8Bit("请输入不重复的id!"));
    }
    

    QList<StudentDatabase::Student> students = studentDb->fetchStudentByIdOrName("", "");

    showStudentsInListWidget(students);

}

void StudentManagerSql::on_modify_clicked()
{


    // 获取当前选中的列表项
    QListWidgetItem* selectedItem =
        ui->listWidget->currentItem();

    if (selectedItem)
    {
        // 获取该项关联的 QWidget（包含员工信息）
        QWidget* widget
            =
            ui->listWidget->itemWidget(selectedItem);

        if (widget)
        {
            // 获取自定义属性 "itemId"，表示员工的 ID
            QVariant idVariant
                =
                widget->property("itemId");

            // 将 QVariant 转换为整数类型的 ID
            int itemId =
                idVariant.toInt();

            // 根据 ID 查询员工信息并获取结果
            StudentDatabase::Student student = studentDb->fetchStudentByIdOrName(QString::number(itemId), "").front();
           

            // 更新信息
          
            if (ui->name_edit->text().isEmpty())
            {
                // 弹出提示框
                QMessageBox::warning(this, QString::fromLocal8Bit("输入提示"), QString::fromLocal8Bit("请输入有效的 姓名!"));
                return;
            }

            student.age = ui->age_edit_3->text().toInt();
            student.className = ui->class_edit_2->text();
            student.name = ui->name_edit->text();
            student.gender = ui->radioButton->isChecked() ? QString::fromLocal8Bit("男") : QString::fromLocal8Bit("女");


            // 刷新查询结果，更新列表
            if (studentDb->updateStudent(student))
            {
                QMessageBox::warning(this, QString::fromLocal8Bit("提示"), QString::fromLocal8Bit("修改成功"));
            }
          
        }
    }
    else
    {
        // 如果未选择项，弹出警告框
        QMessageBox::warning(this, QString::fromLocal8Bit("修改失败"), QString::fromLocal8Bit("未选中！"));
    }

  
    QList<StudentDatabase::Student> students = studentDb->fetchStudentByIdOrName("", "");

    showStudentsInListWidget(students);

}

// 清除输入框内容和列表项选择
void StudentManagerSql::clearInput()
{
    ui->name_edit->clear();  // 清除姓名输入框
    ui->age_edit_3->clear();  // 清除输入框
    ui->class_edit_2->clear();  // 清除输入框

    ui->listWidget->clearSelection();  // 清除列表项选择
}

void StudentManagerSql::on_delete_2_clicked()
{
    // 获取当前选中的列表项
    QListWidgetItem* selectedItem =
        ui->listWidget->currentItem();

    if (selectedItem)
    {
        // 获取该项关联的 QWidget（包含员工信息）
        QWidget* widget =
            ui->listWidget->itemWidget(selectedItem);

        if (widget)
        {
            // 获取自定义属性 "itemId"，表示员工的 ID
            QVariant idVariant = widget->property("itemId");

            
            if (studentDb->deleteStudent(idVariant.toString()))
            {
                QMessageBox::warning(this, QString::fromLocal8Bit("提示"), QString::fromLocal8Bit("删除成功"));
            }

            QList<StudentDatabase::Student> students = studentDb->fetchStudentByIdOrName("", "");

            showStudentsInListWidget(students);
            clearInput();
        }

    }
    else
    {
        QMessageBox::warning(this, QString::fromLocal8Bit("提示"), QString::fromLocal8Bit("未删除成功，未选中或不存在"));
    }

   
}

void StudentManagerSql::on_query_clicked()
{
    // 查询学生
    QString queryName = ui->query_edit_6->text();

    if (ui->query_edit_6->text().isEmpty())
    {
        QList<StudentDatabase::Student> students = studentDb->fetchStudentByIdOrName("", "");

        showStudentsInListWidget(students);
    }
    else
    {
        // 获取输入框中的查询字符串
        QString input
            =
            ui->query_edit_6->text();

        // 检查输入的字符串是否为数字
        bool isNumber = false;
        int id = input.toInt(&isNumber); // 转换为整数，如果是数字，isNumber 为 true

        if (isNumber)
        {
            // 如果是数字，调用查询函数，按 ID 查询
            QList<StudentDatabase::Student> students = studentDb->fetchStudentByIdOrName(input, "");

            showStudentsInListWidget(students);
        }
        else
        {
            // 如果是数字，调用查询函数，按 ID 查询
            QList<StudentDatabase::Student> students = studentDb->fetchStudentByIdOrName("", input);

            showStudentsInListWidget(students);
        }
    }
}


// 槽函数：处理当列表项被选中时的操作
void StudentManagerSql::onItemSelected()
{
    // 获取当前选中的列表项
    QListWidgetItem* selectedItem = ui->listWidget->currentItem();

    if (selectedItem)
    {
        // 获取该项关联的 QWidget（包含员工信息）
        QWidget* widget = ui->listWidget->itemWidget(selectedItem);

        if (widget)
        {
            // 获取自定义属性 "itemId"，表示员工的 ID
            QVariant idVariant = widget->property("itemId");

            // 将 QVariant 转换为整数类型的 ID
            QString itemId = idVariant.toString();

            // 根据 ID 查询员工信息
            auto result = studentDb->fetchStudentByIdOrName(itemId, "");
            if (result.empty())
            {
                return;  // 如果没有找到对应的员工，返回
            }

            StudentDatabase::Student student = result.front();

            // 设置 UI 中的文本框为查询到的员工信息
          
            ui->name_edit->setText(student.name);  // 设置员工姓名
            ui->age_edit_3->setText(QString::number( student.age));
            ui->class_edit_2->setText(student.className);

            if (student.gender == QString::fromLocal8Bit("男"))
            {
                ui->radioButton->setChecked(true);
            }
            else
            {
                ui->radioButton_2->setChecked(true);
            }
        }
    }
}

void StudentManagerSql::showStudentsInListWidget(const QList< StudentDatabase::Student>& students) {
    // 清空现有的 QListWidget 项
    ui->listWidget->clear();

    for (auto& student : students) {
        // 创建自定义的 StudentWidget
        StudentWidget* studentWidget = new StudentWidget(student);

        studentWidget->setProperty("itemId", student.id);

        // 创建一个 QListWidgetItem 来包装 QWidget
        QListWidgetItem* item = new QListWidgetItem(ui->listWidget);
        item->setSizeHint(studentWidget->sizeHint());  // 设置项的大小

        // 将 QWidget 添加到 QListWidgetItem
        ui->listWidget->setItemWidget(item, studentWidget);
    }
}
