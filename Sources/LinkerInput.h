/*!
 *\file
 *\brief This header file contain derived the class from abstract of class Base::Command.
*/

#ifndef LINKERINPUT_H
#define LINKERINPUT_H

#include "Input.h"
#include <QList>
#include <utility>
#include <QLineEdit>
#include <QPushButton>

namespace Linker
{
    /*!
     *  \brief Linker::Input - Encapsulated of a complex request into object together with recipient .
     *
     *  This derived the class encapsulates request, where check all fields of the input on  exists empty of string.
    */
    class Input: public Simple::Command
    {
        Q_OBJECT

        public:
            /*!
             * \brief This constructor save recipient, at execute this command him we well need.
             * \param button - This our recipient.
             *
             * At execute this command in dependence from condition, we will to change staty the 'button'
             */
            Input(QPushButton* const button);
            /*!
             * \brief Adding the reference of field of the input in list.
             * \param Reference on filed of the input.
             */
            void append(QLineEdit* const input);
        public slots:
            /*!
             * \brief Check all field of the input on string of empty. If found empty of string,
             *        that we disable button, else enabled her.
             */
            void execute() override;
        private:
            QList<QLineEdit*> allDeviceInput;
            QPushButton* const button;

    };
}
#endif // LINKERINPUT_H
