#include <bits/stdc++.h>
#define int long long
#define ld long double
#define x first
#define y second
#define pb push_back

using namespace std;

int n, a[100005];

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n;

    for(int i = 0; i < n; i++)
        cin >> a[i];

    sort(a, a + n);

    int s = 0, ans = 0;

    for(int i = 0; i < n; i++)
    {
        if(a[i] >= s)
        {
            ans++;
            s += a[i];
        }
    }

    cout << ans;
}