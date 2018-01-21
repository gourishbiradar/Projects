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
double nthroot(double x, int n, double precision=0.0001)
{
    if(!x)
        return 0;
    double x1 = x;
    double x2 = x/n; //first division
    while(abs(x1-x2)>precision)
    {
        x1=x2;
        x2 = ((n-1.0)*x2 + x/pow(x2,n-1.0))/n;
    }
    return x2;
}
double NSums(double x, double n,double highest_num)
{
    if(highest_num<0)
        return 0;
    if(x==0)
        return 1;
    if(x<0)
        return 0;
    return NSums(x-pow(highest_num,n),n,highest_num-1)+NSums(x,n,highest_num-1);
}
int main()
{
    double x,n;
    cin>>x>>n;
    //Subset sum approach
    //cout<<SubSet(x,n,1); // start with 1, check if you can take it as part of one of the solutions or not, continue with the next number and so on
    //nth root appraoch
    //double highest_num = pow(x,1.0/n); check if it works!!
    double highest_num = nthroot(x,n);
    cout<<NSums(x,n,highest_num);
    return 0;
}