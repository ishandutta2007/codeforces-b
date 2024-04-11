#include<bits/stdc++.h>

using namespace std;

typedef vector<double> vd;
typedef vector<vd> vvd;
typedef vector<vvd> vvvd;
typedef vector<string> vs;
typedef vector<char> vc;
typedef vector<vc> vvc;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef long long ll;
typedef vector<long long> vll;
typedef vector<vll> vvll;
typedef pair<int,int> ii;
typedef vector<ii> vii;
typedef vector<bool> vb;
typedef vector<vb> vvb;
typedef tuple<int,int,int> iii;

#define pb push_back
#define ctz __builtin_ctz
#define pct __builtin_popcount
#define db(x) cerr << #x << "=" << x << endl
#define db2(x, y) cerr << #x << "=" << x << "," << #y << "=" << y << endl
#define db3(x, y, z) cerr << #x << "=" << x << "," << #y << "=" << y << "," << #z << "=" << z << endl
#define all(v) (v).begin(),(v).end()
#define rep(i,n) for(int i=0;i<(n);++i)

int main() {
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int tc;
    cin>>tc;
    while(tc--) {
    	int n;
    	cin>>n;
    	ll a[n],b[n],c[n];
    	rep(i,n) {
    		cin>>a[i]>>b[i];
    	}
    	int j;
    	ll ans=0;
    	rep(i,n) {
    		j=(i+1)%n;
    		c[j]=max(a[j]-b[i],0LL);
    		ans+=c[j];
    	}
    	ll add=1e13;
    	rep(i,n) {
    		add=min(add,a[i]-c[i]);
    	}
    	ans+=add;
    	cout<<ans<<endl;

    }


}