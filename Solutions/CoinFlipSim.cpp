//Read the paper:https://isocpp.org/files/papers/n3551.pdf to understand the beauty of random in c++
#include <iostream>
#include <random>
#include <algorithm> //for deck of cards shuffle implementation
#include <array>
#include <string>
#include <sstream>
using namespace std;
string pick_a_card()
{
    default_random_engine engine{};
    default_random_engine e{};
    uniform_int_distribution<int> suit_d{0,12};
    uniform_int_distribution<int> rank_d{0,3};
    ostringstream ss;
    using card = int;
    array<card,52> deck{};
    iota(deck.begin(),deck.end(),0);
    shuffle(deck.begin(),deck.end(),engine);

    auto suit = []( card c ){ return "SHDC"[c/13];};
    auto rank = []( card c) { return "AKQJT98765432"[c%13];};
    ss<<rank(rank_d(e))<<" "<<suit(suit_d(e))<<" ";
    // for(card c : deck)
    // {
    //     ss<<rank(c)<<suit(c)<<" ";
    // }
    return ss.str();
}
char toss_fair_coin()
{
    static default_random_engine engine{};
    static uniform_int_distribution<int> distribution{0,1};
    return "HT"[distribution(engine)];
}
int roll_fair_die()
{
    static default_random_engine engine{};
    static uniform_int_distribution<int> distribution{1, 6};
    return distribution(engine);
}
int main()
{
    int choice = 0;
    do
    {
        cout << "1. Toss a coin\t2. Roll a die\t3.Shuffle a card\t 4.exit\n";
        cout << "Enter your choice:";
        cin >> choice;
        switch (choice)
        {
        case 1:
            cout << "Coin faces:" << toss_fair_coin() << endl;
            break;
        case 2:
            cout << "Die faces:" << roll_fair_die() << endl;
            break;
        case 3:
            cout<<"Card picked"<<pick_a_card()<<endl;
            break;
        case 4:
            cout << "Thank you!";
            system("pause");
            return 0;
            break;
        default:
            cout << "Wrong choice!!";
        }
    } while (choice != 0);
    return 0;
}