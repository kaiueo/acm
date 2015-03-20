#include <iostream>
#include "Date.h"
using namespace std;

int main()
{
    Date date1;
    date1.print();
    Date date2(2012,12,31);
    date2.print();
    date1.setYear(0);
    date1.print();
    date1.setMonth(2);
    date1.print();
    date1.setDay(33);
    date1.print();
    date2.nextDay();
    date2.print();
    Date date3(date2);
    date3.print();
    return 0;
}
