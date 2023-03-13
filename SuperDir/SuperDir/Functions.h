#pragma once
class IFileInfo;

extern IFileInfo** FindFiles(const char* Folder);

extern void DisplayInformation(IFileInfo** Files);

extern void ReleaseMemory(IFileInfo** Files);

extern void RetrieveInformation(IFileInfo** Files);
