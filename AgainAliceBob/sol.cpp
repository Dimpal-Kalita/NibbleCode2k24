/**
 * 
 * author: Dimpal Kalita
 * date: 28/01/2024 13:24:31
 * 
 */

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
      ll n,x;cin>>n>>x;
      vl v(n);
      rep(i,0,n){
        cin>>v[i];
      }
      sort(all(v));
      multiset<ll>st;
      int ans=0;
      for( int i=0,j=0;i<n;i++){
        st.insert(v[i]);
        while(j<i and (*st.rbegin())-(*st.begin())>2*x){
          //cout<<i<<" "<<" "<<j<<" >"<<(*st.rbegin())-(*st.begin())<<endl;
          st.erase(st.find(v[j]));
          j++;
        }
        ans=max(ans,i-j+1);
      }
      cout<<ans<<endl;
}



int main()
{ 
    fast_io;
    string x="10";
    string in="TLE/input"+x+".txt";
    string out="TLE/output"+x+".txt";
    freopen(in.c_str(),"r+",stdin); 
    freopen(out.c_str(),"w+",stdout); 
    int n=1;
    cin>>n;
    for(int i=0;i<n;i++){
    dk();
   }
  return 0;
}