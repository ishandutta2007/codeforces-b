#include <bits/stdc++.h>
#define ll long long
#define ld long double
#define pb push_back
#define mp make_pair
#define ss(x) (int) x.size()
#define fi first
#define se second
#define cat(x) cerr << #x << " = " << x << endl
#define rep(i, j, n) for (int i = j; i <= n; ++i)
#define per(i, j, n) for (int i = n; j <= i; --i)
#define all(x) x.begin(), x.end()
 
using namespace std;	

int main() {
	int T, n;
	scanf ("%d", &T);
	while (T--) {
		scanf ("%d", &n);
		printf ("%d\n", (n + 1) / 2);
	}
	
	return 0;
}