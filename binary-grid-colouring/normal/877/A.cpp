#pragma comment(linker, "/STACK:102400000,102400000")
#include <bits/stdc++.h>
using namespace std;
//#pragma GCC optimize ("O3")
typedef long long ll;
const int lowbit(int x) { return x&-x; }
int read(){ int v = 0, f = 1;char c =getchar();
while( c < 48 || 57 < c ){if(c=='-') f = -1;c = getchar();}
while(48 <= c && c <= 57) v = v*10+c-48, c = getchar();
return v*f;}
/*
ios::sync_with_stdio(0);
cin.tie(0);
*/
/***************************timer******************************/
struct timer
{
   double t;
   timer() { t=clock(); }
   ~timer() { printf("\nruntime %.3f s\n", get_time()); }
   double get_time() { return (clock()-t)/CLOCKS_PER_SEC; }
};
/*************************************************************/
string a[] = {"Danil", "Olya", "Slava", "Ann", "Nikita"};
int main()
{
	string s;
	cin>>s;
	int cnt = 0;
	for(int i=0;i<5;i++)
	{
		for(int j=0;j+a[i].size()<=s.size();j++)
		{
			if(a[i]==s.substr(j,a[i].size()))
			{
				cnt++;
			}
		 } 
	 }
	 if(cnt==1)puts("YES");
	 else puts("NO"); 
	return 0;
}