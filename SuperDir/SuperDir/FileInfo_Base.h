#pragma once
#include "IFileInfo.h"
#include <string>

class FileInfo_Base : public IFileInfo
{

public:

    virtual void Init(const char* aFolder, const char* aFile);

private:
    char mFile[256];
    char mFolder[256];

};