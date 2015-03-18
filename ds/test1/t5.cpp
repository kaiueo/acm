#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
using namespace std;
int main(){
    string s;
    while(getline(cin, s)){
        int len = s.length();
        if(len==0){
            printf("0\n");
            continue;
        }
        for(int i = 1;i<=len;i++){
            if(len%i==0){
                int f = 1;
                for(int j = i;j<len;j++){
                    if(s[j] != s[j%i]){
                        f = 0;
                        break;
                    }
                }
                if(f){
                    printf("%d\n",i);
                    break;
                }
            }
        }
    }
}
