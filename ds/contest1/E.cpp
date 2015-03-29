#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <string>
#include <algorithm>
using namespace std;
int main()
{
    string s;
    while(cin>>s){
        int n;
        scanf("%d", &n);
        for(int i = 1;i<=n;i++){
            int a;
            cin>>a;
            string s1 = s.substr(0, a-1);
            string s2 = s.substr(a-1, s.length()-2*a+2);
            string s3 = s.substr(s.length()-a+1);

            reverse(s2.begin(), s2.end());
            s = s1+s2+s3;
        }
        cout<<s<<endl;
    }
    return 0;
}

