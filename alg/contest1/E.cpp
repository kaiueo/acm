#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#define max 1000005

long long data[max],b[max];
long long int coun;
void Merge(int start, int mid , int end)
{
	int i = start,j = mid + 1,k = start;
	while(i <= mid&&j <= end)
	{
		if(data[i] <= data[j])
		{
			b[k++] = data[i++];
		}
		else
		{
			coun += j - k;
			b[k++] = data[j++];
		}
	}
	while(i <= mid)
	{
		b[k++] = data[i++];
	}
	while(j <= end)
	{
		b[k++] = data[j++];
	}
	for(int i = start; i <= end; i++)
	{
		data[i] = b[i];
	}
}

void MergeSort(int start, int end)
{
	if(start < end)
	{
		int mid = (start + end)/2;
		MergeSort(start,mid);
		MergeSort(mid+1,end);
		Merge(start,mid,end);
	}
}
int main()
{

    int n;
    while(scanf("%d",&n)!=EOF)
    {
        coun = 0;
        for(int i = 0;i<n;i++){
            scanf("%d", &data[i]);
        }
        MergeSort(0, n-1);
            printf("%lld", coun);

        printf("\n");
    }

	return 0;
}
