#include <iostream>
#include "Date.h"
#include "Student.h"
#include "Course.h"
using namespace std;

int main()
{


    cout<<"��ǰϵͳ����"<<Student::getCount()<<"λѧ��\n";

    Student stu1("����", 1985, 1, 1);
    stu1.addCourse("�߼����Գ������-2", 3);
    stu1.addCourse(new Course("��ѧ����", 5));
    stu1.addCourse("����", 2);

    Date d(1987, 3, 1);
    Student stu2("����", d);
    stu2.addCourse("�߼����Գ������-2", 3);
    stu2.addCourse(new Course("��ѧ����", 5));
    stu2.addCourse("˼���������", 2);

    Student *stu3;
    stu3=new Student("����", 1986, 2, 28);
    stu3->addCourse("�߼����Գ������-2", 3);
    stu3->addCourse(new Course("��ѧ����", 5));
    stu3->addCourse("��������", 2);

    cout<<"=======================================\n";
    cout<<"��ǰϵͳ����"<<Student::getCount()<<"λѧ��\n";
    cout<<stu1<<stu2<<(*stu3);

    delete stu3;
    cout<<"=======================================\n";
    cout<<"��ǰϵͳ����"<<Student::getCount()<<"λѧ��\n";
    cout<<stu1<<stu2<<endl;

    cout<<"=======================================\n";

    Student stu4 = stu1;
    cout<<stu4;
    cout<<"��ǰϵͳ����"<<Student::getCount()<<"λѧ��\n";
    stu4.addCourse("�߼����Գ������-2", 3);
    stu4.addCourse(new Course("��ѧ����", 5));
    stu4.addCourse("˼���������", 2);
    cout<<stu4;


    cout<<"=======================================\n";
    cout<<d<<endl;
    cout<<d++<<endl;
    cout<<++d<<endl;
    d = d + 10;
    cout<<d<<endl;
    cout<<"������һ�����ڣ�������ʹ�ÿո����"<<endl;
    cin>>d;
    cout<<d<<endl;
    cout<<"=======================================\n";
    stu4.addCourse("˼���������", 2); //��һ��Ҫ�˳�����


    return 0;
}


