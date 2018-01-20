//Program to find the number of all possible ways of writing x = sum of (number raised to N) 
//Programming paradigm - backtracking

#include <iostream>
#include <cmath>
using namespace std;

double SubSet(double x, double n, double current_num)
{
    if(pow(current_num,n)<x)
    {
        //two parts, a.)Take the current_num as part of solution set, b.)Don't take the current_num
        return SubSet(x-pow(current_num,n),n,current_num+1)+SubSet(x,n,current_num+1);
    }
    else if(pow(current_num,n)==x)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
int main()
{
    double x,n;
    cin>>x>>n;
    cout<<SubSet(x,n,1); // start with 1, check if you can take it as part of one of the solutions or not, continue with the next number and so on
    return 0;
}