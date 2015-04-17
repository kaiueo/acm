#ifndef DATE_H
#define DATE_H
#include <iostream>
using namespace std;

class Date
{
    friend ostream& operator<<(ostream &out, const Date &d);
    friend istream& operator>>(istream &in, Date &date);
public:
    Date& operator++();
    Date operator++(int);
    Date& operator+(int n);

    void nextDay();     //将当前日期加1，即下一日期
    bool isLeapYear() const;  //判断当前年份是否为闰年

    void setDate(int y, int m, int d);//set函数，设置日期
    int getYear()const
    {
        return year;    //get函数，返回年
    }
    int getMonth()const
    {
        return month;    //get函数，返回月
    }
    int getDay()const
    {
        return day;    //get函数，返回日
    }

    Date(int y, int m, int d);//构造函数
    Date();//缺省构造函数
    Date(const Date &d);  //拷贝构造函数
    virtual ~Date();//虚析构函数
protected:
private:
    bool checkDate();//工具函数，检查当前日期数据是否合法；如果不合法，则修改为默认的合法值，并返回false;否则返回true
    int maxDay() const;//工具函数，返回当前年和月背景下的最大日数

    int year;   //年
    int month;  //月
    int day;    //日
};

#endif // DATE_H
