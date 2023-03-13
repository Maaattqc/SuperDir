#include "FileInfo_EXE.h"
#include <iostream>

void FileInfo_EXE::DisplayInformation()
{
    FileInfo_Binary::DisplayInformation();

    std::cout << "  Fichier EXE\n";
}
