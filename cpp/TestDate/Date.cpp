#include "Date.h"
#include <cstdio>
Date::Date()
{
    setYear(1);
    setMonth(1);
    setDay(1);
}

Date::Date(int y, int m, int d)
{
    setYear(y);
    setMonth(m);
    setDay(d);
}

Date::~Date()
{
    //dtor
}

Date::Date(const Date& other)
{
    setYear(other.year);
    setMonth(other.month);
    setDay(other.day);
}

void Date::setYear(int y)
{
    (isYearValid(y))?(year = y):(year = 1);
}
void Date::setMonth(int m)
{
    (isMonthValid(m))?(month = m):(month = 1);
}
void Date::setDay(int d)
{
    (isDayValid(d))?(day = d):(day = 1);
}

bool Date::isYearValid(int y)
{
    if(y>=1)
    {
        return true;
    }
    return false;
}

bool Date::isMonthValid(int m)
{
    if(m>=1&&m<=12)
    {
        return true;
    }
    return false;
}

bool Date::isDayValid(int d)
{
    int days[12] = {31,28,31,30,31,30,31,31,30,31,30,31};
    if(isLeapYear(year))
    {
        days[1] = 29;
    }

    if(d>=1&&d<=days[month-1])
    {
        return true;
    }
    return false;


}
bool Date::isLeapYear(int y)
{

    if((y%4==0&&y%100!=0)||(y%400==0))
    {
        return true;
    }
    return false;

}
int Date::getYear()
{
    return year;
}

int Date::getMonth()
{
    return month;
}

int Date::getDay()
{
    return day;
}

void Date::nextDay()
{
    day++;
    if(!isDayValid(day))
    {
        day = 1;
        month++;
        if(!isMonthValid(month))
        {
            month = 1;
            year++;
        }
    }
}

void Date::print()
{
    printf("%d-%02d-%02d\n", year, month, day);
}

