#include <iostream>
#include "Date.h"
using namespace std;

int main()
{

    Date date1;
    date1.print();

    Date date2(2012,2,29);
    date2.print();

    date2.nextDay();
    date2.print();

    Date date3(2012,12,31);
    date3.print();

    date3.nextDay();
    date3.print();

    date1.setYear(0);
    date1.print();

    date1.setMonth(13);
    date1.print();

    date1.setMonth(2);
    date1.print();

    date1.setDay(33);
    date1.print();

    Date date4(date2);
    date4.print();

    return 0;
}
