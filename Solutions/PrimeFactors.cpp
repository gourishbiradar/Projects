#include <iostream>
#include <math.h>
#include <map>
using namespace std;
void PrimeGen(int n,map<int,int>& MapPrimes)
{
    while(n%2==0)
    {
        MapPrimes[2]++;
        //cout<<"2 ";
        n/=2;
    }
    int end = sqrt(n);
    for(int i=3;i<=end;i+=2)
    {
        while(n%i==0)
        {
            //cout<<i<<" ";
            MapPrimes[i]++;
            n/=i;
        }
    }
    if(n>2)
    MapPrimes[n]++;
}
int main(int argc, char** argv)
{
    if(argc<1)
    {
        cout<<"Please enter a number to factorize!"<<endl;
        system("pause");
        return -1;
    }
    int n = atoi(argv[1]);
    if(n<0)
    {
        cout<<"Can't factorize negative numbers!!"<<endl;
        system("pause");
        return -1;
    }
    map<int,int> MapPrimes;
    PrimeGen(n,MapPrimes);
    cout<<"Prime factors of "<<n<<" are: ";
    for(map<int,int> ::iterator itr = MapPrimes.begin();itr!=MapPrimes.end();itr++)
    {
        cout<<(*itr).first<<"^"<<(*itr).second<<"*";
    }
    return 0;
}