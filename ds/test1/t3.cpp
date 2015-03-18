#include <iostream>
#include <cstdio>
#include <string>
#include <cmath>
using namespace std;
string a[25];
bool com(string s1, string s2){
    int len = min(s1.length(), s2.length());
    for(int i = 0;i<len;i++){
        if(s1[i]>s2[i]){
            return true;
        }
        else if(s1[i]<s2[i]){
            return false;
        }
    }
    return s1.length() > s2.length();

}

void bsort(int n){
    for(int i = 0;i<n-1;i++){
        for(int j = 0;j<n-i-1;j++){
            if(com(a[j], a[j+1])){
                swap(a[j], a[j+1]);
            }
        }
    }
}
int main(){
    int n;
    while(cin>>n){
        for(int i = 0;i<n;i++){
            cin>>a[i];

        }
        bsort(n);
        for(int i = 0;i<n;i++){
            cout<<a[i]<<endl;
        }
        cout<<endl;
    }
}
