#include <iostream>
#include <vector>
#include <utility>
#include <string.h> //to use memset
using namespace std;

void LPF(int N, int s[])
{
    memset(s,0,N);
    s[1]=1;
    s[2]=2;
    for(int i=4;i<=N;i+=2)
    {
        s[i]=2;
    }
    for(int i=3;i<=N;i+=2)
    {
        if(s[i]==0)
        {
            s[i]=i;
            for(int j=2*i;j<=N;j+=i)
            {
                if(s[j]==0)
                    s[j]=i;
            }
        }
    }
}
void PowersOfN(int N,vector< pair<int,int> > PrimeFactors)
{
    int* s = new int[N+1];
    LPF(N,s);
    int curr = s[N];
    int power = 1;
    while(N>1)
    {
        N/=s[N];
        if(curr==s[N])
        {
            power++;
            continue;
        }
        cout<<curr<<" "<<power<<endl;
        PrimeFactors.push_back(make_pair(curr,power));
        curr = s[N];
        power=1;
    }

}
int main()
{
    int n;
    vector< pair<int,int> > PrimeFactors;
    cout<<"Enter a number:";
    cin>>n;
    cout<<"The prime factors with corresponding powers are:\n";
    PowersOfN(n,PrimeFactors);
    return 0;
}