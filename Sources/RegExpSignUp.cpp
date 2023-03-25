#include "RegExpSignUp.h"
#include "Input.h"

RegExp::SignUp::SignUp(Type::Command::Input* const input,
                            TypeInputData type):
    Base::RegExp(this),
    input(input),
    type(type)
{
    initializeRegExp();
}

void RegExp::SignUp::initializeRegExp()
{
    if(type == TypeInputData::EMAIL)
        regExp.setPattern("[ А-№]");
    else
        regExp.setPattern("[ -/:-@[-`{-№]");
}

void RegExp::SignUp::setWarningMessage(QString& warningMessage)
{
    if(type == TypeInputData::EMAIL){
        warningMessage += QString("Russion symbols and spaces");
        input->updateWarningMessage(warningMessage);
    }
    else{
        warningMessage += regExp.pattern();
        input->updateWarningMessage(warningMessage);
    }
}
