#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <algorithm>
using namespace std;
typedef struct comp
{
    double real;
    double imag;
};
int main()
{
    int n;
    cin>>n;
    while(n--)
    {
        char s;
        double r1,i1,r2,i2;
        cin>>s>>r1>>i1>>r2>>i2;
        comp c1;
        c1.real = r1;
        c1.imag = i1;
        comp c2;
        c2.real = r2;
        c2.imag = i2;
        comp c3;
        switch(s)
        {
            case '+':
                c3.real = c1.real+c2.real;
                c3.imag = c1.imag+c2.imag;
                break;
            case '-':
                c3.real = c1.real - c2.real;
                c3.imag = c1.imag - c2.imag;
                break;
            case '*':
                c3.real = (c1.real*c2.real - c1.imag*c2.imag);
                c3.imag = (c1.real*c2.imag + c1.imag*c2.real);
                break;
            case '/':
                if(c2.real*c2.real+c2.imag*c2.imag==0)
                {
                    cout<<"Wrong Input!"<<endl;
                    continue;
                }
                else
                {
                    c3.real = (c1.real*c2.real+c1.imag*c2.imag)/(c2.real*c2.real+c2.imag*c2.imag);
                    c3.imag = (c1.imag*c2.real-c1.real*c2.imag)/(c2.real*c2.real+c2.imag*c2.imag);
                }
                break;
        }
        if(c3.real == 0&&c3.imag ==0)
        {
            printf("0\n");
        }
        else if(c3.real == 0&&c3.imag !=0)
        {
            if(c3.imag<0)
            {
                printf("%.2fi\n",c3.imag);
            }
            else if(c3.imag>0)
            {
                printf("%.2fi\n",c3.imag);
            }
        }
        else if(c3.real != 0&&c3.imag ==0)
        {
            printf("%.2f\n", c3.real);
        }
        else
        {
            printf("%.2f", c3.real);
            if(c3.imag<0)
            {
                printf("%.2fi\n",c3.imag);
            }
            else if(c3.imag>0)
            {
                printf("+%.2fi\n",c3.imag);
            }
        }




    }

    return 0;
}

