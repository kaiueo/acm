
#include <iostream>
#include <cstdio>
#include <string>
using namespace std;
int main()
{
    int n;
    cin>>n;
    for(int i = 1; i<=n; i++)
    {

        string s1;
        string s2;
        cin>>s1>>s2;
        if(s1.length()<s2.length())
        {
            swap(s1, s2);
        }
        for(int i = s2.length(); i<s1.length(); i++)
        {
            s2 = '0' + s2;
        }
        string s3;
        int g=0;
        int j=0;
        for(int i =s1.length()-1; i>=0; i--)
        {
            g = s1[i]+s2[i]-'0'-'0'+j;
            if(g>=10)
            {
                j = 1;
                g -= 10;
            }
            s3 =(char)(g+'0')+s3;
        }
        if(j!=0)
        {
            s3 = (char)(j + '0')+ s3;
        }
        cout<<s3<<endl;
    }

}

