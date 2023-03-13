#include "WindowID.h"
#include "CheckInputSignIn.h"
#include "./ui_WindowID.h"

WindowID::WindowID():
    inputPass{std::make_shared<Type::Command::Input>(this)},
    inputUserId{std::make_shared<Type::Command::Input>(this)},
    linkerInputs{std::make_shared<Linker::Input>()},
    ui(new Ui::WindowID)
{
    ui->setupUi(this);
    collectAllInputAboutSignIn();
    collectAllInputAboutSignUp();
}

void WindowID::collectAllInputAboutSignIn()
{
    auto checkInputUserID{std::make_shared<Check::SignIn::Input>(inputUserId.get())};
    inputUserId->setCheck(checkInputUserID);
    linkerInputs->append(inputUserId);
    auto checkInputPassword{std::make_shared<Check::SignIn::Input>(inputPass.get())};
    inputPass->setCheck(checkInputPassword);
    linkerInputs->append(inputPass);
}

void WindowID::collectAllInputAboutSignUp()
{

}

void WindowID::updateMessageAboutSignIn(Type::Command::Input *const command)
{
    if(inputUserId.get() == command)
        ui->messUserID->setText(command->warning());
    else if(inputPass.get() == command)
        ui->messPass->setText(command->warning());
}

void WindowID::updateMessageAboutSignUp(Type::Command::Input *const command)
{

}

WindowID::~WindowID()
{
    delete ui;
}

