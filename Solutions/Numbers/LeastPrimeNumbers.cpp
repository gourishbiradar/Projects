#include <iostream>
#include <vector>
using namespace std;

void LPF(int n)
{
    vector<int> least_prime(n+1,0);
    least_prime[1]=1;
    //least prime factor of even numbers is 2
    for(int i=2;i<=n;i+=2)
    {
        least_prime[i]=2;
    }
    //calculate least prime factors of odd numbers
    for(int i=3;i<=n;i+=2)
    {
        if(least_prime[i]==0) //the number is prime
        {
            least_prime[i]=i;
            for(int j=2*i;j<=n;j+=i) //mark all the multiples to have i as the smallest prime
            {
                if(least_prime[j]==0)
                    least_prime[j]=i;
            }
        }
    }
    for(int i=1;i<=n;i++)
    {
        cout<<i<<" : "<<least_prime[i]<<endl;
    }
}
int main()
{
    int n;
    cout<<"Enter a number to find least prime factors:";
    cin>>n;
    LPF(n);
    return 0;
}