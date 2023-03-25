/*!
 * \file
 * \brief This header file contain derivatives class implements partly regular expression.
*/
#ifndef REGEXPSIGNUP_H
#define REGEXPSIGNUP_H

#include "RegExp.h"

/// Type fields of input
enum class TypeInputData{USER_ID,///< field of input for name user
                         PASS, ///< field of input for password
                         CONFIRM_PASS, ///< field of input for confirm password
                         EMAIL ///< field of input for email
                        };

namespace RegExp
{
    /// RegExp::SignUp - Implements regular expression at registration account.
    class SignUp: public Base::RegExp
    {
        public:
            /*!
             * \brief This constructor initialize regular expression registration account.
             * \param input - reference on object derivative class from base class Base::Command.
             * \param type - type field of input.
             *
             * This constructor which accepts in quality parameter reference on
             * object 'input' (derivative class from base class Base::Command).
             * This reference on object we save, so that in the future transfer warning message, if such will be is needed.\n
             *
             * In body the constructor setting string of pattern in accordance with type field of input.
             */
            SignUp(Type::Command::Input* const input,
                   TypeInputData type);
        private:
            void setWarningMessage(QString& warningMessage) override;
            void initializeRegExp();
        private:
            Type::Command::Input* const input;
            TypeInputData type;
    };
}
#endif // REGEXPSIGNUP_H
