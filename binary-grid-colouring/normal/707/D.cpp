#pragma comment(linker, "/STACK:102400000,102400000")
//#include<bits/stdc++.h>
#include<stdio.h>
#include<string.h>
#include<algorithm>
#include<iostream>
#include<cstring>
#include<vector>
#include<map>
#include<cmath>
#include<queue>
#include<set>
#include<stack>
#include <utility>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
#define mst(a) memset(a, 0, sizeof(a))
#define M_P(x,y) make_pair(x,y)  
#define rep(i,j,k) for (int i = j; i <= k; i++)  
#define per(i,j,k) for (int i = j; i >= k; i--)  
#define lson x << 1, l, mid  
#define rson x << 1 | 1, mid + 1, r  
const int lowbit(int x) { return x&-x; }  
const double eps = 1e-8;  
const int INF = 1e9+7; 
const ll inf =(1LL<<62) ;
const int MOD = 1e9 + 7;  
const ll mod = (1LL<<32);
const int N = 101010; 
const int M=100010; 
template <class T1, class T2>inline void getmax(T1 &a, T2 b) {if (b>a)a = b;}  
template <class T1, class T2>inline void getmin(T1 &a, T2 b) {if (b<a)a = b;}
int read(){int v = 0, f = 1;char c =getchar();while( c < 48 || 57 < c ){if(c=='-') f = -1;c = getchar();}while(48 <= c && c <= 57) v = v*10+c-48, c = getchar();return v*f;}

struct bookcase 
{
	int op,x,y;
	int ans;
}q[M];
vector<int> v[M];
bool a[1005][1005];
int sum;
int n,m,Q;
void dfs(int x)
{
	int ok=0;
	if(q[x].op==1 && !a[q[x].x][q[x].y])
	{
		ok=1;
		a[q[x].x][q[x].y]=true;
		sum++;
	}
	else if(q[x].op==2 && a[q[x].x][q[x].y])
	{
		a[q[x].x][q[x].y]=false;
		ok=2;
		sum--;
	}
	else if(q[x].op==3)
	{
		int i=q[x].x;
		ok=3;
		for(int j=1;j<=m;j++)
		{
			if(a[i][j])
			{
				a[i][j]=false;
				sum--;
			}
			else
			{
				a[i][j]=true;
				sum++;
			}
		}
	}
	q[x].ans=sum;
	for(int i=0;i<(int)v[x].size();i++)
	{
		dfs(v[x][i]);
	}
	if(ok==1)
	{
		a[q[x].x][q[x].y]=false;
		sum--;
	}
	else if(ok==2)
	{
		a[q[x].x][q[x].y]=true;
		sum++;
	}
	else if(ok==3)
	{
		int i=q[x].x;
		for(int j=1;j<=m;j++)
		{
			if(a[i][j])
			{
				a[i][j]=false;
				sum--;
			}
			else
			{
				a[i][j]=true;
				sum++;
			}
		}
	}
}
int main()
{
	#ifndef ONLINE_JUDGE
    freopen("in.txt","r",stdin);
    #endif
	n=read(),m=read(),Q=read();
	for(int i=1;i<=Q;i++)
	{
		scanf("%d%d",&q[i].op,&q[i].x);
		if(q[i].op<=2) scanf("%d",&q[i].y);
		if(q[i].op==4) v[q[i].x].push_back(i);
		else v[i-1].push_back(i);
	}
	dfs(0);
	for(int i=1;i<=Q;i++)
	printf("%d\n",q[i].ans);
	return 0;
}