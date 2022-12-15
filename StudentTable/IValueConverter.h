#pragma once
#include <string>

using namespace std;

#include "Object.h"

class IValueConverter : public Object
{ // no need to implement toString function
public:
    virtual string convert(Object*) = 0;
};