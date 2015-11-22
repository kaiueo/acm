#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <ctime>
#include <cmath>

using namespace std;

int main()
{
    long long int n;
    while(cin>>n)
    {

        srand((unsigned)time(NULL));
        long long int cnt = 0;

        for(int i = 0; i<n; i++)
        {
            double x = rand()%(999+1)/(float)(999+1);
            double y = rand()%(999+1)/(float)(999+1);
            if(x==0.0)
            {
                continue;
            }
            if((sin(x)/x)>=y)
            {
                cnt++;
            }

        }
        double ans = (double)cnt/n;
        printf("%.3f\n", ans);
    }

    return 0;
}
