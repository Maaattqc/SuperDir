#include "FileInfo_Binary.h"
#include <iostream>
#include <iomanip>

void FileInfo_Binary::DisplayInformation() const
{
    const char* UNITS[4] = { " o  ",
        "Kio ",
        "Mio ",
        "Gio " };

    FileInfo_Base::DisplayInformation();
    uint64_t lSize = Size;
    unsigned int lUnit = 0;
    for (; lUnit < 4; lUnit++)
    {
        if (1024 > lSize){
            break;}
        lSize /= 1024;
    }
    std::cout << std::setw(6) << lSize << " " << UNITS[lUnit];
}

void FileInfo_Binary::RetrieveInformation()
{
    char FileName[1024];
    struct _stat Data;
    RetrieveFileName(FileName, sizeof(FileName));
    int Number = _stat(FileName, &Data);
    if (Number == 0){
        Size = Data.st_size;
    }
}

FileInfo_Binary::FileInfo_Binary() : Size(0)
{}
