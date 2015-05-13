#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <string>
#include <cstring>

using namespace std;
char a[100005];
int main()
{
    while(scanf("%s", a)!=EOF){
        int k = strlen(a);
        long long int t;
        if(a[0]=='6'){
            t = 1;
        }
        else{
            t = 2;
        }
        for(int i = 1;i<k;i++){
            if(a[i] == '6'){
                t = t*2 +1;
            }else{
                t = t*2 +2;
            }
        }

    printf("%lld\n",t);

 }
    return 0;
}

