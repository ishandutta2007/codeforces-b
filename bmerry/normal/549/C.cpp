// WRONG ANSWER

#include <bits/stdc++.h>

/*** TEMPLATE CODE STARTS HERE ***/

using namespace std;

typedef vector<int> vi;
typedef vector<string> vs;
typedef long long ll;
typedef complex<double> pnt;
typedef pair<int, int> pii;

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

template<class T> T gcd(T a, T b) { return b ? gcd(b, a % b) : a; }

static void redirect(int argc, const char **argv)
{
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

int main(int argc, const char **argv)
{
    redirect(argc, argv);
    int N, K;
    cin >> N >> K;
    int odd = 0;
    for (int i = 0; i < N; i++)
    {
        int x;
        cin >> x;
        odd += x & 1;
    }
    const string names[] = {"Stannis", "Daenerys"};
    int winner;
    if (N == K)
    {
        winner = !(odd & 1);
    }
    else
    {
        int last = (N + 1 - K) & 1;
        int turns = (N - K) / 2;
        bool upset = false;
        if (last == 0 && odd <= turns)
            upset = true;
        if (N - odd <= turns && (K & 1) == last)
            upset = true;
        winner = upset ? !last : last;
    }
    cout << names[winner] << '\n';
    return 0;
}