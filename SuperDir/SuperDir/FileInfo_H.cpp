#include "FileInfo_H.h"
#include <iostream>

void FileInfo_H::DisplayInformation() const
{
    FileInfo_Text::DisplayInformation();

    std::cout << "  Langage C++ : Header\n";
}
