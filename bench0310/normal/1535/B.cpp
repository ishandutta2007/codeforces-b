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
        int n;
        cin >> n;
        vector<int> v[2];
        for(int i=1;i<=n;i++)
        {
            int a;
            cin >> a;
            v[a&1].push_back(a);
        }
        vector<int> a={0};
        for(int b:v[0]) a.push_back(b);
        for(int b:v[1]) a.push_back(b);
        int res=0;
        for(int i=1;i<=n;i++) for(int j=i+1;j<=n;j++) res+=(gcd(a[i],2*a[j])>1);
        cout << res << "\n";
    }
    return 0;
}