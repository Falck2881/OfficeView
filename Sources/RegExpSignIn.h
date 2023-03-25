/*!
 * \file
 * \brief This header file contain derivatives class implements partly regular expression.
*/
#ifndef REGEXPSIGNIN_H
#define REGEXPSIGNIN_H

#include "RegExp.h"

namespace RegExp
{
    ///RegExp::SignIn - Implements regular expression at sign in account.
    class SignIn: public Base::RegExp
    {
        public:
            /*!
             * \brief This constructor initialize regular expression for sign in account.
             * \param input - reference on object derivative class from base class Base::Command.
             *
             * This constructor which accepts in quality parameter reference on
             * object 'input' (derivative class from base class Base::Command).
             * This reference on object we save, so that in the future transfer warning message, if such will be is needed.\n
             *
             * In body the constructor setting string of pattern in accordance with type field of input.
             */
            SignIn(Type::Command::Input* const input);
        private:
            void setWarningMessage(QString& warningMessage) override;
            void initializeRegExp();
        private:
            Type::Command::Input* const input;
    };
}
#endif // REGEXPSIGNIN_H
