#ifndef STUDENT_H
#define STUDENT_H
#define MAX_SIZE 10
#include "Date.h"
#include "Course.h"
#include <iostream>
#include <string>
using namespace std;
class Student
{
    friend ostream& operator<<(ostream&, const Student &s);   //重载流运算符的友元声明，输出学生以及选课信息
    public:
        Student& addCourse(Course *course);             //通过课程指针添加课程，实现学生选课功能
        Student& addCourse(const string &courseName, int creditHour);//通过课程名和学分信息添加课程，实现学生选课功能

        bool removeCourse(int i);                       //删除指定位置的课程
        bool removeCourse(const string& courseName);    //根据课程名称删除课程
        bool isExist(Course* course) const;

        //void print() const;   //打印学生信息

        Student& setName(const char* const n);//set函数，设置姓名
        const char* getName() const {return name;}//get函数，获得姓名
        const Date& getBirthDate() const {return birthDate;}//get函数，获得生日
        static int getCount() {return count;}//静态get函数，获得对象数量

        Student(const char* const n, int y, int m, int d);//构造函数
        Student(const char* const n, const Date &d);//构造函数
        Student(const Student &s);  //拷贝构造函数
        virtual ~Student(); //析构函数
    protected:
    private:
        char *name; //姓名
        const Date birthDate;   //生日
        static int count;   //静态成员，用于统计学生数目

        int courseNumber;   //当前实际课程数目
        Course *courseList[MAX_SIZE];   //存储当前学生所选的课程指针
};

#endif // STUDENT_H
