#ifndef LINKERINPUT_H
#define LINKERINPUT_H

#include "Input.h"
#include <QList>
#include <utility>

namespace Linker
{
    class Input: public Base::Command
    {
        Q_OBJECT

        public:
            Input() = default;
            void append(std::shared_ptr<Type::Command::Input> input);
        public slots:
            bool execute() override;
        private:
            QList<std::shared_ptr<Type::Command::Input>> allDeviceInput;

    };
}
#endif // LINKERINPUT_H
