#include<bits/stdc++.h>
#define ff first
#define ss second
#define mp make_pair
#define INF INT_MAX
using namespace std;

void short1(int s,vector<pair<long long int,long long int>>ar[],long long int dis[],bool vis[])
{
    
    class prioritize{public: bool operator ()(pair<int,long long int>&p1 ,pair<int,long long int>&p2){return p1.second>p2.second;}};
    priority_queue<pair<int,long long int> ,vector<pair<int,long long int> >, prioritize> pq;
    pq.push(mp(s,dis[s-1]=0));
        while(!pq.empty())
        {
            
            pair<int,long long int> x=pq.top();
            pq.pop();
            int v=x.ff;
            long long int w=x.ss;
           
            if(vis[v-1]==false)
            {
                vis[v-1]=true;
                for(int i=0;i<ar[v-1].size();i++)
                {
                    if(!vis[ar[v-1][i].ff-1]&&ar[v-1][i].ss+w<dis[ar[v-1][i].ff-1])
                    {
                        
                        dis[ar[v-1][i].ff-1]=ar[v-1][i].ss+w;
                        pq.push(mp(ar[v-1][i].ff,dis[ar[v-1][i].ff-1]));
                    }
                }
            }
        }
}
int main()
{
    
    int t;cin>>t;
    while(t--)
    {
     long long int dis[3001];
bool vis[3001];
    for(int i=0;i<3001;i++)
    {
        vis[i]=false;
        
    }
        for(int i=0;i<3001;i++)
    dis[i]=INF;
    long long int n,m,w,x,y;
    cin>>n>>m;vector<pair<long long int,long long int>>ar[n];
    for(long long int i=0;i<m;i++)
    {
        cin>>x>>y>>w;
        ar[x-1].push_back(mp(y,w));
        ar[y-1].push_back(mp(x,w));
    }
    int s;
    cin>>s;
    short1(s,ar,dis,vis);
    for(int i=0;i<n;i++)
    {
        if(i!=s-1)
       dis[i]!=INF? cout<<dis[i]<<" " : cout<<"-1 "; 
        
    }
         cout<<"\n";
    }
   
    return 0;
}




