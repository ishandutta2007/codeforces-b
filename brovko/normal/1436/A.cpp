#include <bits/stdc++.h>
#define int long long
#define ld long double

using namespace std;

int t, n, m, a[105];

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> t;

    while(t--)
    {
        cin >> n >> m;

        for(int i = 0; i < n; i++)
            cin >> a[i];

        int s = 0;

        for(int i = 0; i < n; i++)
            s += a[i];

        if(s == m)
            cout << "YES";
        else cout << "NO";

        cout << "\n";
    }
}