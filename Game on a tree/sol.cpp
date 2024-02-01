#include<bits/stdc++.h>
using namespace std;

#define md                  1000000007
#define pb                  push_back
#define endl                " \n"
#define F                   first
#define S                   second
#define sz(x)               (int)(x).size()   
#define inp(v)              for(auto &x: v) cin>>x  
#define all(x)              (x).begin(), (x).end()
#define rep(i, a, b)        for (int i = a; i < (b); ++i)
#define fast_io             cin.tie(0)->sync_with_stdio(0);cin.exceptions(cin.failbit);

using ll  = long long;
using ull = unsigned long long;
using lld = long double;
using pii = pair<int,int>;
using pll = pair<ll,ll>;
using vl  = vector<ll>;
using vi  = vector<int>;


void dk(){
     ll n,m,k;
     cin>>n>>m>>k;
     vector<vl>adj(n+1);
     rep(i,1,n){
          ll x;
          cin>>x;
          adj[i+1].pb(x);
          adj[x].pb(i+1);
     }
     vector<ll>depth(n+1),par(n+1);
     function<void(ll,ll,ll)>dfs=[&](ll u,ll p,ll d){
          depth[u]=d;
          par[u]=p;
          for(auto v:adj[u]){
               if(v!=p){
                    dfs(v,u,d+1);
               }
          }
     };
     dfs(1,0,1);
     vector<pll>v;
     rep(i,1,n+1){
          if(adj[i].size()==1 and i!=1) v.pb({depth[i],i});
     }
     sort(all(v),greater<pll>());
     vector<ll>ans(n+1),vis(n+1);
     for(auto i:v){
          ll u=i.S;
          ll cnt=0;
          while(u!=0 and !vis[u]){
               cnt++;
               vis[u]=1;
               u=par[u];
          }
          ans[i.S]=cnt;
     }
     sort(all(ans),greater<ll>());
     ans.resize(m+1);
     rep(i,0,m){
          if(i>=k){
               cout<<ans[i%k]<<endl[i==m-1];
          }else{
               cout<<ans[i]<<endl[i==m-1];
          }
     }
}



int main()
{ 
    fast_io;
    string s="18";
    string in="tle/input"+s+".txt";
    string out="tle/output"+s+".txt";
    freopen(in.c_str(),"r+",stdin);
    freopen(out.c_str(),"w+",stdout);
    int _=1;
//     cin>>_;
    for(int i=0;i<_;i++){
    dk();
   }
  return 0;
}   