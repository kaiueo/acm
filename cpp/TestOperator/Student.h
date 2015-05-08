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

    Student& setName(const char* const n);//set��������������
    const char* getName() const
    {
        return name;    //get�������������
    }
    const Date& getBirthDate() const
    {
        return birthDate;    //get�������������
    }
    static int getCount()
    {
        return count;    //��̬get��������ö�������
    }


    Student(const char* const n, int y, int m, int d);//���캯��
    Student(const char* const n, const Date &d);//���캯��
    Student(const Student &s);  //�������캯��
    virtual ~Student(); //��������

    Student& addCourse(Course *course);
    Student& addCourse(const string &courseName, int creditHour);

protected:
private:
    char *name; //����
    const Date birthDate;   //����
    static int count;   //��̬��Ա������ͳ��ѧ����Ŀ
    Course *courseList[MAX_SIZE];
    int courseNumber;
};

#endif // STUDENT_H