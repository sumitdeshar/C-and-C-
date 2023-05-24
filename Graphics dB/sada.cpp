
// C++ program to reverse a string
// using first to last approach
// 'for' loop
#include <iostream>
using namespace std;
 
// Function to reverse a string
void reverseStr(string& str)
{
    int n = str.length();
 
    // Swap character starting from two
    // corners
    for (int i = 0; i < n / 2; i++)
    {

        swap(str[i], str[n - i - 1]);
    }
}
 
// Driver program
int main()
{
    string str;
    cout<<"What is your name"<<endl;
    cin>>str;
    reverseStr(str);
    cout <<"Your name is "<< str;
    return 0;
}
