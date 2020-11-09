/*
https://www.geeksforgeeks.org/generate-all-binary-strings-from-given-pattern/
*/

#include <bits/stdc++.h>

using namespace std;

void generateStrings(string str, int index)
{
    if(index == str.size())
    {   
        cout<<str<<endl;
        return;
    }

    if(str[index] == '?')
    {
        str[index] = '0';
        generateStrings(str, index + 1);   

        str[index] = '1';
        generateStrings(str, index + 1);
    }

    else
    {
        generateStrings(str, index + 1);
    }
    
}

int main()
{
    string str = "1??0?101";
    generateStrings(str, 0);
    return 0;
}