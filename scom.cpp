#include <bits/stdc++.h>
#include <fstream>
using namespace std;
#define ll long long
#define pb push_back
#define mp make_pair
#define ff first
#define ss second
#define bs binary_search
#define vl vector<ll>
#define pll pair<ll,ll>
#define vpl vector<pair<ll,ll> >
#define mll map<ll,ll>
#define mcl map<char,ll>
#define msl map<string,ll>
#define fr(a,b,c) for(ll a=b;a<c;a++)
void in(ll *a,ll n){fr(i,0,n){cin>>a[i];}}
void out(ll *a,ll n){fr(i,0,n){cout<<a[i]<<" ";}}
void fast(){
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}
bool b[8]={false},bi[8]={false},b2[8]={false};
stack<ll> s1;
vl v[8],v7[8],v8[8];
int d=7;
ll to[8];
string s="ABCDEFG";
vpl v2[8],v3[8];
ll dis[8],par[8];
vpl v4,v5,v6[8];stack<ll>sta;

void bfs(ll a){
	if(!b[a]){
		b[a]=true;
		fr(i,0,v7[a].size()){
			bfs(v7[a][i]);
		}
		s1.push(a);
	}
}
void bfs1(ll a){
	if(!b2[a]){
		b2[a]=true;
		fr(i,0,v8[a].size()){
			bfs1(v8[a][i]);
		}
		cout<<s[a-1]<<" ";
	}
}
int main(){
fast();
    
	fr(i,1,8){
		ll a;
		cin>>a;
		fr(j,0,a){
			ll b,c;
			cin>>b>>c;
		    v7[i].pb(b);
		    v8[b].pb(i);
		}
	}
	
	memset(b2,false,sizeof(b2));
	memset(b,false,sizeof(b));
	fr(i,1,8){

		if(!b[i])
			bfs(i);
	}
	cout<<"The strongly connected components of the sixth graph are:\n";
	while(!s1.empty()){
		ll p=s1.top();
		s1.pop();
		if(!b2[p]){
			bfs1(p);
			cout<<"\n";
		}
	}





}
