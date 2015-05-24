#ifndef COURSE_H
#define COURSE_H

#include <string>
#include <iostream>
using namespace std;

class Course
{
    friend ostream& operator<<(ostream &, const Course&);
    public:
        const string& getName()	const	{return name;}  //get函数，获得课程名称
        void setName(const string &n)	{name=n;}       //set函数，修改课程名称
        int getCreditHour()	const	{return creditHour;}//get函数，获得课程学分
        void setCreditHour(int ch){creditHour=ch;}      //set函数，修改课程学分
        virtual int getScore() const = 0;

        Course(const string &n="", int ch=0);   //构造函数
        virtual ~Course();                      //析构函数
    protected:
    private:
        string name;
        int creditHour;
};

#endif // COURSE_H
