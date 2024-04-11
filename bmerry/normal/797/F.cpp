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
#define SZ(x) ((int) (x).size())

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

struct event
{
    ll p;
    int c = -1;

    bool operator<(const event &other) const
    {
        return tie(p, c) < tie(other.p, other.c);
    }
};

static void solve()
{
    int N, M;
    cin >> N >> M;
    vector<event> events(N + M);
    for (int i = 0; i < N; i++)
        cin >> events[i].p;
    for (int i = 0; i < M; i++)
        cin >> events[i + N].p >> events[i + N].c;
    sort(RA(events));

    vector<ll> dpr(2, LLONG_MAX / 2);
    vector<ll> dpl(2, LLONG_MAX / 2);
    dpr[0] = 0;
    for (const auto &e : events)
    {
        if (e.c == -1)
        {
            vector<ll> dp2r(SZ(dpr) + 1, LLONG_MAX / 2);
            vector<ll> dp2l(SZ(dpl), LLONG_MAX / 2);
            for (int i = 0; i < SZ(dpr); i++)
                dp2r[i + 1] = min(dp2r[i + 1], dpr[i] - e.p);
            if (!dpl.empty())
                dp2r[0] = min(dp2r[0], dpl[1] + e.p);
            for (int i = 1; i < SZ(dpl); i++)
                dp2l[i - 1] = min(dp2l[i - 1], dpl[i] + e.p);
            dpr = move(dp2r);
            dpl = move(dp2l);  // TODO: could do in-place
        }
        else
        {
            vector<ll> dp2r(SZ(dpr), LLONG_MAX / 2);
            vector<ll> dp2l(SZ(dpl) + e.c, LLONG_MAX / 2);
            for (int i = 0; i < min(e.c, SZ(dpr)); i++)
                dp2l[e.c - i] = min(dp2l[e.c - i], dpr[i] + i * e.p - (e.c - i) * e.p);
            for (int i = e.c; i < SZ(dpr); i++)
                dp2r[i - e.c] = min(dp2r[i - e.c], dpr[i] + e.c * e.p);
            for (int i = 1; i < SZ(dpl); i++)
                dp2l[e.c + i] = min(dp2l[e.c + i], dpl[i] - e.c * e.p);
            for (int i = SZ(dp2l) - 1; i > 0; i--)
                dp2l[i - 1] = min(dp2l[i - 1], dp2l[i] + e.p);
            dp2r[0] = min(dp2r[0], dp2l[1] + e.p);
            dpr = move(dp2r);
            dpl = move(dp2l);
        }
        while (SZ(dpl) > max(N, 2) + 1)
            dpl.pop_back();
        while (SZ(dpl) > 2 && dpl.back() >= LLONG_MAX / 4)
            dpl.pop_back();
        while (SZ(dpr) > 2 && dpr.back() >= LLONG_MAX / 4)
            dpr.pop_back();
    }
    if (dpr[0] >= LLONG_MAX / 4)
        cout << "-1\n";
    else
        cout << dpr[0] << '\n';
}

int main(int argc, const char **argv)
{
    redirect(argc, argv);
    solve();

    return 0;
}