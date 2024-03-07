#include <iostream>
#include <iomanip>

using namespace std;

int main()
{
    double eps = 1;

    while (1 + eps > 1)
    {
        eps /= 2;
    }

    eps *= 2;

    cout << "epsilon = " << eps << endl;
    cout << fixed << setprecision(18) << "1 + x > 1:\n1 + x = " << 1 + eps << endl;
    
}