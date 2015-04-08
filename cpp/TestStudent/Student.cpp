#include "Student.h"
#include "Date.h"
#include <cstring>
#include <iostream>
using namespace std;

int Student::count = 0;

Student::Student(const char* const n, const Date &b) : birthDate(b)
{
    count++;
    name = NULL;
    setName(n);
}

Student::Student(const char* const n, int y, int m, int d) : birthDate(y, m, d)
{
    count++;
    name = NULL;
    setName(n);
}

Student::~Student()
{
    count--;
    if(name) delete[] name;
}

Student::Student(const Student& other) : birthDate(other.birthDate)
{
    count++;
    name = NULL;
    setName(other.name);
}

void Student::setName(const char* const n)
{
    if(name) delete[] name;
    int length = strlen(n);
    name = new char(length + 1);
    strcpy(name,n);
}

const char *Student::getName() const
{
    return name;
}

const int Student::getCount()
{
    return count;
}

const Date Student::getBirthDate()
{
    return birthDate;
}

void Student::print() const
{
    cout<<"Name:"<<name<<endl;
    cout<<"birthday:";
    birthDate.print();
    cout<<endl;
}

