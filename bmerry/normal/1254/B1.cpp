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

template<class T> T gcd(T a, T b) { return b ? gcd(b, a % b) : a; }

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

// Generate all primes up to and including n
static std::vector<int> sieve(int n)
{
    std::vector<bool> comp(n + 1);
    std::vector<int> out;
    for (int i = 2; i <= n; i++)
    {
        if (!comp[i])
        {
            out.push_back(i);
            for (int j = 2 * i; j <= n; j += i)
                comp[j] = true;
        }
    }
    return out;
}

int main(int argc, const char **argv)
{
    redirect(argc, argv);
    int N;
    cin >> N;
    vll s(N + 1);
    for (int i = 0; i < N; i++)
    {
        int a;
        cin >> a;
        s[i + 1] = s[i] + a;
    }

    auto primes = sieve(1000000);
    vll factors;
    for (int p : primes)
        if (s[N] % p == 0)
        {
            factors.push_back(p);
            factors.push_back(s[N] / p);
        }
    factors.push_back(s[N]);

    ll best = LLONG_MAX;
    for (ll f : factors)
    {
        if (f <= 1)
            continue;
        ll cost = 0;
        for (int i = 1; i < N; i++)
        {
            ll diff = s[i] % f;
            cost += min(diff, f - diff);
        }
        best = min(best, cost);
    }
    if (best == LLONG_MAX)
        best = -1;
    cout << best << '\n';

    return 0;
}