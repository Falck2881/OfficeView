#ifndef INPUT_H
#define INPUT_H

#include "Command.h"
#include "Check.h"

class WindowID;

namespace Type
{
    namespace Command
    {
        class Input: public Base::Command
        {
            Q_OBJECT

            public:
                Input(WindowID* const window);
                QString warning() const;
                void updateWarningMessageAboutSignIn(const QString& newMessage);
                void updateWarningMessageAboutSignUp(const QString& newMessage);
                void setCheck(std::shared_ptr<Base::Check> typeExp);
            signals:
               void data(const QString& text);
            public slots:
                bool execute() override;
                void saveText(const QString& newText);
            private:
                void setMessageAboutErrorInput();
                void setMessageAboutSuccessfulyInput();
                void sendData();
            private:
                QString text;
                QString warningMessage;
                WindowID* const window;
                std::shared_ptr<Base::Check> typeExp;

        };
    }
}
#endif // INPUTDATA_H
