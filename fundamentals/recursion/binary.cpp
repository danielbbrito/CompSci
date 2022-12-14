/**
 * Converts decimal to binary using recursion
*/
#include <iostream>
#include <string>
using namespace std;

string binary(int decimal, string result);

int main()
{
    int num;
    
    cin >> num;

    cout << binary(num, "") 
         << endl;

    return 0;
}

string binary(int decimal, string result)
{
    if (decimal == 0)
    {
        return result;
    }

    result = to_string(decimal % 2) + result;

    return binary(decimal / 2, result);
}