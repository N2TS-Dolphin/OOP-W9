#pragma once
#include <vector>
#include <string>
#include <sstream>
#include <iomanip>

using namespace std;

#include "IValueConverter.h"
#include "Student.h"

class StudentToRowConverter : public IValueConverter
{
private:
    vector <int> _widths;

public:
    StudentToRowConverter(vector <int> widths)
    {
        _widths = widths;
    }

public:
    string toString()
    {
        return "StudentToRowConverter";
    }

    string convert(Object* object)
    {
        auto student = dynamic_cast<Student*>(object);
        stringstream builder;

        builder << setw(_widths[0]) << student->name() << "|";
        builder << setw(_widths[1]) << student->phone() << "|";
        builder << setw(_widths[2]) << student->address() << "|";

        string result = builder.str();
        return result;
    }
};