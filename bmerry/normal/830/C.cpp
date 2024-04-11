#include <bits/stdc++.h>
#ifndef ONLINE_JUDGE
# include <sys/time.h>
# include <sys/resource.h>
#endif

/*** TEMPLATE CODE STARTS HERE ***/

#ifndef M_PI
#define M_PI 3.1415926535897932384626433832795028841971693993751
#endif

using namespace std;

typedef vector<string> vs;
typedef long long ll;
typedef complex<double> pnt;
typedef vector<ll> vi;
typedef pair<ll, ll> pii;

#define RA(x) begin(x), end(x)
#define FE(i, x) for (auto i = begin(x); i != end(x); ++i)
#define SZ(x) ((ll) (x).size())

template<class T>
void splitstr(const string &s, vector<T> &out)
{
    istringstream in(s);
    out.clear();
    copy(istream_iterator<T>(in), istream_iterator<T>(), back_inserter(out));
}

template<class T> T gcd(T a, T b) { return b ? gcd(b, a % b) : a; }

static void redirect(int argc, const char **argv)
{
#ifndef ONLINE_JUDGE
    struct rlimit rlim;
    getrlimit(RLIMIT_STACK, &rlim);
    rlim.rlim_cur = 256 * 1024 * 1024;
    setrlimit(RLIMIT_STACK, &rlim);
    getrlimit(RLIMIT_DATA, &rlim);
    rlim.rlim_cur = 256 * 1024 * 1024;
    setrlimit(RLIMIT_DATA, &rlim);
#endif

    ios::sync_with_stdio(false);
    cin.tie(NULL);
    if (argc > 1)
    {
        static filebuf f;
        f.open(argv[1], ios::in);
        cin.rdbuf(&f);
        if (!cin)
        {
            cerr << "Failed to open '" << argv[1] << "'" << endl;
            exit(1);
        }
    }

    if (argc > 2)
    {
        static filebuf f;
        f.open(argv[2], ios::out | ios::trunc);
        cout.rdbuf(&f);
        if (!cout)
        {
            cerr << "Failed to open '" << argv[2] << "'" << endl;
        }
    }
}

/*** TEMPLATE CODE ENDS HERE */

struct pqitem
{
    ll i;
    ll d;

    bool operator<(const pqitem &other) const
    {
        return d > other.d;
    }
};

static ll divup(ll a, ll b)
{
    return (a + b - 1) / b;
}

int main(int argc, const char **argv)
{
    redirect(argc, argv);
    ll N, k;
    cin >> N >> k;
    vector<ll> a(N);
    for (int i = 0; i < N; i++)
        cin >> a[i];
    vector<ll> r(N);
    ll m = 0;
    ll c = accumulate(RA(a), 0LL);
    priority_queue<pqitem> q;
    for (int i = 0; i < N; i++)
        q.push(pqitem{i, 1});
    ll ans = 1;
    while (!q.empty())
    {
        ll d0 = q.top().d;
        while (!q.empty() && q.top().d == d0)
        {
            ll i = q.top().i;
            q.pop();
            ll nr = divup(a[i], d0);
            m += nr - r[i];
            r[i] = nr;
            if (nr > 1)
                q.push(pqitem{i, divup(a[i], nr - 1)});
        }
        ll d = (c + k) / m;
        if (d >= d0)
            ans = max(ans, d);
    }
    cout << ans << '\n';

    return 0;
}