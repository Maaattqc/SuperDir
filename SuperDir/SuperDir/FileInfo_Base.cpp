#include <assert.h>
#include <stdint.h>
#include <iomanip>
#include <iostream>
#include <string.h>
#include "FileInfo_Base.h"

void FileInfo_Base::Init(const char* LocalFolder, const char* LocalFile)
{
    assert(NULL != LocalFolder);
    assert(NULL != LocalFile);
    strncpy_s(File, LocalFile, sizeof(File) - 1); strncpy_s(Folder, LocalFolder, sizeof(Folder) - 1);
}

void FileInfo_Base::DisplayInformation() const
{
    size_t Lon = strlen(File);
    std::cout << File;
    std::cout << "                              " + Lon;
}

FileInfo_Base::FileInfo_Base()
{
    memset(&File, 0, sizeof(File));
    memset(&Folder, 0, sizeof(Folder));
}

void FileInfo_Base::RetrieveFileName(char* Out, unsigned int OutSize) const
{
    assert(OutSize > 0);

    assert(Out != NULL);

    sprintf_s(Out, OutSize, "%s\\%s", Folder, File);
}
