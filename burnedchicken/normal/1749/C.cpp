#include <bits/stdc++.h>
using namespace std;

#define rep(i,a,b) for(int i=a; i<(b); ++i)
#define per(i,a,b) for(int i=a; i>=(b); --i)
#define ll long long
#define int ll
#define all(a) a.begin(),a.end()
#define pii pair<int,int>
#define inf 0x3f3f3f3f
#define pb push_back
#define sz(a) ((int)a.size())
#ifdef i_am_noob
#define bug(...) cerr << "#" << __LINE__ << ' ' << #__VA_ARGS__ << "- ", _do(__VA_ARGS__)
template<typename T> void _do(T && x) {cerr << x << endl;}
template<typename T, typename ...S> void _do(T && x, S&&...y) {cerr << x << ", "; _do(y...);}
#else
#define bug(...) 777771449
#endif

const int maxn=200005,mod=998244353;

int n,a[maxn];

signed main(){
    ios_base::sync_with_stdio(0),cin.tie(0);
    int t;
    cin >> t;
    while(t--){
        cin >> n;
        rep(i,0,n) cin >> a[i];
        sort(a,a+n,greater<int>());
        int res=0;
        rep(j,1,n+1){
            int cur=j;
            rep(i,0,n-j+1) if(a[i]<=cur) cur--;
            if(cur==0) res=j;
        }
        cout << res << "\n";
    }
}