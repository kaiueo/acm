#include <iostream>
#include <cstdio>
using namespace std;
typedef struct{
    string name;
    long long int id;
    int avg;
    int gpa;
}stun;
stun stu[1005];
bool com(stun s1, stun s2){
    if(s1.avg!=s2.avg){
        return s1.avg < s2.avg;
    }
    else{
        if(s1.gpa != s2.gpa){
            return s1.gpa < s2.gpa;
        }
        else{
            if(s1.id != s2.id){
                return s1.id > s2.id;
            }
            else{
                return false;
            }
        }

    }
}
void bc(int n){
    for(int j = 0;j< n-1;j++){
        for(int i = 0;i<n-j-1;i++){
            if(com(stu[i], stu[i+1])){
                swap(stu[i],stu[i+1]);
            }
        }
    }
}
int main(){
    int n;
    while(scanf("%d",&n)!=EOF){
        for(int i = 0;i<n;i++){
            cin>>stu[i].name;
            scanf("%lld%d%d", &(stu[i].id), &(stu[i].avg), &(stu[i].gpa));
        }
        bc(n);
        for(int i = 0;i<n;i++){
            cout<<stu[i].name;
            printf(" %lld %d %d\n",stu[i].id,stu[i].avg, stu[i].gpa);
        }
    }
}
