#ifndef SQLMANAGER_H
#define SQLMANAGER_H

#include <QObject>

#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlError>
#include <QList>
#include <QString>
#include <QStandardItemModel>
#include <QTableView>
#include <QDebug>

class StudentDatabase {
public:
    // 定义学生信息结构体
    struct Student {
    public:
        int id;          // 学号 (自动递增的整数)
        QString name;    // 姓名
        QString gender;  // 性别
        int age;         // 年龄
        QString className; // 班级
    };

    // 构造函数
    StudentDatabase(const QString& dbName) {
        // 使用SQLite数据库驱动连接数据库
        QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");

        // 设置数据库文件名
        db.setDatabaseName(dbName);

        // 尝试打开数据库，判断是否成功
        if (!db.open()) {
            // 如果打开失败，输出错误信息
            qDebug() << "Failed to open database!";
        }
        else {
            // 如果打开成功，输出成功信息
            qDebug() << "Database opened successfully!";
        }

        // 创建表格 (如果不存在)
        createTable();
    }

    // 创建表格
    void createTable() {
        QSqlQuery query;
        QString createTableQuery = R"(
        CREATE TABLE IF NOT EXISTS students (
            id INTEGER PRIMARY KEY AUTOINCREMENT,  -- 自动递增的整数类型主键
            name TEXT,
            gender TEXT,
            age INTEGER,
            className TEXT
        );
    )";

        // 执行创建表格的SQL语句
        if (!query.exec(createTableQuery)) {
            qDebug() << "Error creating table: " << query.lastError().text();
        }
    }


    // 添加学生
    bool addStudent(const Student& student) {
       

        QSqlQuery query;

        // 插入数据时无需指定 id 字段，SQLite 会自动生成
        query.prepare("INSERT INTO students (name, gender, age, className) VALUES (:name, :gender, :age, :className)");

        query.bindValue(":name", student.name);
        query.bindValue(":gender", student.gender);
        query.bindValue(":age", student.age);
        query.bindValue(":className", student.className);

        if (!query.exec()) {
            qDebug() << "Error inserting student: " << query.lastError().text();
            return false;
        }
        else {
            qDebug() << "Student inserted successfully!";
        }

        return true;
    }

    // 删除学生
    bool deleteStudent(const QString& id) {
      

        QSqlQuery query;
        query.prepare("DELETE FROM students WHERE id = ?");
        query.addBindValue(id);

        if (!query.exec()) {
            qDebug() << "删除学生失败: " << query.lastError().text();
            
            return false;
        }

      
        return true;
    }

    // 修改学生信息
    bool updateStudent(const Student& student) {
       

        QSqlQuery query;
        query.prepare("UPDATE students SET name = ?, gender = ?, age = ?, className = ? WHERE id = ?");

        query.addBindValue(student.name);
        query.addBindValue(student.gender);
        query.addBindValue(student.age);
        query.addBindValue(student.className);
        query.addBindValue(student.id);

        if (!query.exec()) {
            qDebug() << "修改学生信息失败: " << query.lastError().text();
            
            return false;
        }

        
        return true;
    }

    // 查询学生信息
    QList<Student> fetchStudentByIdOrName(const QString &id = "", const QString &name = "") {
        QList<Student> students;

       

        QSqlQuery query;
        QString sql = "SELECT * FROM students WHERE 1=1"; // 1=1 用于确保查询条件始终有效

        // 根据输入的查询条件，动态添加 SQL 查询条件
        if (!id.isEmpty()) {
            sql += " AND id = ?";
        }
        if (!name.isEmpty()) {
            sql += " AND name LIKE ?";
        }

        query.prepare(sql);

        // 绑定参数
        if (!id.isEmpty()) {
            query.addBindValue(id);
        }
        if (!name.isEmpty()) {
            query.addBindValue("%" + name + "%"); // 使用 LIKE 模糊查询
        }

        if (!query.exec()) {
            qDebug() << "查询失败: " << query.lastError().text();
            
            return students;
        }

        // 遍历查询结果，并将每一条结果存入 Student 结构体
        while (query.next()) {
            Student student;
            student.id = query.value(0).toInt();
            student.name = query.value(1).toString();
            student.gender = query.value(2).toString();
            student.age = query.value(3).toInt();
            student.className = query.value(4).toString();

            students.append(student);  // 将学生添加到列表
        }

      
        return students;
    }

 
private:
  
};



#endif // SQLMANAGER_H
