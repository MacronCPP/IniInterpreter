#include <iostream>
#include <IniInterpreter/IniFile.h> //header file

int main()
{
    IniInterpreter::IniFile file("example.ini");
    //loading from file example.ini

    std::cout << "Global variables in file: " << std::endl;

    for(auto& x : file.getGlobalVariables())
    {
        std::cout << x.first << " - " << (std::string)(x.second) << std::endl;
        //listing all variables in global space of ini file
    }

    if((bool)file.getGlobalVariables()["isHintTrue"]) //getting a variable named isHintTrue from global space
        std::cout << "The hint is right!" << std::endl;
    else
        std::cout << "The hint is wrong!" << std::endl;

    std::cout << "Sections: " << std::endl;

    for(auto& x : file) //file.begin and file.end return iterators for std::map<std::string, IniInterpreter::Section>
    {
        std::cout << "  Name: " << x.first << std::endl;
        x.second[x.second.getVariable<std::string>("number")] = true;
        //it is possible to use operator [] or getVariable
    }

    file.saveToFile("example_out.ini"); //you can save content of IniFile to file

    return 0;
}
