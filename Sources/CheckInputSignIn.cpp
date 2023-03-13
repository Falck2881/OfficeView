#include "CheckInputSignIn.h"
#include "Input.h"

Check::SignIn::Input::Input(Type::Command::Input* const input):
    Base::Check(this),
    input(input)
{
    initializeRegExp();
}

void Check::SignIn::Input::initializeRegExp()
{
    regExp.setPattern("[^ -/:-@[-`{-№]");
}

void Check::SignIn::Input::setWarningMessageByDefault()
{
    input->updateWarningMessageAboutSignIn("");
}

void Check::SignIn::Input::setWarningMessage()
{
    QString newMessageWarning("You to input invalid charecters, check field input.\n"
                              "Invalid: ");
    newMessageWarning += regExp.pattern();
    input->updateWarningMessageAboutSignIn(newMessageWarning);
}
