#include <iostream>
#include <string>
#include <stack>
using namespace std;
bool isOpenBracket(char c)
{
    if(c=='(' || c=='{' || c='[' )
        return true;
    return false;
}
bool isnumeric(char c)
{
    if(c>=48 && c<=57)
        return true;
    return false;
}
bool isCloseBracket(char c)
{
    if(c==')' || c=='}' || c==']')
        return true;
    return false;
}
bool BracektsMatch(char open,char close)
{
    if(open=='(' && close==')')
        return true;
    if(open=='{' && close=='}')
        return true;
    if(open=='[' && close==']')
        return true;
    return false;
}
int SolveEqu(string str)
{
    stack<char> s;
    s.push('#');
    int result = 0;
    int length = str.length();
    for(int i=0;i<length;i++)
    {
        if(isOpenBracket(str[i]))
        {
            //Push it into the stack
        }
        else if(isCloseBracket(str[i]))
        {
            //Pop top elements
            //Check if it is numeric
            //if numeric solve
            //else pop the open bracket
            //if brackets  don't match throw error
        }
        else if(isnumeric(str[i]))
        {
            //pop the top element
            //if a sign
            //Calculate the numbers
        }
        else
        {
            //throw error
        }
    }
    return result;
}
int main()
{
    string str;
    cin>>str;
    int result = SolveEqu(str);
    cout << "The solution is "<<result;
    return 0;
}