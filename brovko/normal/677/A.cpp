#include <bits/stdc++.h>
#define int long long
#define ld long double
#define y1 eohfweoifhew
#define y0 wepfjwewpjfef

using namespace std;

int n, h, a[1005];

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> h;

    for(int i = 0; i < n; i++)
        cin >> a[i];

    int ans = n;

    for(int i = 0; i < n; i++)
        if(a[i] > h)
            ans++;

    cout << ans;
}