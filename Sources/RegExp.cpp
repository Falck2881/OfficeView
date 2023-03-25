#include "RegExp.h"

Base::RegExp::RegExp(Base::RegExp* const typeChild):
    type(typeChild)
{

}

bool Base::RegExp::isMatchRegularExpression(const QString& text)
{
    QRegularExpressionMatch matchRegExp = regExp.match(text);
    bool matchInput = matchRegExp.hasMatch();

    if(matchInput)
    {
        QString warningMessage("You to input invalid charecters, check field input.\n"
                               "Invalid: ");
        type->setWarningMessage(warningMessage);
    }
    return matchInput;
}

bool Base::RegExp::isEmptyString(const QString &string)
{
    return string == "" ? true: false;
}
