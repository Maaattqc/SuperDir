#include <assert.h>
#include <stdint.h>
#include <iomanip>
#include <iostream>
#include "Functions.h"

int main(int Count, const char** Vector)
{
    if (Count < 2)
    {
        std::cerr << "Erreur passe un nom de repertoire\n";
        return 1;
    }

    IFileInfo** Files =  FindFiles(Vector[1]);
    return 0;
}