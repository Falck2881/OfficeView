#include "WindowID.h"
#include <QApplication>
#include <QFile>
#include <QDebug>

int main(int argc, char *argv[])
{
    QFile style(":/Takezo.qss");
    if(!style.open(QIODevice::ReadOnly)){
        qDebug() << "Failed read style 'Takezo' from file";
        QApplication::quit();
    }

    QApplication app(argc, argv);
    app.setStyleSheet(QString(style.readAll()));
    WindowID w;
    w.show();
    return app.exec();
}
