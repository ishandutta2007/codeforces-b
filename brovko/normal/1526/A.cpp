#include <bits/stdc++.h>
#define int long long
#define ld long double
#define x first
#define y second
#define mp make_pair
#define pb push_back
#define y1 jgpjewgjepg

using namespace std;

int t, n, a[100005];

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> t;

    while(t--)
    {
        cin >> n;
        n *= 2;

        for(int i = 0; i < n; i++)
            cin >> a[i];

        sort(a, a + n);

        for(int i = 0; i < n; i++)
        {
            if(i % 2 == 0)
                cout << a[i / 2] << ' ';
            else cout << a[n - 1 - i / 2] << ' ';
        }

        cout << "\n";
    }
}