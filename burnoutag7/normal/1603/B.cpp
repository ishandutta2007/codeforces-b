#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

void mian(){
    ll x,y;
    cin>>x>>y;
    if(y<x)cout<<x+y<<'\n';
    else cout<<y-y%x/2<<'\n';
}

int main(){

    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int T;
    cin>>T;
    while(T--)mian();

    return 0;
}