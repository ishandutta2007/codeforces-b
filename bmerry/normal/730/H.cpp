#include <bits/stdc++.h>
#ifndef ONLINE_JUDGE
# include <sys/time.h>
# include <sys/resource.h>
#endif

/*** TEMPLATE CODE STARTS HERE ***/

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

static void no()
{
    cout << "No\n";
    exit(0);
}

int main(int argc, const char **argv)
{
    redirect(argc, argv);
    int N, M;
    cin >> N >> M;
    vector<string> names(N);
    vector<string> match;
    vector<string> nmatch;
    vector<int> indices(M);
    for (int i = 0; i < N; i++)
        cin >> names[i];
    for (int i = 0; i < M; i++)
    {
        cin >> indices[i];
        indices[i]--;
    }
    for (int i = 0; i < N; i++)
    {
        if (count(RA(indices), i))
            match.push_back(names[i]);
        else
            nmatch.push_back(names[i]);
    }
    int X = SZ(nmatch);
    for (int i = 0; i < M; i++)
        if (SZ(match[i]) != SZ(match[0]))
            no();
    int L = SZ(match[0]);
    string pattern;
    for (int i = 0; i < L; i++)
    {
        char c = match[0][i];
        for (int j = 0; j < M; j++)
            if (match[j][i] != c)
            {
                c = '?';
                break;
            }
        pattern += c;
    }
    for (int i = 0; i < X; i++)
    {
        if (SZ(nmatch[i]) != L)
            continue;
        int fit = 0;
        for (int j = 0; j < L; j++)
            if (pattern[j] == '?' || pattern[j] == nmatch[i][j])
                fit++;
        if (fit == L)
            no();
    }
    cout << "Yes\n" << pattern << '\n';
    return 0;
}