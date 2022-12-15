#pragma once
#include <string>

using namespace std;

#include "Object.h"

class Student : public Object
{
private:
    string _name;
    string _phone;
    string _address;

public:
    string name() { return _name; }
    string phone() { return _phone; }
    string address() { return _address; }

public:
    Student();
    Student(string name, string phone, string address)
    {
        _name = name;
        _phone = phone;
        _address = address;
    }

public:
    string toString()
    {
        return "Student";
    }
};