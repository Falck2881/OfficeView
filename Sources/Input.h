/*!
 * \file
 * \brief   This header file contain derived of class from abstract of class Base::Command
*/
#ifndef INPUT_H
#define INPUT_H

#include "Command.h"
#include "RegExp.h"
#include <QPixmap>

class WindowID;

namespace Type
{
    namespace Command
    {
        /*!
         * \brief Type::Command::Input - The class is interlayer between data input and check in regular expression.
         *
         * As already is was tell, this class is interlayer, between data input and check in regular expression.
         * We encapsulate request where check on availability the data input.  Also this class implements part the  pattern 'Mediator',
         * this class is colleague for 'Mediator' and also 'Mediator' is recipient this request. As only we check data input
         * (at any  the results of the condition  of operator) begin communication with 'Mediator'
         *
         */
        class Input: public Simple::Command
        {
            Q_OBJECT

            public:
                /*!
                 * \brief The constructor simple save reference 'window'
                 * \param window - the reference on mediator, her us need at execute this command
                 */
                Input(WindowID* const window);
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
                /*!
                 * \brief updating warning message and begin communication with the mediator.
                 * \param newMessage - new warning message.
                 */
                void updateWarningMessage(const QString& newMessage);
                /*!
                 * \brief set derived of class from abstract of class Base::RegExp.
                 * \param typeExp - this regular expression used at check the data input.
                 *
                 *  Each field of input has mine regular expression and therefore we invert dependence used this method.
                 *  In this  method we transfer  derived class, which  implements regular expression.
                 *  At execute this command we data input check used this regular expression.
                 */
                void setRegExp(std::shared_ptr<Base::RegExp> typeExp);
                /*!
                 * \brief return verified input data.
                 */
                QString data() const;
            public slots:
                /*!
                 * \brief Execute check input data, on the subject  unacceptable charecters,
                 *  at the same time we use regular expression
                 */
                void execute() override;
                /*!
                 * \brief Save input data from user
                 * \param newText - new data the user
                 */
                void saveText(const QString& newText);
            private:
                void setMessageAboutErrorInput();
                void setMessageAboutSuccessfulyInput();
                void sendData();
                void setWarnningMessage(const QString& warnningMessage);
                void notifyMediatorAboutSuccessfullyInputting();
                void notifyMediatorAboutTheErrorInput();
            private:
                QString text;
                QString warningMessage;
                WindowID* const window;
                std::shared_ptr<Base::RegExp> regExp;
        };
    }
}
#endif // INPUTDATA_H
