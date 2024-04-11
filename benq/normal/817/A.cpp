/*#include <ext/pb_ds/assoc_container.hpp> 
#include <ext/pb_ds/tree_policy.hpp>*/
#include <bits/stdc++.h>

using namespace std;
//using namespace __gnu_pbds;
 
typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> pii;
//typedef tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update> ordered_set;

#define FOR(i, a, b) for (int i=a; i<b; i++)
#define F0R(i, a) for (int i=0; i<a; i++)
#define FORd(i,a,b) for (int i = (b)-1; i >= a; i--)
#define F0Rd(i,a) for (int i = (a)-1; i >= 0; i--)
 
#define mp make_pair
#define pb push_back
#define f first
#define s second
#define lb lower_bound
#define ub upper_bound

const int MOD = 1000000007;
double PI = 4*atan(1);

int main() {
	ios_base::sync_with_stdio(0);cin.tie(0);
	int x1,y1,x2,y2; cin >> x1 >> y1 >> x2 >> y2;
	int x,y; cin >> x >> y;
	x1 = abs(x1-x2), y1 = abs(y1-y2);
	if (x1 % x != 0 || y1 % y != 0) {
		cout << "NO";
		return 0;
	}
	x1 /= x, y1 /= y;
	if ((x1 % 2) != (y1 % 2)) cout << "NO";
	else cout << "YES";
}