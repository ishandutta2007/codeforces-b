#include <bits/stdc++.h>
/*
#pragma comment(linker, "/stack:200000000")
#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4")
*/
#define ll long long                   
#define f first 
#define s second 
#define pb push_back               
#define mp make_pair 
#define o cout<<"BUG"<<endl;
#define IOS ios_base::sync_with_stdio(0);

using namespace std;                    

const ll maxn=2e5+123,inf=1e18,mod=1e9+7,N=360360;

int main(){
    #ifdef LOCAL
    //    freopen ("test.in", "r", stdin);
    #endif                                     
    ll a,b,c,n;
    cin>>a>>b>>c>>n;
    if(min(a,b)>=c && n-a-b+c>0)
        cout<<n-a-b+c;
    else
        cout<<-1;
}