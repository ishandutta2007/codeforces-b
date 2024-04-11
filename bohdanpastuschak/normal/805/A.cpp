#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <set>
#include <list>
#include <map>
#include <queue>
#include <iterator>
#include <iomanip>
#include <stdio.h>
#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <ctime>
#include <utility>
#include <functional>
#include <stack>
#include <deque>
#include <sstream>
using namespace std;

#define infinity (ll)1e15+1
#define PI 3.14159265358979

#define ll long long
#define pdd pair<double,double>
#define pll pair<ll, ll>
#define pii pair<int,int>

#define MP make_pair
#define SZ size()
#define PB push_back

#define vi vector<int>//ll
#define vll vector<ll>
#define vpll vector<pll>
#define vpii vector<pii>
#define vch vector<char>
#define vb vector<bool>

#define FOR(i,a,b) for(ll i = (a); i < (b); ++i)
#define RFOR(i,b,a) for(ll i = (b) - 1; i >= (a); --i)
#define REPEAT(i) FOR(counter1234,0,i)
#define ALL(a) a.begin(), a.end()
#define X first
#define Y second
#define MAXN 100001

bool isP(int n)
{
	if (n == 1) return false;
	if (n == 2 || n == 3) return true;
	for (ll i = 2; i*i <= n; ++i)
		if (n%i == 0)
			return false;
	return true;
}

int main()
{
	ios_base::sync_with_stdio(false);

	ll l, r;
	cin >> l >> r;

	if (l == r)
	{
		if (isP(l))
			cout << l;
		else
		{
			FOR(i,2,l)
				if (l % i == 0)
				{
					cout << i;
					return 0;
				}
		}
	}
	else
		cout << 2;
	
	return 0;
}