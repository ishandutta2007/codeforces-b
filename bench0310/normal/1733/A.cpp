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
        int n,k;
        cin >> n >> k;
        vector<int> m(k,0);
        for(int i=0;i<n;i++)
        {
            int a;
            cin >> a;
            m[i%k]=max(m[i%k],a);
        }
        ll res=0;
        for(int i=0;i<k;i++) res+=m[i];
        cout << res << "\n";
    }
    return 0;
}