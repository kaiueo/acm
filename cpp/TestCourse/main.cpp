#include <iostream>
#include "Date.h"
#include "Student.h"
#include "ObligatoryCourse.h"
#include "ElectiveCourse.h"
using namespace std;

int main()
{


    ObligatoryCourse* oc1 = new ObligatoryCourse("�߼����Գ������-2", 3);
    ObligatoryCourse* oc2 = new ObligatoryCourse("����", 2);
    ObligatoryCourse* oc3 = new ObligatoryCourse("��ѧ����", 5);

    ElectiveCourse* ec1 = new ElectiveCourse("��������", 1);
    ElectiveCourse* ec2 = new ElectiveCourse("��������", 1);
    ElectiveCourse* ec3 = new ElectiveCourse("��Ӱ����", 1);



    cout<<"������ѧ������:";
    char name[100];
    cin>>name;
    cout<<endl;
    cout<<"������ѧ�����գ��������ö��߸���:";
    int year, month, day;
    cin>>year>>month>>day;
    cout<<endl;
    Student s(name, year, month, day);
    bool flag = true;
    while(flag)
    {

        cout<<"���濪ʼѡ�Σ�\n1.���޿�\n2.ѡ�޿�\n3.��ʾѧ����Ϣ\n4.�˳�\n"<<endl;
        cout<<"����ѡ���ǣ�";
        int n;
        cin>>n;
        cout<<endl;
        switch(n)
        {
        case 1:
            cout<<"1."<<(*oc1)<<endl<<"2."<<(*oc2)<<endl<<"3."<<(*oc3)<<endl;
            cout<<"����ѡ���ǣ�";
            int n1;
            cin>>n1;
            cout<<endl;
            int m;
            switch(n1)
            {
            case 1:
                if(s.isExist(oc1))
                {
                    cout<<"�γ��Ѵ��ڣ�����\n"<<endl;
                }
                else
                {
                    cout<<"���������:";
                    cin>>m;
                    oc1->setMark(m);
                    s.addCourse(oc1);
                    cout<<endl;
                }
                break;
            case 2:
                if(s.isExist(oc2))
                {
                    cout<<"�γ��Ѵ��ڣ�����\n"<<endl;
                }
                else
                {
                    cout<<"���������:";
                    cin>>m;
                    oc2->setMark(m);
                    s.addCourse(oc2);
                    cout<<endl;
                }

                break;
            case 3:
                if(s.isExist(oc3))
                {
                    cout<<"�γ��Ѵ��ڣ�����\n"<<endl;
                }
                else
                {
                    cout<<"���������:";
                    cin>>m;
                    oc3->setMark(m);
                    s.addCourse(oc3);
                    cout<<endl;
                }
                break;
            default:
                cout<<"��������ȷ�����!!!\n"<<endl;
                break;
            }
            break;
        case 2:
            cout<<"1."<<(*ec1)<<endl<<"2."<<(*ec2)<<endl<<"3."<<(*ec3)<<endl;
            cout<<"����ѡ���ǣ�";
            int n2;
            cin>>n2;
            cout<<endl;
            char g;
            switch(n2)
            {
            case 1:
                if(s.isExist(ec1))
                {
                    cout<<"�γ��Ѵ��ڣ�����\n"<<endl;
                }
                else
                {
                    cout<<"������ȼ�:";
                    cin>>g;
                    ec1->setGrade(g);
                    s.addCourse(ec1);
                    cout<<endl;
                }
                break;
            case 2:
                if(s.isExist(ec2))
                {
                    cout<<"�γ��Ѵ��ڣ�����\n"<<endl;
                }
                else
                {
                    cout<<"������ȼ�:";
                    cin>>g;
                    ec2->setGrade(g);
                    s.addCourse(ec2);
                    cout<<endl;
                }
                break;
            case 3:
                if(s.isExist(ec3))
                {
                    cout<<"�γ��Ѵ��ڣ�����\n"<<endl;
                }
                else
                {
                    cout<<"������ȼ�:";
                    cin>>g;
                    ec3->setGrade(g);
                    s.addCourse(ec3);
                    cout<<endl;
                }
                break;
            default:
                cout<<"��������ȷ�����!!!\n"<<endl;
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
            cout<<"��������ȷ�����!!!\n"<<endl;
            break;
        }
    }

    return 0;
}
