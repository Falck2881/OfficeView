#include "Input.h"
#include "WindowID.h"
#include <QRegularExpressionMatch>


Type::Command::Input::Input(WindowID* const window):
    window(window)
{
}

void Type::Command::Input::saveText(const QString& newText)
{
    text = newText;
}

void Type::Command::Input::setCheck(std::shared_ptr<Base::Check> newTypeExp)
{
    typeExp = std::move(newTypeExp);
}

QString Type::Command::Input::warning() const
{
    return warningMessage;
}

void Type::Command::Input::updateWarningMessageAboutSignIn(const QString &newMessage)
{
    warningMessage = newMessage;
    window->updateMessageAboutSignIn(this);
}

void Type::Command::Input::updateWarningMessageAboutSignUp(const QString &newMessage)
{
    warningMessage = newMessage;
    window->updateMessageAboutSignUp(this);
}

bool Type::Command::Input::execute()
{
    bool isExecute = false;
    if(text != ""){
        if(typeExp->isMatchRegularExpression(text)){
            isExecute = true;
            sendData();
        }
        else
            isExecute = false;
    }
    else
        isExecute = false;


    return isExecute;
}

void Type::Command::Input::sendData()
{
    emit data(text);
}
