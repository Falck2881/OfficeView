#include "LinkerInput.h"

void Linker::Input::append(std::shared_ptr<Type::Command::Input> input)
{
    allDeviceInput.push_back(std::move(input));
}

bool Linker::Input::execute()
{
    bool isExecute = false;
    for(auto input: allDeviceInput)
    {
        if(input->execute())
            isExecute = true;
        else{
            isExecute = false;
            break;
        }
    }

    return isExecute;
}
