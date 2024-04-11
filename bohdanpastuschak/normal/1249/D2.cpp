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
	
	int n, k;
	cin >> n >> k;
	vector<pair<int, int>> ev;
	vector<pair<int, int>> A(n + 1);
	FOR(i, 1, n + 1) {
		int l, r;
		cin >> l >> r;
		ev.PB({l, -i});
		ev.PB({r, i});
		A[i] = {l, r};
	}
	
	VI ans;
	sort(ALL(ev));
	set<PII> S;
	for(auto e: ev){
		int ja = e.Y;
		if (ja < 0){
			S.insert({A[-ja].Y, -ja});
		}else{
			S.erase({A[ja].Y, ja});
		}		
		
		if (SZ(S) > k){
			auto hto = *S.rbegin();
			S.erase(hto);
			ans.PB(hto.Y);
		}
	}	
	
	cout << SZ(ans) << endl;
	for(auto i: ans){
		cout << i << ' ';
	}
	
	cout << endl;
	
    cerr << "Time elapsed: " << clock() / (double)CLOCKS_PER_SEC << endl;
    return 0;
}