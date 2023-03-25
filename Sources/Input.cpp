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

void Type::Command::Input::setRegExp(std::shared_ptr<Base::RegExp> newRegExp)
{
    regExp = std::move(newRegExp);
}

QString Type::Command::Input::warning() const
{
    return warningMessage;
}

QPixmap Type::Command::Input::success() const
{
    QPixmap pixmap(":/IconOK.png");
    pixmap = pixmap.scaled(32,32,Qt::AspectRatioMode::KeepAspectRatio);
    return pixmap;
}

QPixmap Type::Command::Input::failure() const
{
    QPixmap pixmap(":/IconClose.png");
    pixmap = pixmap.scaled(32,32,Qt::AspectRatioMode::KeepAspectRatio);
    return pixmap;
}

void Type::Command::Input::updateWarningMessage(const QString &newMessage)
{
    setWarnningMessage(newMessage);
    window->notifyAboutErrorsInput(this);
}

void Type::Command::Input::execute()
{
    if(!regExp->isEmptyString(text)){
        if(!regExp->isMatchRegularExpression(text)){
            notifyMediatorAboutSuccessfullyInputting();
        }
    }
    else
        notifyMediatorAboutTheErrorInput();

}

void Type::Command::Input::setWarnningMessage(const QString &newWarnningMessage)
{
    warningMessage = newWarnningMessage;
}

void Type::Command::Input::notifyMediatorAboutSuccessfullyInputting()
{
    setWarnningMessage(" Successfully.");
    window->notifyAboutSuccessfullyInput(this);
}

void Type::Command::Input::notifyMediatorAboutTheErrorInput()
{
    setWarnningMessage(" Field empty, input a data.");
    window->notifyAboutErrorsInput(this);
}

QString Type::Command::Input::data() const
{
    return text;
}
