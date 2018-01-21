#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <string>
#include <cstring>
using namespace std;
typedef pair<int,string> is;

void CountingSort(is *argv, int argc, int k)
{
	is* b = new is[argc];
	int *c = new int[k+1];
	for(int i=0;i<=k;i++)
		c[i]=0;
	for(int i=0;i<argc;i++)
		c[argv[i].first]++;
	for(int i=1;i<argc;i++)
		c[argv[i].first]+=c[argv[i-1].first];
	for(int i=argc-1;i>=0;i--)
	{
		b[c[argv[i].first]-1]=argv[i];
		c[argv[i].first]--;
	}
	for(int i=0;i<argc;i++)
		argv[i]=b[i];
    //return b;
}

int main() {
    int limit = 1000000;
    int n;
    cin>>n;
    is *arr = new is[n];
    for(int i=0;i<n;i++)
    {
        int j;
        string str;
        cin>>j>>str;
        if(i<=n/2)
        {
           arr[i]=make_pair(j,"-");
        }
        else
        {
            arr[i]=make_pair(j,str);
        }
    }
    //arr = CountingSort(arr,n,limit);
    CountingSort(arr,n,limit);
    for(int i=0;i<n;i++)
    {
        cout<<arr[i].second<<" ";
    }
    return 0;
}