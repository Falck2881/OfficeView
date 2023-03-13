#include "Check.h"

Base::Check::Check(Base::Check* const typeChild):
    type(typeChild)
{

}

bool Base::Check::Check::isMatchRegularExpression(const QString& text)
{
    bool matchInput = false;
    QRegularExpressionMatch matchRegExp = regExp.match(text);
    matchInput = matchRegExp.hasMatch();

    if(matchInput)
        type->setWarningMessageByDefault();
    else
        type->setWarningMessage();

    return matchInput;
}
