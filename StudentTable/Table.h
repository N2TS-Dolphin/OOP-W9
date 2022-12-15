#pragma once
#include <vector>
#include <string>
#include <iomanip>
#include <iostream>

using namespace std;

#include "IValueConverter.h"
#include "Object.h"

class Table
{
private:
    vector<string> _headers;
    vector<int> _widths;
    vector<Object*> _data;
    IValueConverter* _converter;

public:
    Table(vector<string> headers, vector<int> widths, vector<Object*> data, IValueConverter* converter)
    {
        _headers = headers;
        _widths = widths;
        _data = data;
        _converter = converter;
    }

    void display()
    {
        int total = 0;
        for (int i = 0; i < _headers.size(); i++)
        {
            cout << setw(_widths[i]) << _headers[i] << "|";
            total += _widths[i];
        }
        cout << endl;

        for (int i = 0; i < total + 3; i++)
        {
            cout << "-";
        }

        cout << endl;

        for (int i = 0; i < _data.size(); i++) {
            string line = _converter->convert(_data[i]);
            cout << line << endl;
        }

        for (int i = 0; i < total + 3; i++)
        {
            cout << "-";
        }
    }
};