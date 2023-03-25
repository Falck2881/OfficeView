/*!
 * \file
 *  \brief This header file contain derived of class from abstract of class Base::Command
*/
#ifndef CHECKPASSWORD_H
#define CHECKPASSWORD_H

#include "Command.h"
#include <QString>

class WindowID;

namespace Type
{
    namespace Command
    {
        /*!
         * \brief Type::Command::CheckPassword - this class implements the pattern 'Command'
         *
         *  This derived of class implements checking input password.
         */
        class CheckPassword: public Simple::Command
        {
            public:
                /*!
                 * \brief CheckPassword - The constructor simple save reference 'window'
                 * \param window - the reference on mediator, her us need at execute this command
                 */
                CheckPassword(WindowID* const window);
                /*!
                 * \brief returning the warning message.
                 */
                QString warning() const;
                /*!
                 * \brief returning the icon of success, if the user data input right.
                 */
                QPixmap success() const;
                /*!
                 * \brief returning the  icon of error, if the user wrong at data input.
                 */
                QPixmap failure() const;
            public slots:
                /*!
                 * \brief setPassword - setting primary password.
                 * \param pass - invented password of user.
                 */
                void setPassword(const QString& pass);
                /*!
                 * \brief setConfirmPassword - set the confirmed password of user.
                 * \param confirmPass - confirmed password of user.
                 */
                void setConfirmPassword(const QString& confirmPass);
                /*!
                 * \brief execute - checking input password of user.
                 */
                void execute() override;
            private:
                void notifyAboutPassedCheck();
                void notifyAboutFailedCheck();
                void setWarningMessage(const QString newWarningMessage);
                bool isPasswordIdentical() const;
            private:
                QString warningMessage;
                QString password;
                QString confirmPassword;
                WindowID* const window;
        };
    }
}
#endif // CHECKPASSWORD_H
