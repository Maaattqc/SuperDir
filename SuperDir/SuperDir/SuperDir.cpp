#include <assert.h>
#include <iomanip>
#include <iostream>
#include "Functions.h"
int main(int Count, const char** Params)
{
    assert(Count >= 1);
    assert(Params != NULL);

    if (Count < 2)
    {
        std::cerr << "Erreur, passez un repertoire en argument\n";
        return 999;
    }

    IFileInfo** Files = FindFiles(Params[1]);
    RetrieveInformation(Files);
    DisplayInformation(Files);
    ReleaseMemory(Files);

    return 0;
}
