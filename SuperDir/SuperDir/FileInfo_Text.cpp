#include <iomanip>
#include <iostream>
#include "FileInfo_Text.h"
#include <cassert>
void FileInfo_Text::DisplayInformation() const
{
    FileInfo_Base::DisplayInformation();

    std::cout << std::setw(6) << LCount << " lignes \n";
}

void FileInfo_Text::RetrieveInformation()
{
    FILE* File;
    char FileName[512];
    char lLine[1024];
    RetrieveFileName(FileName, sizeof(FileName));
    int FOP = fopen_s(&File, FileName, "r");
    if (FOP == 0)
    {
        while (NULL != fgets(lLine, sizeof(lLine), File))
        {
            LCount++;
        }
        FOP = fclose(File);
        assert(FOP == 0);
    }
}
FileInfo_Text::FileInfo_Text() : LCount(0)
{
}
