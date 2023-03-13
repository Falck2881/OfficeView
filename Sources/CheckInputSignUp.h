#ifndef CHECKINPUTSIGNUP_H
#define CHECKINPUTSIGNUP_H

#include "Check.h"

enum class TypeInputData{FAILED, USER_ID, PASS, CONFIRM_PASS, EMAIL};

namespace Check
{
    namespace SignUp
    {
        class Input: public Base::Check
        {
            public:
                Input(Type::Command::Input* const input,
                      TypeInputData type);
            private:
                void setWarningMessage() override;
                void setWarningMessageByDefault() override;
                void initializeRegExp();
            private:
                Type::Command::Input* const input;
                TypeInputData type;
        };
    }
}
#endif // CHECKINPUTSIGNUP_H
