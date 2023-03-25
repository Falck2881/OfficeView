#include "RegExpSignIn.h"
#include "Input.h"

RegExp::SignIn::SignIn(Type::Command::Input* const input):
    Base::RegExp(this),
    input(input)
{
    initializeRegExp();
}

void RegExp::SignIn::initializeRegExp()
{
    regExp.setPattern("[ -/:-@[-`{-№]");
}

void RegExp::SignIn::setWarningMessage(QString& warningMessage)
{
    warningMessage += regExp.pattern();
    input->updateWarningMessage(warningMessage);
}
