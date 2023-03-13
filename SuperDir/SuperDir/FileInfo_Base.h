#pragma once
#include "IFileInfo.h"
#include <string>

class FileInfo_Base : public IFileInfo 
{
public:

    virtual void Init(const char* Folder, const char* File);

    virtual void DisplayInformation() const;


protected:

    FileInfo_Base();
    void RetrieveFileName(char* Out, unsigned int Size) const;

private:
    char File[256];
    char Folder[256];

};