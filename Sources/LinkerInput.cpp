#include "LinkerInput.h"

Linker::Input::Input(QPushButton* const button):button(button)
{

}

void Linker::Input::append(QLineEdit* const input)
{
    allDeviceInput.push_back(input);
}

void Linker::Input::execute()
{
    for(auto input: allDeviceInput)
    {
        if(input->text() == ""){
            button->setEnabled(false);
            break;
        }
        else
            button->setEnabled(true);
    }
}
