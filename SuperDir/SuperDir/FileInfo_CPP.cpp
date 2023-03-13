#include "FileInfo_CPP.h"
#include <iostream>

void FileInfo_CPP::DisplayInformation() const
{
    FileInfo_Text::DisplayInformation();

    std::cout << "  Fichier C++ : Source\n";
}
