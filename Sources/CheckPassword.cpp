#include "CheckPassword.h"
#include "WindowID.h"
#include <QRegularExpression>
#include <QRegularExpressionMatch>

Type::Command::CheckPassword::CheckPassword(WindowID* const window):
    window(window)
{

}

void Type::Command::CheckPassword::setPassword(const QString& newPassword)
{
    password = newPassword;
}

void Type::Command::CheckPassword::setConfirmPassword(const QString& newConfirmPassword)
{
    confirmPassword = newConfirmPassword;
}

QString Type::Command::CheckPassword::warning() const
{
    return warningMessage;
}

QPixmap Type::Command::CheckPassword::failure() const
{
    QPixmap pixmap(":/IconClose.png");
    pixmap = pixmap.scaled(32,32,Qt::AspectRatioMode::KeepAspectRatio);
    return pixmap;
}

QPixmap Type::Command::CheckPassword::success() const
{
    QPixmap pixmap(":/IconOK.png");
    pixmap = pixmap.scaled(32,32,Qt::AspectRatioMode::KeepAspectRatio);
    return pixmap;
}

void Type::Command::CheckPassword::execute()
{
    if(isPasswordIdentical())
        notifyAboutPassedCheck();
    else
        notifyAboutFailedCheck();

}

bool Type::Command::CheckPassword::isPasswordIdentical() const
{
    QRegularExpression regExp( password + "$");
    QRegularExpressionMatch regMatch = regExp.match(confirmPassword);
    return regMatch.hasMatch() ? true : false;
}

void Type::Command::CheckPassword::notifyAboutPassedCheck()
{
    setWarningMessage("Passed check.");
    window->notifyAboutPassedCheckThePassword();
}

void Type::Command::CheckPassword::notifyAboutFailedCheck()
{
    setWarningMessage("Failed check.");
    window->notifyAboutFailedCheckThePassword();
}

void Type::Command::CheckPassword::setWarningMessage(const QString newWarningMessage)
{
    warningMessage = newWarningMessage;
}
