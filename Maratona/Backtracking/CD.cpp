#include <iostream>

using namespace std;

#define SIZE 21

int tracks[SIZE], n;

void cd(int i)
{

}

int main()
{
    // While input for n is valid
    while (cin >> n)
    {
        int length;

        // While length is valid
        for (int i = 0; cin >> length; i++)
            tracks[i] = length;
        
        // Iterate over tracks array
        for (int i = 0; i < sizeof(tracks) / sizeof(tracks[0]); i++)
        {

        }
    }

}