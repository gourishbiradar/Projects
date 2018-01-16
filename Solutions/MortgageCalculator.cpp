#include <iostream>
#include <cmath>
#include <string>
using namespace std;
double mortgage(double principal, double roi, double term)
{
    double emi;
    int pow_term = pow((1+roi),term);
    emi = roi*principal*pow_term;
    emi/=(pow_term-1);
    return emi;
}
int main()
{
    double principal,roi;
    double term;
    cout<<"Enter the principal amount:";
    cin>>principal;
    cout<<"Enter the rate of interest and time period:";
    cin>>roi>>term;
    cout<<"Annuinty: 1. annually 2. monthly 3.weekly 4. daily\n";
    cout<<"Enter the choice :";
    int choice;
    cin>>choice;
    double emi;
    string units;
    switch(choice)
    {
        case 1:
            emi = mortgage(principal,roi/100,term);
            units = " years";
        break;
        case 2:
            emi = mortgage(principal,roi/1200,term);
            units = " months";
        break;
        case 3:
            emi = mortgage(principal,roi/4800,term);
            units = " weeks";
        break;
        case 4:
            emi = mortgage(principal,roi/36500,term);
            units = " days";
        break;
        default:
        cout<<"Wrong choice entered!";
        return -1;
    }
    cout<<"The principal "<<principal<<" can be paid with a monthly payment of "<<emi<<" over "<<term<<units;
    return 0;
}