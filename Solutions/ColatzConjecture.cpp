#include <iostream>
#include <ctime>
using namespace std;

int main(int argc ,char** argv)
{
    if(argc<2)
    {
        cout<<"Please enter a number to check collatz conjecture!";
        return -1;
    }
    long long int n = atoll(argv[1]);
    long long int N = n;
    if(n<=1)
    {
        cout<<"The number needs to be greater than 1";
        return -1;
    }
    long long int steps = 0;
    clock_t t0,t1;
    t0 = clock();
    while(n>1)
    {
        if(n&1) //is odd?
        {
            n = n*3 + 1;
        }
        else //is even!!
        {
            n = n>>1; //divide by 2
        }
        steps++;
    }
    t1 = clock();
    double tt = (double)(t1-t0)/CLOCKS_PER_SEC;
    cout<<"The number of steps needed to reach "<<n<<" from "<<N<<" is "<<steps<<" in time:"<<tt;
    return 0;
}