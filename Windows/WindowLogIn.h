#ifndef WINDOWLOGIN_H
#define WINDOWLOGIN_H

#include <QWidget>

QT_BEGIN_NAMESPACE
namespace Ui { class WindowLogIn; }
QT_END_NAMESPACE

class WindowLogIn : public QWidget
{
    Q_OBJECT

public:
    WindowLogIn(QWidget *parent = nullptr);
    ~WindowLogIn();

private:
    Ui::WindowLogIn *ui;
};
#endif // WINDOWLOGIN_H
