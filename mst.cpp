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
ll dis[8];
vpl v2[8],v3[8];
vpl v4,v5,v6[8];	
void mst(){
    fr(t,0,7){
		ll mini=INT_MAX,k;
		fr(i,1,8){
			if((mini>dis[i])&&(!bi[i])){
				k=i;
				mini=dis[i];
			}
		}
		bi[k]=true;

		if(k!=1){
			cost+=val[v4[k].ss][k];
		    v5.pb(mp(v4[k].ss,k));
		}
		fr(i,0,v3[k].size()){
			if(v3[k][i].ss<dis[v3[k][i].ff]){
				dis[v3[k][i].ff]=v3[k][i].ss;
				v4[v3[k][i].ff]=mp(dis[i],k);
			}
		}

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
		    v3[i].pb(mp(b,c));
		    val[i][b]=c;
		}
	}
	v4.pb(mp(0,0));

	fr(i,1,8){
		dis[i]=INT_MAX;
		v4.pb(mp(dis[i],i));

	}
	memset(b,false,sizeof(b));
	cout<<"The edges in the minimum spanning tree for the third graph are:\n";
	dis[1]=0;
	v4[1].ff=0;
	mst();
	fr(i,0,v5.size()){
		cout<<"("<<s[v5[i].ff-1]<<","<<s[v5[i].ss-1]<<") ";
	}
	cout<<"\nits cost is= "<<cost;





}
