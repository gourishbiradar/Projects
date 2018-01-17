#include <iostream>
#include <cmath>
using namespace std;
//TODO fix rounding off errors
#define QUARTER 25
#define DIME 10
#define NICKEL 5
#define PENNIES 1
int main()
{
    int quarters=0,dimes=0,nickels=0,pennies=0;
    double cost,money;
    cout<<"Enter the cost:";
    cin>>cost;
    cout<<"Enter the money given:";
    cin>>money;
    if(cost>money)
    {
        cout<<"Please given adequate amount of money to pay for charges!!";
        return 0;
    }
    int dollars = floor(money-cost);
    int change = ((money-cost)-dollars)*100; //1 dollar is 100 cents
    if(change)
    {
        if(change%QUARTER==0)
        {
            quarters = change/QUARTER;
        }
        else
        {
            quarters = change/QUARTER;
            change = change - quarters*QUARTER;
            if(change%DIME==0)
            {
                dimes = change/DIME;
            }
            else
            {
                dimes = change/DIME;
                change = change - dimes*DIME;
                if(change%NICKEL==0)
                {
                    nickels = change/NICKEL;
                }
                else
                {
                    nickels = change/NICKEL;
                    change = change - nickels*NICKEL;
                    if(change)
                    {
                        pennies = change;
                    }
                }
            }
        }
    }
    cout<<"the change is " <<(money-cost)<<" paid with "
    <<dollars<<" dollars, "
    <<quarters<<" quarters, "
    <<nickels<<" nickels, "
    <<dimes<<" dimes and "
    <<pennies<<" pennies\n";
    system("pause");
    return 0;
}