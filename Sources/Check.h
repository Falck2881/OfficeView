#ifndef CHECK_H
#define CHECK_H

#include <memory>
#include <QRegularExpression>
#include <QString>

namespace Type {
    namespace Command {
        class Input;
    }
}

namespace Base
{
    class Check
    {
        public:
            virtual ~Check() = default;
            bool isMatchRegularExpression(const QString& text);
        protected:
            virtual void setWarningMessage() = 0;
            virtual void setWarningMessageByDefault() = 0;
        protected:
            Check(Check* const typeChild);
        private:
            Check* const type;
        protected:
            QRegularExpression regExp;
    };
}
#endif // CHECK_H
