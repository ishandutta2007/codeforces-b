#include <bits/stdc++.h>
#define int long long
#define ld long double
#define y1 sdopgh

using namespace std;

int n;

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n;
    
    int x = 0;
    
    for(int i = 1; i * i <= n; i++)
        if(n % i == 0)
            x = i;
    
    cout << x << ' ' << n / x;
}