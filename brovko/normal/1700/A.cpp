#include <bits/stdc++.h>
//#define int long long
#define ld long double
#define pb push_back
#define x first
#define y second

using li = long long;

using namespace std;


int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int t;
    cin >> t;

    while(t--)
    {
        int n, m;
        cin >> n >> m;

        li ans = 0;

        for(int j = 1; j <= m; j++)
            ans += j;

        for(int i = 2; i <= n; i++)
            ans += i * m;

        cout << ans << "\n";
    }
}