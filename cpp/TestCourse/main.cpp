#include <iostream>
#include "Date.h"
#include "Student.h"
#include "ObligatoryCourse.h"
#include "ElectiveCourse.h"
using namespace std;

int main()
{


    ObligatoryCourse* oc1 = new ObligatoryCourse("高级语言程序设计-2", 3);
    ObligatoryCourse* oc2 = new ObligatoryCourse("体育", 2);
    ObligatoryCourse* oc3 = new ObligatoryCourse("数学分析", 5);

    ElectiveCourse* ec1 = new ElectiveCourse("音乐欣赏", 1);
    ElectiveCourse* ec2 = new ElectiveCourse("美术欣赏", 1);
    ElectiveCourse* ec3 = new ElectiveCourse("电影欣赏", 1);



    cout<<"请输入学生姓名:";
    char name[100];
    cin>>name;
    cout<<endl;
    cout<<"请输入学生生日，年月日用短线隔开:";
    int year, month, day;
    cin>>year>>month>>day;
    cout<<endl;
    Student s(name, year, month, day);
    bool flag = true;
    while(flag)
    {

        cout<<"下面开始选课：\n1.必修课\n2.选修课\n3.显示学生信息\n4.退出\n"<<endl;
        cout<<"您的选择是：";
        int n;
        cin>>n;
        cout<<endl;
        switch(n)
        {
        case 1:
            cout<<"1."<<(*oc1)<<endl<<"2."<<(*oc2)<<endl<<"3."<<(*oc3)<<endl;
            cout<<"您的选择是：";
            int n1;
            cin>>n1;
            cout<<endl;
            int m;
            switch(n1)
            {
            case 1:
                if(s.isExist(oc1))
                {
                    cout<<"课程已存在！！！\n"<<endl;
                }
                else
                {
                    cout<<"请输入分数:";
                    cin>>m;
                    oc1->setMark(m);
                    s.addCourse(oc1);
                    cout<<endl;
                }
                break;
            case 2:
                if(s.isExist(oc2))
                {
                    cout<<"课程已存在！！！\n"<<endl;
                }
                else
                {
                    cout<<"请输入分数:";
                    cin>>m;
                    oc2->setMark(m);
                    s.addCourse(oc2);
                    cout<<endl;
                }

                break;
            case 3:
                if(s.isExist(oc3))
                {
                    cout<<"课程已存在！！！\n"<<endl;
                }
                else
                {
                    cout<<"请输入分数:";
                    cin>>m;
                    oc3->setMark(m);
                    s.addCourse(oc3);
                    cout<<endl;
                }
                break;
            default:
                cout<<"请输入正确的序号!!!\n"<<endl;
                break;
            }
            break;
        case 2:
            cout<<"1."<<(*ec1)<<endl<<"2."<<(*ec2)<<endl<<"3."<<(*ec3)<<endl;
            cout<<"您的选择是：";
            int n2;
            cin>>n2;
            cout<<endl;
            char g;
            switch(n2)
            {
            case 1:
                if(s.isExist(ec1))
                {
                    cout<<"课程已存在！！！\n"<<endl;
                }
                else
                {
                    cout<<"请输入等级:";
                    cin>>g;
                    ec1->setGrade(g);
                    s.addCourse(ec1);
                    cout<<endl;
                }
                break;
            case 2:
                if(s.isExist(ec2))
                {
                    cout<<"课程已存在！！！\n"<<endl;
                }
                else
                {
                    cout<<"请输入等级:";
                    cin>>g;
                    ec2->setGrade(g);
                    s.addCourse(ec2);
                    cout<<endl;
                }
                break;
            case 3:
                if(s.isExist(ec3))
                {
                    cout<<"课程已存在！！！\n"<<endl;
                }
                else
                {
                    cout<<"请输入等级:";
                    cin>>g;
                    ec3->setGrade(g);
                    s.addCourse(ec3);
                    cout<<endl;
                }
                break;
            default:
                cout<<"请输入正确的序号!!!\n"<<endl;
                break;
            }

            break;
        case 3:
            cout<<s<<endl;;
            break;
        case 4:
            flag = false;
            break;
        default:
            cout<<"请输入正确的序号!!!\n"<<endl;
            break;
        }
    }

    return 0;
}

