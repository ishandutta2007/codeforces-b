#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while(t--)
    {
        string s;
        cin >> s;
        array<int,3> c={0,0,0};
        for(char a:s) c[a-'A']++;
        if(c[0]+c[2]==c[1]) cout << "YES\n";
        else cout << "NO\n";
    }
    return 0;
}