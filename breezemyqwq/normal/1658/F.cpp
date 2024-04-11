
#include <bits/stdc++.h>

#define fi first
#define se second
#define pc putchar
#define ll long long
#define pb push_back
#define mp make_pair
#define W(p) while(p--)
#define pii pair<int, int>
#define ull unsigned long long
#define all(x) x.begin(), x.end()
#define def(N, K, b) const K N = b;
#define rep(i, b, s) for(int i = (b); i <= (s); ++i)
#define per(i, b, s) for(int i = (b); i >= (s); --i)
#define ios ios::sync_with_stdio(0); cin.tie(0); cout.tie(0)

namespace IO {
    const int SIZE = (1 << 20) + 1;
    char ibuf[SIZE], *iS, *iT, obuf[SIZE], *oS = obuf, *oT = obuf + SIZE - 1;
    char _st[55];
    int _qr = 0;
    inline char gc() {
        return (iS == iT ? iT = (iS = ibuf) + fread(ibuf, 1, SIZE, stdin), (iS == iT ? EOF : *iS++) : *iS++);
    }
    inline void qread() {}
    template<class T1, class ...T2>
    inline void qread(T1 &IEE, T2&... ls) {
        register T1 __ = 0, ___ = 1;
        register char ch;
        while(!isdigit(ch = gc())) ___ = (ch == '-') ? -___ : ___;
        do {
            __ = (__ << 1) + (__ << 3) + (ch ^ 48);
        }while(isdigit(ch = gc()));
        __ *= ___;
        IEE = __;
        qread(ls...);
        return ;
    }
    inline void flush() {
        fwrite(obuf, 1, oS - obuf, stdout);
        oS = obuf;
        return ;
    }
    inline void putc_(char _x) {
        *oS++ = _x;
        if(oS == oT) flush();
    }
    inline void qwrite() {}
    template<class T1, class ...T2>
    inline void qwrite(T1 IEE, T2... ls) {
        if(!IEE) putc_('0');
        if(IEE < 0) putc_('-'), IEE = -IEE;
        while(IEE) _st[++_qr] = IEE % 10 + '0', IEE /= 10;
        while(_qr) putc_(_st[_qr--]);
        qwrite(ls...);
        return ;
    }
    struct Flusher_{ ~Flusher_() { flush(); } } io_flusher;
}

using namespace IO;
using namespace std;

namespace Comb {
	def(SIZ, int, 1.1e6 + 5);
	int p;
	
	ll inv[SIZ], fac[SIZ], Inv[SIZ];
	
	void init(int mod) {
		p = mod;
		inv[0] = fac[0] = Inv[0] = inv[1] = fac[1] = Inv[1] = 1;
		rep(i, 2, SIZ - 1) {
			fac[i] = fac[i - 1] * i % p;
			inv[i] = p - (p / i) * inv[p % i] % p;
			Inv[i] = Inv[i - 1] * inv[i] % p;
		}
	}
	
	ll C(int n, int m) {
		if(n < m || m < 0) return 0;
		return ((fac[n] * Inv[n - m]) % p) * Inv[m] % p;
	}
} using Comb::C;

mt19937_64 rnd(chrono::steady_clock::now().time_since_epoch().count());
ll My_Rand(ll Mod) { return (ull)(rnd()) % Mod; }

template<class T1, class T2>
void To_max(T1 &x, const T2 y) { x < y ? x = y : x = x; }
template<class T1, class T2>
void To_min(T1 &x, const T2 y) { x > y ? x = y : x = x; }

ll qmul(ll x, ll y, ll p) {
	ll l = x * (y >> 25) % p * (1 << 25) % p;
	ll r = x * (y & ((1 << 25) - 1)) % p;
	return (l + r) % p;
}

ll qpow(ll n, ll base, ll mod = 1e18) {
	ll ret = 1;
	while(n) {
		if(n & 1) ret = ret * base % mod;
		base = base * base % mod;
		n >>= 1;
	}
	return ret % mod;
}

ll gcd(ll x, ll y) { return !y ? x : gcd(y, x % y); }
ll lcm(ll x, ll y) { return x / gcd(x, y) * y; }

void InitHash(ull &base, int &prime, ull &mod) { base = 131, prime = 233317, mod = 212370440130137957ll; } 
//header

def(N, int, 2e5 + 5)

int n, m;
int a[N];
int c[2];
int pre[N];

int main() {
	ios;
	int T = 1;
	cin >> T;
	W(T) {
		c[0] = c[1] = 0;
		cin >> n >> m;
		int len = n - m;
		string s; cin >> s;
		rep(i, 1, n) a[i] = (s[i - 1] - '0'), ++c[a[i]];
		rep(i, 1, n) pre[i] = pre[i - 1] + a[i];
		if((1ll * m * c[1]) % n != 0) {
			cout << "-1\n";
			continue;
		}
		int nd = 1ll * m * c[1] / n;
		rep(i, m, n) if(pre[i] - pre[i - m] == nd) {
			cout << "1\n" << i - m + 1 << ' ' << i << '\n';
			goto End;
		}
		rep(i, len, n) {
			if(pre[i] - pre[i - len] == c[1] - nd) {
				cout << "2\n";
				cout << "1 " << i - len << '\n';
				cout << i + 1 << ' ' << n << '\n';
				break;
			}
		}
		End:;
	}
	return 0;
}