#include <bits/stdc++.h>
using namespace std;

//#pragma GCC optimize("Ofast,unroll-loops")
//#pragma GCC target("avx,avx2,fma")

typedef long long LL;
typedef pair<int, int> PII;
typedef vector<int> VI;
#define MP make_pair
#define PB push_back
#define X first
#define Y second

#define FOR(i, a, b) for(int i = (a); i < (b); ++i)
#define RFOR(i, b, a) for(int i = (b) - 1; i >= (a); --i)
#define ALL(a) a.begin(), a.end()
#define SZ(a) (int)((a).size())
#define FILL(a, value) memset(a, value, sizeof(a))
#define debug(a) cerr << #a << " = " << a << endl;

template<typename T> void setmax(T& x, T y) {x = max(x, y);}
template<typename T> void setmin(T& x, T y) {x = min(x, y);}

const double PI = acos(-1.0);
const LL INF = 1e9 + 47;
const LL LINF = INF * INF;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

int main()
{
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	
	int t;
	cin >> t;
	while(t--){
		string s;
		cin >> s;
		int n = SZ(s);		
		int ans = INF;
		vector<int> pref(n, 0);
		pref[0] = s[0] == '0';
		FOR(i, 1, n) pref[i] = pref[i - 1] + (s[i] == '0');
		
		setmin(ans, pref.back());
		setmin(ans, n - pref.back());
		
		FOR(i, 0, n - 1){
			int curr = 0;
			curr += i + 1 - pref[i];//1
			curr += pref.back() - pref[i];//0
			setmin(ans, curr);
			
			curr = 0;
			curr += pref[i];//0
			curr += n - i - 1 - (pref.back() - pref[i]);//1			
			setmin(ans, curr);
		}
		
		cout << ans << endl;
	}
	
    cerr << "Time elapsed: " << clock() / (double)CLOCKS_PER_SEC << endl;
    return 0;
}