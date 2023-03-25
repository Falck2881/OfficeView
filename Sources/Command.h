/*!
 \file
 \brief This header file contain abstract class for implements pattern 'Command'
*/
#ifndef COMMAND_H
#define COMMAND_H

#include <QObject>

namespace Simple
{
    /*! \brief Base::Command - this abstract class which provides pure virtual of method
     *  for in order to derivative a class redefine him.
    */
    class Command: public QObject
    {
        Q_OBJECT
        public:
            virtual ~Command() = default;
        public slots:
            /*!
             * This pure virtual  method which must redefine a derivative object from this abstract the class
            */
            virtual void execute() = 0;
        protected:
            Command() = default;
    };
}
#endif // COMMAND_H
