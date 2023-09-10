#include <bits/stdc++.h>

using namespace std;

int main()
{
    
    map<char, set<int>> ba = {
        {'C', set<int>()},
        {'E', set<int>()},
        {'O', set<int>()},
        {'P', set<int>()}
    };
    
    string s;
    set<char> nogo;
    
    getline(cin, s);
    
    int dif = 3;
    for (int i = 0; i < s.length(); i+=3, dif+=3)
    {
        int card = stoi(string() + s[i] + s[i+1]);
        
        if (s[dif-1] == 'U')
            s[dif-1] = 'O';
            
        if (ba[s[dif-1]].find(card) == ba[s[dif-1]].end())
            ba[s[dif-1]].insert(card);
        
        else if (nogo.find(s[dif-1]) == nogo.end())
        {
            ba[s[dif-1]].clear();
            ba[s[dif-1]].insert(-5);
            nogo.insert(s[dif-1]);
        }
    }
    
    for (auto it: ba)
    {
        if (it.second.find(-5) != it.second.end())
            cout << "erro\n";
        
        else
        {
            if (it.second.size() < 13)
                cout << 13 - it.second.size() << endl;
            
            else
                cout << 0 << endl;
        }
    }

    return 0;
}