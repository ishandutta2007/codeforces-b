#include <bits/stdc++.h>
#define int long long
#define ld long double
#define x first
#define y second
#define pb push_back

using namespace std;

int t;

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> t;

    while(t--)
    {
        int s, n, k;
        cin >> s >> n >> k;

        if(s == k)
            cout << "YES\n";
        else
        if(k > n || s - n >= n / k * k)
            cout << "NO\n";
        else cout << "YES\n";
    }
}