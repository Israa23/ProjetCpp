#include "mainwindow.h"
#include "form.h"
#include "connection.h"
#include <QApplication>
#include <QMessageBox>
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow f;


    f.show();

    return a.exec();
}
