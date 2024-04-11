// writer: w33z8kqrqk8zzzx33
#include <bits/stdc++.h>
using namespace std;

// begin fast read template by CYJian (source: https://www.luogu.com.cn/paste/i11c3ppx)

namespace io {
	const int __SIZE = (1 << 21) + 1;
	char ibuf[__SIZE], *iS, *iT, obuf[__SIZE], *oS = obuf, *oT = oS + __SIZE - 1, __c, qu[55]; int __f, qr, _eof;
	#define Gc() (iS == iT ? (iT = (iS = ibuf) + fread (ibuf, 1, __SIZE, stdin), (iS == iT ? EOF : *iS ++)) : *iS ++)
	inline void flush () { fwrite (obuf, 1, oS - obuf, stdout), oS = obuf; }
	inline void gc (char &x) { x = Gc(); }
	inline void pc (char x) { *oS ++ = x; if (oS == oT) flush (); }
	inline void pstr (const char *s) { int __len = strlen(s); for (__f = 0; __f < __len; ++__f) pc (s[__f]); }
	inline void gstr (char *s) { for(__c = Gc(); __c < 32 || __c > 126 || __c == ' ';)  __c = Gc();
		for(; __c > 31 && __c < 127 && __c != ' '; ++s, __c = Gc()) *s = __c; *s = 0; }
	template <class I> inline bool gi (I &x) { _eof = 0;
		for (__f = 1, __c = Gc(); (__c < '0' || __c > '9') && !_eof; __c = Gc()) { if (__c == '-') __f = -1; _eof |= __c == EOF; }
		for (x = 0; __c <= '9' && __c >= '0' && !_eof; __c = Gc()) x = x * 10 + (__c & 15), _eof |= __c == EOF; x *= __f; return !_eof; }
	template <class I> inline void print (I x) { if (!x) pc ('0'); if (x < 0) pc ('-'), x = -x;
		while (x) qu[++ qr] = x % 10 + '0',  x /= 10; while (qr) pc (qu[qr --]); }
	struct Flusher_ {~Flusher_(){flush();}}io_flusher_;
} using io::pc; using io::gc; using io::pstr; using io::gstr; using io::gi; using io::print;

// end fast read template by CYJian

#define iter(i, a, b) for(int i=(a); i<(b); i++)
#define rep(i, a) iter(i, 0, a)
#define rep1(i, a) iter(i, 1, (a)+1)
#define log(a) cerr<<"\033[32m[DEBUG] "<<#a<<'='<<(a)<<" @ line "<<__LINE__<<"\033[0m"<<endl
#define all(a) a.begin(), a.end()
#define fi first
#define se second
#define pb push_back
#define mp make_pair
 
using ll=long long;
using pii=pair<int, int>;
//#define int ll
const int MOD = 1000000007;

static char buf[240 << 20];
void* operator new(size_t s) {
	static size_t i = sizeof buf;
	assert(s < i);
	return (void*)&buf[i -= s];
}
void operator delete(void*) {}

template<class T> struct ptr {
	unsigned ind;
	ptr(T* p = 0) : ind(p ? unsigned((char*)p - buf) : 0) {
		assert(ind < sizeof buf);
	}
	T& operator*() const { return *(T*)(buf + ind); }
	T* operator->() const { return &**this; }
	T& operator[](int a) const { return (&**this)[a]; }
	explicit operator bool() const { return ind; }
};

struct Node {
	ptr<Node> l = 0, r = 0;
	int lo, hi, tag = 0, imin = 0;
	Node(int lo,int hi):lo(lo),hi(hi){} // Large interval of -inf
	int query(int L, int R) {
		if (R <= lo || hi <= L) return 1000000006;
		if (L <= lo && hi <= R) return imin;
		push();
		return min(l->query(L, R), r->query(L, R));
	}
	int query(int i) { return query(i, i+1); }
	void imaxify(int L, int R, int v) {
		if (R <= lo || hi <= L) return;
		if (L <= lo && hi <= R) {
			tag = max(tag, v);
			imin = max(imin, v);
		}
		else {
			push(), l->imaxify(L, R, v), r->imaxify(L, R, v);
			imin = min(l->imin, r->imin);
		}
	}
	void push() {
		if (!l) {
			int mid = lo + (hi - lo)/2;
			l = new Node(lo, mid); r = new Node(mid, hi);
		}
		if (tag)
			l->imaxify(lo,hi,tag), r->imaxify(lo,hi,tag), tag = 0;
	}
};

char Buf[5];

signed main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
	int N, q; gi(N), gi(q);
    Node hori(0, N+3);
	Node vert(0, N+3);
	set<int> ah, av;
	while(q--) {
		int n, m; gi(n), gi(m), gstr(Buf);
		if(Buf[0] == 'L') { // hori, determiner = m
			if(ah.find(m) != ah.end()) { pstr("0\n"); continue; }
			ah.insert(m);
			int hit = vert.query(m);
			print(n - hit); pc('\n');
			hori.imaxify(hit+1, n+1, m);
		} else {
			if(av.find(n) != av.end()) { pstr("0\n"); continue; }
			av.insert(n);
			int hit = hori.query(n);
			print(m - hit); pc('\n');
			vert.imaxify(hit+1, m+1, n);
		}
	}
}