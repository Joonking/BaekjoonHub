#include <string>
#include <iostream>
using namespace std;

bool solution(string s)
{
    int P = 0;
    int Y = 0;
   for(char c : s)
   {
        if(c=='p' || c =='P')
            P++;
       else if(c=='y' || c == 'Y')
           Y++;
   }

    return P==Y;
}