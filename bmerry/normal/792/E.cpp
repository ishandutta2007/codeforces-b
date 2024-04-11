//#pragma GCC optimize("O3")
//#pragma GCC target("arch=corei7-avx")
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
typedef vector<int> vi;
typedef vector<ll> vll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

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

static void redirect(int argc, const char **argv)
{
#ifndef ONLINE_JUDGE
    struct rlimit rlim;
    getrlimit(RLIMIT_STACK, &rlim);
    rlim.rlim_cur = 256 * 1024 * 1024;
    setrlimit(RLIMIT_STACK, &rlim);
#ifndef __SANITIZE_ADDRESS__
    getrlimit(RLIMIT_DATA, &rlim);
    rlim.rlim_cur = 256 * 1024 * 1024;
    setrlimit(RLIMIT_DATA, &rlim);
#endif
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
    cin.exceptions(ios::failbit);
}

/*** TEMPLATE CODE ENDS HERE */

static ll sets_of(ll a, ll s)
{
    ll b = (a + s) / (s + 1);
    ll rem = b * (s + 1) - a;
    if (rem > b)
        return -1;
    return b;
}

static void solve()
{
    int N;
    cin >> N;
    vi a(N);
    for (int i = 0; i < N; i++)
        cin >> a[i];

    ll ans = LLONG_MAX;
    for (int i = 1; i <= 32000; i++)
    {
        ll sets = 0;
        for (int j = 0; j < N; j++)
        {
            ll b = sets_of(a[j], i);
            if (b == -1)
                goto bad;
            sets += b;
        }
        ans = min(ans, sets);
bad:;
    }

    vi cand;
    int last = -1;
    for (int i = 1; i <= 32000; i++)
    {
        ll size = a[0] / i;
        if (size != last)
        {
            cand.push_back(size);
            last = size;
        }
        if (size * i == a[0] && size - 1 != last)
        {
            cand.push_back(size - 1);
            last = size - 1;
        }
    }
    for (int size : cand)
    {
        ll sets = 0;
        for (int i = 0; i < N; i++)
        {
            ll b = sets_of(a[i], size);
            if (b == -1)
                goto bad2;
            sets += b;
        }
        ans = min(ans, sets);
bad2:;
    }
    cout << ans << '\n';
}

int main(int argc, const char **argv)
{
    redirect(argc, argv);
    solve();

    return 0;
}