#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <string>
#include <cstring>

using namespace std;

int next[505];
void getNext(string s){
    int j = 0, k = -1;
    next[0] = -1;
    while(j<s.length()){
        while(k>=0&&s[j]!=s[k]){
            k=next[k];
        }
        j++;
        k++;
        next[j]=k;
    }
}

int main()
{
    string s;
    while(cin>>s){
        memset(next, 0, sizeof(next));
        getNext(s);
        for(int i = 0;i<s.length();i++){
            printf("%d ", next[i]);
        }
        printf("\n");
    }

    return 0;
}

