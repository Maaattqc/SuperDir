#pragma once
#include "IFileInfo.h"

class FileInfo_Base : public IFileInfo
{

public:

    virtual void Init(const char* aFolder, const char* aFile);


private:

    char mFile[512];
    char mFolder[256];

};