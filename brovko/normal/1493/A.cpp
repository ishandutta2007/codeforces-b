#include <bits/stdc++.h>
#define int long long

using namespace std;

int t, n, k;

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> t;

    while(t--)
    {
        cin >> n >> k;

        cout << n - (k + 1) / 2 << "\n";

        for(int i = (k + 1) / 2; i <= n; i++)
            if(i != k)
                cout << i << ' ';

        cout << "\n";
    }
}