#include "CheckInputSignUp.h"
#include "Input.h"

Check::SignUp::Input::Input(Type::Command::Input* const input,
                            TypeInputData type):
    Base::Check(this),
    input(input),
    type(type)
{
    initializeRegExp();
}

void Check::SignUp::Input::initializeRegExp()
{
    if(type == TypeInputData::EMAIL)
        regExp.setPattern("[^ А-№]");
    else
        regExp.setPattern("[^ -/:-@[-`{-№]");
}

void Check::SignUp::Input::setWarningMessageByDefault()
{
    input->updateWarningMessageAboutSignUp("");
}

void Check::SignUp::Input::setWarningMessage()
{
    QString newMessageWarning("You to input invalid charecters, check field input.\n"
                              "Invalid: ");

    if(type == TypeInputData::EMAIL){
        newMessageWarning += QString("Russion symbols and spaces");
        input->updateWarningMessageAboutSignUp(newMessageWarning);
    }
    else{
        newMessageWarning += regExp.pattern();
        input->updateWarningMessageAboutSignUp(newMessageWarning);
    }
}
