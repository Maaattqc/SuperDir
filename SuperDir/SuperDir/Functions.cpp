#include <assert.h>
#include <stdint.h>
#include <iomanip>
#include <iostream>
#include <memory.h>
#include <stdio.h>
#include <Windows.h>
#include "FileInfo_CPP.h"
#include "FileInfo_EXE.h"
#include "FileInfo_H.h"
#include "FileInfo_Other.h"
#include "Functions.h"

static IFileInfo* CreateFileInfo(const WIN32_FIND_DATA & aData);

IFileInfo** FindFiles(const char* aFolder)
{
    assert(aFolder != NULL);
    IFileInfo** lResult = new IFileInfo * [100];
    memset(lResult, 0, sizeof(IFileInfo*) * 100);
    char lPattern[1024];
    sprintf_s(lPattern, "%s\\*", aFolder);
    WIN32_FIND_DATA lData;
    HANDLE lHandle = FindFirstFile(L"*", &lData);
    if (INVALID_HANDLE_VALUE != lHandle)
    {
        unsigned int lCount = 0;

        do
        {
            if (0 == (lData.dwFileAttributes & FILE_ATTRIBUTE_DIRECTORY))
            {
                lResult[lCount] = CreateFileInfo(lData);
                assert(NULL != lResult[lCount]);
                //lResult[lCount]->Init(aFolder, lData.cFileName);
                lCount++;
                if (100 <= lCount)
                {
                    break;
                }
            }
        } while (FindNextFile(lHandle, &lData));
        BOOL lRet = FindClose(lHandle);
        assert(lRet);
    }
	std::cout << "Hello World!\n";
    return lResult;
}

//IFileInfo* CreateFileInfo(const WIN32_FIND_DATA& aData)
//{
//    size_t lLen = strlen(aData.cFileName);
//    IFileInfo* lResult;
//    if (0 == _stricmp(".cpp", aData.cFileName + lLen - 4)) { lResult = new FileInfo_CPP; }
//    else if (0 == _stricmp(".exe", aData.cFileName + lLen - 4)) { lResult = new FileInfo_EXE; }
//    else if (0 == _stricmp(".h", aData.cFileName + lLen - 2)) { lResult = new FileInfo_H; }
//    else
//    {
//        lResult = new FileInfo_Other;
//    }
//
//    assert(NULL != lResult);
//
//    return lResult;
//}