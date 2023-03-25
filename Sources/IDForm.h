#ifndef IDFORM_H
#define IDFORM_H

#include <QString>

namespace ID
{
    namespace SignIn
    {
        struct User
        {
            QString name;
            QString password;
        };
    }

    namespace SignUp
    {
        struct User
        {
            QString name;
            QString email;
            QString password;
        };
    }
}



#endif // IDFORM_H
