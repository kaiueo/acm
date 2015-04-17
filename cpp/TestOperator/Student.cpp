#include "Student.h"
#include <cstring>
#include <iostream>
#include "Course.h"
#include <cstdlib>
using namespace std;

int Student::count=0;

Student::Student(const char* const n, const Date &d)
    :birthDate(d)
{
    name=NULL;
    setName(n);
    count++;
    courseNumber = 0;
}

Student::Student(const char* const n, int y, int m, int d)//构造函数
    :birthDate(y, m, d)
{
    name=NULL;
    setName(n);
    count++;
    courseNumber = 0;
}

Student::Student(const Student &s)  //拷贝构造函数
    :birthDate(s.birthDate)
{
    name=NULL;
    setName(s.name);
    count++;
    for(int i = 0;i<s.courseNumber;i++){
        courseList[i] = s.courseList[i];
    }
    courseNumber = s.courseNumber;
}

Student::~Student()
{
    delete[] name;
    count--;
}

Student& Student::setName(const char * const n)
{
    if(name) delete[] name;
    name = new char[strlen(n)+1];
    strcpy(name, n);
    return *this;
}

void Student::print() const
{
	cout<<"姓名："<<name
		<<"\t生日：";
	cout<<birthDate;
	cout<<"\n";
}
Student& Student::addCourse(Course *course){
    if(courseNumber == MAX_SIZE){
        cerr<<"超过最大课程数！！！"<<endl;
        exit(0);
    }
    courseList[courseNumber++] = course;

    return (*this);
}
Student& Student::addCourse(const string &courseName, int creditHour){
    if(courseNumber == MAX_SIZE){
        cerr<<"超过最大课程数！！！"<<endl;
        exit(0);
    }
    Course *course = new Course(courseName, creditHour);
    addCourse(course);

    return (*this);
}


ostream& operator<<(ostream& out, const Student &s){
    out<<"姓名："<<s.getName()<<" 出生日期：";
    cout<<s.getBirthDate();
    out<<"，选课信息如下："<<endl;
    for(int i = 0;i<s.courseNumber;i++){
        cout<<*s.courseList[i];
    }
    return out;
}
