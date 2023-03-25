/*!
 * \file
 * \brief This header file contain abstract class which partly implements regular expression.
*/
#ifndef REGEXP_H
#define REGEXP_H

#include <memory>
#include <QRegularExpression>
#include <QString>

namespace Type {
    namespace Command {
        class Input;
    }
}


namespace Base
{
    /*!
     *\brief  Base::RegExp - this abstract class which implements check string through regular expression.

     *  In particular we must check input a user on availability
     *  unacceptable symbols. In particular we must check input user on availability unacceptable  symbols.
     *  So as this the abstract class in him exists method which need redefine,
     *  for this responsible that two classes 'RegExp::SignIn' and 'RegExp::SignUp'.

    */
    class RegExp
    {
        public:
            virtual ~RegExp() = default;
            /*!
             * \brief This class method checks match with characters in a regular expression.
             * \param text - this variable we and checks in regular expression.
             * \return True if find match, otherwise false.
             */
            bool isMatchRegularExpression(const QString& text);
            /*!
             * \brief This class method checks, is empty string or not.
             * \param string - string which we checks.
             * \return True if is empty, otherwise false.
             */
            bool isEmptyString(const QString& string);
        protected:
            /*!
             * \brief This pure virtual function which redefine derivative classes.
             *  In each implementation derivatives classes  add to the message,
             *  mine  pattern of unacceptable charecters
             * \param warningMessage - to this message add string of pattern with unaccectable
            */
            virtual void setWarningMessage(QString& warningMessage) = 0;
        protected:
            /*!
             * \brief RegExp - this constructor used only at call constructors derivatives classes.
             *  We Does this for define reference on derivative class.
             * \param typeChild - this reference on derivative class
             */
            RegExp(RegExp* const typeChild);
        private:
            RegExp* const type;
        protected:
            QRegularExpression regExp;
    };
}
#endif // REGEXP_H
