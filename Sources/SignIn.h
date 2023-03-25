#ifndef SIGNIN_H
#define SIGNIN_H

#include "Command.h"
#include "IDForm.h"
#include <memory>

namespace Type
{
    namespace Command
    {
        class SignIn: public Simple::Command
        {
            public:
                SignIn(std::shared_ptr<ID::SignIn::User> dataUser);
            public slots:
                void execute() override;
            private:
                bool isDataUserExists();
                void signIntoAccount();
            private:
                std::shared_ptr<ID::SignIn::User> dataUser;
        };
    }
}
#endif // SIGNIN_H
