#include <QApplication>
#include "mainwindow.h"
#include <QIcon>



int main(int argc, char *argv[])
{


    QApplication a(argc, argv);
    MainWindow w;
    a.setWindowIcon(QIcon("calculator.png"));
    w.show();
    return a.exec();
}
