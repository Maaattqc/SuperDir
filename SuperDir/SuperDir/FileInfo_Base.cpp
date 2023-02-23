#include <assert.h>
#include <stdint.h>
#include <iomanip>
#include <iostream>
#include <string.h>
#include "FileInfo_Base.h"

void FileInfo_Base::Init(const char* Folder, const char* File)
{
    assert(NULL != Folder);
    assert(NULL != File);
    strncpy_s(mFile, File, sizeof(mFile) - 1); strncpy_s(mFolder, Folder, sizeof(mFolder) - 1);
}