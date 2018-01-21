#include <iostream>
#include <cstdlib>
#include <chrono>
#include <thread>
#include <unistd.h>
#include <boost/thread/thread.hpp>
using namespace std;

int main()
{
    int x;
    while(1)
    {
        cout<<"1.Alarm in seconds\t2.Alarm in milliseconds\t3.Alarm in minutes\t4.Exit";
        int choice;
        cout<<"Enter your choice:";
        cin>>choice;
        switch(choice)
        {
            case 1:
            cout<<"Enter the time in seconds:";
            cin>>x;
            boost::this_thread::sleep( boost::posix_time::seconds(x));
            cout<<"\a";
            break;
            case 2:
            cout<<"Enter the time in milliseconds:";
            cin>>x;
            boost::this_thread::sleep(boost::posix_time::milliseconds(x));
            cout<<"\a";
            break;
            case 3:
            cout<<"Enter the time in minutes:";
            cin>>x;
            boost::this_thread::sleep( boost::posix_time::seconds((x/60)));  
            cout<<"\a";          
            break;
            case 4:
                cout<<"Thank you!";
                return 0;
            default:
            cout<<"Please enter the correct choice";
        }

    }
    //sleep(x);
    //std::this_thread::sleep_until(chrono::system_clock::now() + chrono::seconds(x));
    return 0;
}