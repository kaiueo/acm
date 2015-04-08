#include <iostream>
#include "Date.h"
#include "Student.h"
using namespace std;

int main()
{
    Date d1(1996,12,31);
    d1.print();
    cout<<endl;
    char *n = "ZhangSan";
    Student s1(n, d1);
    s1.print();
    int cnt = Student::getCount();
    cout<<"Count:"<<cnt<<endl;
    Student *s2 = new Student("Lisi", 1997, 1, 1);
    s2->print();
    cnt = Student::getCount();
    cout<<"Count:"<<cnt<<endl;
    delete s2;
    cnt = Student::getCount();
    cout<<"Count:"<<cnt<<endl;
    Student s3(s1);
    s3.print();
    cnt = Student::getCount();
    cout<<"Count:"<<cnt<<endl;

    return 0;
}
