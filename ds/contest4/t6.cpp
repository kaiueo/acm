#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <string>
#include <cstring>

using namespace std;

int main()
{
    string s;
    while(cin>>s){
        int n;
        cin>>n;
        while(n--){
            string c;
            cin>>c;
            if(c=="Insert"){
                int t;
                cin>>t;
                string sub;
                cin>>sub;
                s.insert(t-1,sub);

            }
            else if(c=="Delete"){
                int m, n;
                scanf("%d%d", &m, &n);
                s.erase(m-1 ,n);

            }
            else{
                s += s;
            }
        }
        cout<<s<<endl;
    }

    return 0;
}

