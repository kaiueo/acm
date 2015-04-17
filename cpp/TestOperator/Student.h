#ifndef STUDENT_H
#define STUDENT_H

#include "Date.h"
#include "Course.h"
#include <iostream>

#define MAX_SIZE 6
using namespace std;
class Student
{
    friend ostream& operator<<(ostream& out, const Student &s);
public:
    void print() const;

    Student& setName(const char* const n);//set函数，设置姓名
    const char* getName() const
    {
        return name;    //get函数，获得姓名
    }
    const Date& getBirthDate() const
    {
        return birthDate;    //get函数，获得生日
    }
    static int getCount()
    {
        return count;    //静态get函数，获得对象数量
    }


    Student(const char* const n, int y, int m, int d);//构造函数
    Student(const char* const n, const Date &d);//构造函数
    Student(const Student &s);  //拷贝构造函数
    virtual ~Student(); //析构函数

    Student& addCourse(Course *course);
    Student& addCourse(const string &courseName, int creditHour);

protected:
private:
    char *name; //姓名
    const Date birthDate;   //生日
    static int count;   //静态成员，用于统计学生数目
    Course *courseList[MAX_SIZE];
    int courseNumber;
};

#endif // STUDENT_H
