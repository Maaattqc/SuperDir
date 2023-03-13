#include <assert.h>
#include <iostream>
#include <Windows.h>
#include "FileInfo_CPP.h"
#include "FileInfo_EXE.h"
#include "FileInfo_H.h"
#include "FileInfo_Other.h"
#include "Functions.h"

IFileInfo** GResult = new IFileInfo * [100]; // (100), car c'est écrit dans la consigne du travail

IFileInfo** FindFiles(const char* Folder)
{
    assert(NULL != Folder);
    char Array[1024];
    int Count = 0;
    memset(GResult, 0, sizeof(IFileInfo*) * 100);
    sprintf_s(Array, "%s\\*", Folder);
    WIN32_FIND_DATA WIN32Data;
    HANDLE Handle = FindFirstFile(Array, &WIN32Data);
    if (Handle != INVALID_HANDLE_VALUE) {
        do {
            if ((WIN32Data.dwFileAttributes & FILE_ATTRIBUTE_DIRECTORY) == 0) {
                size_t Long = strlen(WIN32Data.cFileName);
                IFileInfo* ResultTemp;
                if (_stricmp(".cpp", WIN32Data.cFileName + Long - 4) == 0) {
                    ResultTemp = new FileInfo_CPP;
                }
                else if (_stricmp(".exe", WIN32Data.cFileName + Long - 4) == 0) {
                    ResultTemp = new FileInfo_EXE;
                }
                else if (_stricmp(".h", WIN32Data.cFileName + Long - 2) == 0) {
                    ResultTemp = new FileInfo_H;
                }
                else
                {
                    ResultTemp = new FileInfo_Other;
                }
                assert(ResultTemp != NULL);
                GResult[Count] = ResultTemp;
                assert(GResult[Count] != NULL);
                GResult[Count]->Init(Folder, WIN32Data.cFileName);
                Count++;

                if (100 <= Count)
                {break;}
            }
        } while (FindNextFile(Handle, &WIN32Data)); {BOOL Bool = FindClose(Handle); assert(Bool);}
    }
    return GResult;
}

void DisplayInformation(IFileInfo** Files)
{
    assert(Files != NULL);
    for (unsigned int i = 0; i < 100; i++)
    {
        if (NULL == Files[i])
        {
            break; } Files[i]->DisplayInformation();
    }
}

void RetrieveInformation(IFileInfo** Files)
{
    assert(Files != NULL);
    for (unsigned int i = 0; i < 100; i++)
    {
        if (NULL == Files[i])
        {
            break; } Files[i]->RetrieveInformation();
    }
}

void ReleaseMemory(IFileInfo** Files)
{
    assert(Files != NULL);
    for (unsigned int i = 0; i < 100; i++)
    {
        if (NULL == Files[i])
        {
            break;
        } delete Files[i];
    }

    delete[] Files;

}