#include <assert.h>
#include <stdint.h>
#include <iomanip>
#include <iostream>
#include "Functions.h"

int main(int Count, const char** Param)
{
    if (Count < 2){
        std::cerr << "Erreur passe un nom de repertoire\n";
        return 2;
    }

    IFileInfo** Files =  FindFiles(Param[1]);
    return 0;
}