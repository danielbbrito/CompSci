#include <iostream>

using namespace std;

void Troca(int *v, int start, int end)
{
    if (start >= end)
        return;

    int aux = v[start];
    v[start] = v[end];
    v[end] = aux;

    return Troca(v, start + 1, end - 1);
}

int main()
{
    int n[20];

    for (int i = 0; i < 20; i++)
    {
        cin >> n[i];
    }

    Troca(n, 0, 19);

    for (int i = 0; i < 20; i++)
    {
        cout << "N[" << i << "] = " << n[i] << endl;
    }
}