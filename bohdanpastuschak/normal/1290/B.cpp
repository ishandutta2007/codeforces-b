#include <bits/stdc++.h>
using namespace std;
 
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

const int A = 26;
vector<int> cnt[A];

inline bool ye(int l, int r, int id)
{
	auto it = lower_bound(ALL(cnt[id]), l);
	return *it <= r;
}

int main()
{
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	
	string s;
	cin >> s;
	FOR(i, 0, SZ(s)) cnt[s[i] - 'a'].PB(i);
	FOR(i, 0, A) cnt[i].PB(SZ(s));
	
	int q;
	cin >> q;
	while(q--)
	{
		int l, r;
		cin >> l >> r;
		--l; --r;
		if (l == r)
		{
			cout << "Yes\n";
			continue;
		}
		
		int C = 0;
		FOR(i, 0, A) C += ye(l, r, i);
		if (C > 2)
		{
			cout << "Yes\n";
			continue;
		}
		
		if (C == 2 && s[l] != s[r])
		{
			cout << "Yes\n";
			continue;
		}
		
		cout << "No\n";
	}
	
	cerr << "Time elapsed: " << clock() / (double)CLOCKS_PER_SEC << endl;
	return 0;
}