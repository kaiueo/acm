#include <iostream>
#include "Date.h"
#include "Student.h"
#include "Course.h"
using namespace std;

int main()
{


    cout<<"当前系统中有"<<Student::getCount()<<"位学生\n";

    Student stu1("张三", 1985, 1, 1);
    stu1.addCourse("高级语言程序设计-2", 3);
    stu1.addCourse(new Course("数学分析", 5));
    stu1.addCourse("体育", 2);

    Date d(1987, 3, 1);
    Student stu2("李四", d);
    stu2.addCourse("高级语言程序设计-2", 3);
    stu2.addCourse(new Course("数学分析", 5));
    stu2.addCourse("思想道德修养", 2);

    Student *stu3;
    stu3=new Student("王五", 1986, 2, 28);
    stu3->addCourse("高级语言程序设计-2", 3);
    stu3->addCourse(new Course("数学分析", 5));
    stu3->addCourse("音乐欣赏", 2);

    cout<<"=======================================\n";
    cout<<"当前系统中有"<<Student::getCount()<<"位学生\n";
    cout<<stu1<<stu2<<(*stu3);

    delete stu3;
    cout<<"=======================================\n";
    cout<<"当前系统中有"<<Student::getCount()<<"位学生\n";
    cout<<stu1<<stu2<<endl;

    cout<<"=======================================\n";

    Student stu4 = stu1;
    cout<<stu4;
    cout<<"当前系统中有"<<Student::getCount()<<"位学生\n";
    stu4.addCourse("高级语言程序设计-2", 3);
    stu4.addCourse(new Course("数学分析", 5));
    stu4.addCourse("思想道德修养", 2);
    cout<<stu4;


    cout<<"=======================================\n";
    cout<<d<<endl;
    cout<<d++<<endl;
    cout<<++d<<endl;
    d = d + 10;
    cout<<d<<endl;
    cout<<"请输入一个日期，年月日使用空格隔开"<<endl;
    cin>>d;
    cout<<d<<endl;
    cout<<"=======================================\n";
    stu4.addCourse("思想道德修养", 2); //这一步要退出程序


    return 0;
}



