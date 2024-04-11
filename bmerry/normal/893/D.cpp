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
}

/*** TEMPLATE CODE ENDS HERE */

struct impossible {};

int main(int argc, const char **argv)
{
    redirect(argc, argv);
    int N;
    ll D;
    cin >> N >> D;
    vector<ll> a(N);
    vector<ll> s(N + 1);
    vector<ll> c(N + 1);
    for (int i = 0; i < N; i++)
        cin >> a[i];
    partial_sum(RA(a), s.begin() + 1);
    c[N] = s[N];
    for (int i = N - 1; i >= 0; i--)
        c[i] = max(s[i], c[i + 1]);

    try
    {
        if (c[0] > D)
            throw impossible();

        int ans = 0;
        ll B = 0;

        for (int i = 0; i < N; i++)
        {
            if (a[i] == 0 && B < 0)
            {
                ans++;
                ll top = D - (c[i] - s[i]);
                if (top < 0)
                    throw impossible();
                B = top;
            }
            B += a[i];
        }
        cout << ans << "\n";
    }
    catch (impossible)
    {
        cout << "-1\n";
    }

    return 0;
}