#include <assert.h>
#include <string.h>
#include "FileInfo_Base.h"

void FileInfo_Base::Init(const char* aFolder, const char* aFile)
{
    assert(aFolder != NULL);
    assert(aFile != NULL);
    mFolder = aFolder;
    mFile = aFile;
}

