#ifndef CHECKINPUTSIGNIN_H
#define CHECKINPUTSIGNIN_H

#include "Check.h"

namespace Check
{
    namespace SignIn
    {
        class Input: public Base::Check
        {
            public:
                Input(Type::Command::Input* const input);
            private:
                void setWarningMessage() override;
                void setWarningMessageByDefault() override;
                void initializeRegExp();
            private:
                Type::Command::Input* const input;
        };
    }
}
#endif // CHECKINPUTSIGNIN_H
