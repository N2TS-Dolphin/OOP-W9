#include "Object.h"
#include "IValueConverter.h"
#include "Student.h"
#include "StudentToRowConverter.h"
#include "Table.h"

int main()
{
    vector<Object*> data = { new Student("Tran Huu Long", "0909888712", "227 Nguyen Van Cu P4 Q5"),new Student("Cao Duc Tuan", "0773256712", "177 Nguyen Dinh Chieu Q3"),new Student("Le Mai Loan", "0869327617", "17 Tran Phu Q2"),new Student("Dinh Thi Ly", "0999876432", "35 Vo Thi Sau Q1"),new Student("Nguyen Duc Vinh", "0999882725", "15 Vo Van Tan P11 Binh Thanh") };
    vector<string> headers = { "Ho va ten", "SDT", "Dia chi" };
    vector<int> widths = { 15, 11, 28 };

    IValueConverter* converter = new StudentToRowConverter(widths);

    Table table(headers, widths, data, converter);
    table.display();
}