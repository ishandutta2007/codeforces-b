#include <bits/stdc++.h>
using namespace std;
 
#define ll long long
#define mp make_pair
#define pb push_back
#define pii pair <int, int>
#define vi vector<int>

#define FOR(i, a, b) for (int i=a; i<b; i++)
#define F0R(i, a) for (int i=0; i<a; i++)
 
#define f first
#define s second
#define lb lower_bound
#define ub upper_bound
#define endl "\n"
 
const int MOD = 1000000007;
double PI = 4*atan(1);

int main() {
	ios_base::sync_with_stdio(0);cin.tie(0);
	int n,sum=0; cin >> n;
	F0R(i,n) {
		int x; cin >> x;
		sum += x;
	}
	if (n == 1) {
		if (sum == 1) cout << "YES";
		else cout << "NO";
	} else {
		if (sum == (n-1)) cout << "YES";
		else cout << "NO";
	}
	return 0;
}