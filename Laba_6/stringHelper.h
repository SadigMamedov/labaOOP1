#ifndef STRINGHELPER_H
#define STRINGHELPER_H

#include <stdio.h>
#include <stdlib.h>
#include <string>

#include "jsonException.h"

using namespace std;

class stringHelper
{
public:
    string deleteSymbol(string data, char symbol);
};

#endif // STRINGHELPER_H
