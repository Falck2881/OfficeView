#include "SignIn.h"

Type::Command::SignIn::SignIn(std::shared_ptr<ID::SignIn::User> dataUser):
    dataUser(dataUser)
{

}

void Type::Command::SignIn::execute()
{
    if(isDataUserExists())
        signIntoAccount();
}

bool Type::Command::SignIn::isDataUserExists()
{
    return dataUser->name != "" && dataUser->password != "";
}

void Type::Command::SignIn::signIntoAccount()
{

}
