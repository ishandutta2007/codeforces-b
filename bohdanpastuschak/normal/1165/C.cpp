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
#define ITER(it, a) for(__typeof(a.begin()) it = a.begin(); it != a.end(); ++it)
#define ALL(a) a.begin(), a.end()
#define SZ(a) (int)((a).size())
#define FILL(a, value) memset(a, value, sizeof(a))
#define debug(a) cout << #a << " = " << a << endl;

const double PI = acos(-1.0);
const LL INF = 1e9 + 47;
const LL LINF = INF * INF;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

int main()
{
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	//freopen("In.txt", "r", stdin);
	//freopen("In.txt", "w", stdout);
	
	int n;
	cin >> n;
	string s, ans;
	cin >> s;
		
	for(int i = 0; i < n - 1; ++i)
	{
		int j = i + 1;
		while(j < n && s[j] == s[i])
			++j;
		
		if (j == n)
			break;
		ans += s[i];
		ans += s[j];
		i = j;
	}	
	
	cout << n - SZ(ans) << endl;
	cout << ans << endl;
	
	cerr << "Time elapsed: " << clock() / (double)CLOCKS_PER_SEC << endl;
	return 0;
}