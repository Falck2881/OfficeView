#ifndef WINDOWLOGIN_H
#define WINDOWLOGIN_H

#include <QWidget>
#include <memory>
#include "Input.h"
#include "LinkerInput.h"

QT_BEGIN_NAMESPACE
namespace Ui { class WindowID; }
QT_END_NAMESPACE

class WindowID : public QWidget
{
    Q_OBJECT

    public:
        WindowID();
        ~WindowID();
        void updateMessageAboutSignIn(Type::Command::Input* const command);
        void updateMessageAboutSignUp(Type::Command::Input* const command);

    private:
        void collectAllInputAboutSignIn();
        void collectAllInputAboutSignUp();

    private:
        std::shared_ptr<Type::Command::Input> inputPass;
        std::shared_ptr<Type::Command::Input> inputUserId;
        std::shared_ptr<Linker::Input> linkerInputs;
        Ui::WindowID *ui;
};
#endif // WINDOWLOGIN_H
