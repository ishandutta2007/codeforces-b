#include <bits/stdc++.h>

using namespace std;

#define x first
#define y second
#define mp make_pair
#define pb push_back
#define sqr(a) ((a) * (a))
#define sz(a) int(a.size())
#define all(a) a.begin(), a.end()
#define forn(i, n) for(int i = 0; i < int(n); i++)
#define fore(i, l, r) for(int i = int(l); i < int(r); i++)

typedef long long li;
typedef long double ld;
typedef pair<int, int> pt;

template<class A, class B> ostream& operator << (ostream &out, pair<A, B> &a) {
	return out << "(" << a.x << ", " << a.y << ")";
}

template<class A> ostream& operator << (ostream &out, vector<A> &a) {
 	out << "[";
 	forn(i, sz(a)) {
 		if(i) out << ", ";
 		out << a[i];
 	}
 	return out << "]\n";
}

const int INF = int(1e9);
const li INF64 = li(1e18);
const int MOD = INF + 7;
const ld PI = acosl(-1.0);
const ld EPS = 1e-9; 

mt19937 rnd(time(NULL));
mt19937_64 rnd64(time(NULL));

const int N = 100043;

int n, k;

int a[N], dp[N];

bool read() {
 	if(scanf("%d %d", &n, &k) != 2)
 		return false;
 	forn(i, n) scanf("%d", &a[i]);
 	return true;
}

void solve() {
	forn(i, n) a[i]--;
	forn(i, n)
	{
		if (a[i] == -1)
			dp[i] = min(n - 1, i + k) - max(0, i - k) + 1;
		else
		{
			int intersect = max(0, min(n - 1, a[i] + k) - max(0, i - k) + 1);
			dp[i] = min(n - 1, i + k) - max(0, i - k) + 1 + dp[a[i]] - intersect;
		}
	}
	forn(i, n)
		printf("%d ", dp[i]);
	puts("");
}

int main() {
	
#ifdef _DEBUG
	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);
	int tt = clock();
#endif

	srand(time(NULL));
	cout << fixed << setprecision(15);

	while(read()) {

		solve();

#ifdef _DEBUG
		cerr << "TIME = " << clock() - tt << " ms\n";
		tt = clock();
#endif

	}
	
	return 0;
}