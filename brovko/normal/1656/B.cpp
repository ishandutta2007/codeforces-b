#include <bits/stdc++.h>
#define int long long
#define ld long double
#define x first
#define y second
#define pb push_back

using namespace std;

int t, n, k, a[200005];

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> t;

    while(t--)
    {
        cin >> n >> k;

        for(int i = 0; i < n; i++)
            cin >> a[i];

        map <int, int> m;

        for(int i = 0; i < n; i++)
            m[a[i]]++;

        bool F = 0;

        for(int i = 0; i < n; i++)
            if(m[k + a[i]])
                F = 1;

        cout << (F ? "YES\n" : "NO\n");
    }
}