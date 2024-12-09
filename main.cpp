#include "studentmanagersql.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    StudentManagerSql w;
    w.show();
    return a.exec();
}
