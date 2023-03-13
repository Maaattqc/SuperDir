#pragma once
class IFileInfo
{
public:
    virtual ~IFileInfo() = 0;

    virtual void Init(const char* Folder, const char* File) = 0;
    virtual void DisplayInformation() const = 0;
    virtual void RetrieveInformation() = 0;
};
