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
ofstream fout;
bool b[8]={false},bi[8]={false},b2[8]={false};
stack<ll> s1;
vl v[8],v7[8],v8[8];
int d=7;
ll to[8];
string s="ABCDEFG";
vpl v2[8],v3[8];
ll dis[8],par[8];
vpl v4,v5,v6[8];
void toposort(int i){
	if(!b[i]){
		b[i]=true;
		fr(j,0,v[i].size()){
			toposort(v[i][j]);
		}
		to[i]=d;
		d--;
	}
}
ll cost=0;
ll val[8][8];
void dijkstra(){
	fr(t,0,6){
		ll mini=INT_MAX,k;
		fr(i,1,8){
			if(mini>dis[i]&&!b[i]){
				mini=dis[i];
				k=i;
			}
		}
		b[k]=true;
		fr(i,0,v2[k].size()){
			dis[v2[k][i].ff]=min((dis[k]+v2[k][i].ss),dis[v2[k][i].ff]);
		}
	}
}
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
void check(ll a,ll c){
	b[c]=true;
	if(!b[a]){
		b[a]=true;
		fr(i,0,v6[a].size()){
			if(v6[a][i].ff!=c){
				check(v6[a][i].ff,c);
			}
		}
	}

}
void atri(int a){
	if(!b2[a]){
		b2[a]=true;
		if(v6[a].size()>1){
			memset(b,false,sizeof(b));
			check(v6[a][0].ff,a);
			ll flag=0;
			fr(i,1,8){

				if(!b[i]){
					flag=1;
				}
			}
			if(flag==1){
				fout<<s[a-1]<<"\n";
			}
		}
		fr(i,0,v6[a].size()){
			atri(v6[a][i].ff);
		}
	}
}
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
		fout<<s[a-1]<<" ";
	}
}
int main(){
	fast();

	fout.open("some.txt");
	fout<<"First graph:";
	fr(i,1,8){
		ll a;
		cin>>a;
		fr(j,0,a){
			ll b,c;
			cin>>b>>c;
		    v[i].pb(b);
		}
	}
	fr(i,1,8){
		if(!b[i])
		toposort(i);
	}
	fout<<"\n";
	fr(i,0,19){
		fout<<"_";
	}

	fout<<"\n| VERTEX | NUMBER |\n";

	vpl v1;
	fr(i,1,8){
		v1.pb(mp(to[i],i));
	}
	fr(i,0,19){
		fout<<"_";
	}
	sort(v1.begin(),v1.end());
	for(int i=0;i<7;i++){
		v1[i].ss--;
		fout<<"\n|   "<<s[v1[i].ss]<<"    |   "<<v1[i].ff<<"    |\n";
	    fr(i,0,19){
			fout<<"_";
		}
	}
	fout<<"\nSecond graph:\n";
	memset(b,false,sizeof(b));
	fr(i,1,8){
		ll a;
		cin>>a;
		fr(j,0,a){
			ll b,c;
			cin>>b>>c;
		    v2[i].pb(mp(b,c));
		}
	}
	fr(i,1,8){
		dis[i]=INT_MAX;
	}
	dis[1]=0;
	dijkstra();
	fout<<"shortest path for graph:\n";
    fr(i,1,8){

		fout<<"Shortest path from  A to "<<s[i-1]<<" A(Distance="<<dis[i]<<")\n";
	}
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
	fout<<"The edges in the minimum spanning tree for the third graph are:\n";
	dis[1]=0;
	v4[1].ff=0;
	mst();
	fr(i,0,v5.size()){
		fout<<"("<<s[v5[i].ff-1]<<","<<s[v5[i].ss-1]<<") ";
	}
	fout<<"\nits cost is= "<<cost;
	fr(i,1,8){
		ll a;
		cin>>a;
		fr(j,0,a){
			ll b,c;
			cin>>b>>c;
		    v6[i].pb(mp(b,c));
		}
	}
	ll so;
	cin>>so;
	fout<<"\n";
	fout<<"For the fourth graph, the articulation points are:\n";
	atri(so);
	memset(b2,false,sizeof(b2));
	fr(i,1,8){
		ll a;
		cin>>a;
		fr(j,0,a){
			ll b,c;
			cin>>b>>c;
		    v6[i].pb(mp(b,c));
		}
	}

	cin>>so;

	fout<<"\n";
	fout<<"For the fifth graph, the articulation points are:\n";
	atri(so);

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
	fout<<"The strongly connected components of the sixth graph are:\n";
	while(!s1.empty()){
		ll p=s1.top();
		s1.pop();
		if(!b2[p]){
			bfs1(p);
			fout<<"\n";
		}
	}
}
