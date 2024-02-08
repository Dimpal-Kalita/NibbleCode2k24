## Nibble Code
Since every bird must receive at least M nibbles of biscuit, NibbleCoder can only satisfy  $ceil(\frac{N}{M})$ birds.
Since by default every programming language returns the floor in divison we can just return $\frac{N}{M}$ as answer.




<details>
    <summary>Code</summary>

```cpp
    #include<bits/stdc++.h>
    using namespace std;
    int main(){
        int n,m;
        cin>>n>>m;
        cout<<n/m<<endl;
        return 0;
    }
```
</details>



## Game on a Tree

### Brute Approach
we can find the junction with the maximum number of tokens from the root, by performing a depth first search from the root junction. Once again, we will have to mark the junctions on the path to the root to become inactive for $K$ minutes. We will do this for each friend.

### Optimal Approach
 A key observation is that the $i^{th}$
 friend will take the same path as the  $(i+k)^{th}$ 
 friend. In addition, the junction selected by each path will always be a leaf (unless there are no apples currently on the tree). To determine the order of the leaves, we can do a depth first search from the root, to determine the depth of each leaf. From there, we can go through the leaves in non-increasing order of depth and follow the parent and mark the junctions as visited, until we reach a vertex that has already been visited. From here, we know that all other vertices on the path to the root have been visited. The order of leaves can be determined by selecting the 
 largest leaves in order, based on the number of vertices it visited for the first time on the path to the root (which can be done in linear time in counting sort, though this was not required). Now, we can determine the answer for each friend.

<details>
    <summary> Code </summary>

```cpp
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
                cout<<ans[i%k]<<endl;
            }else{
                cout<<ans[i]<<endl;
            }
        }
    }
```
</details>

## Prodigy Kid

If you can somehow calculate the $\sum_{j=1}^m \left\lfloor \frac{m}{j} \right\rfloor$
in a time complexity $< O(m)$, the problem transforms into a simple Precalculation problem.

Now the question is: How to calculate this?

The first thing to notice is that when you take the floor, most of the values are repeated, so we can use this to our advantage.

In fact, $\left\lfloor \frac{m}{j} \right\rfloor$ can take at most $2\sqrt{m}$ different values.

**Proof:** 

- If $j \leq \sqrt{m}$, then $\left\lfloor \frac{m}{j} \right\rfloor$ can take at most $\sqrt{m}$ different values.

- If $j> \sqrt{m}$, then $\lfloor \frac{m}{j}\rfloor < \sqrt{m}$, so it also can take at most $\sqrt{m}$ different values.

So, we can differentiate these values by the divisors of $m$ as the value of $\left\lfloor \frac{m}{j} \right\rfloor$ changes when $j$ is a divisor of $m$.

Thus, we can precalculate the value of $\left\lfloor \frac{m}{j} \right\rfloor$ for all the divisors of $m$ and then use this to calculate the sum.

<details>
<summary> Code </summary>

```cpp
ll find(ll n){
     auto calc=[&](ll n,ll x)->ll{
          ll dif=(n/x)-(n/(x+1));
          return dif;
     };
     ll ans=0;
     for(int i=1;i*i<=n;i++){
          ans+=(i*calc(n,i));
          if(n/i!=i){
               ans+=((n/i)*calc(n,n/i));
          }
     }
     return ans;
}

const int N=50000;
vl dp(N+1,0);
void PreCalc(ll n){
     for(int i=1;i<=N;i++){
          dp[i]=find(i)+dp[i-1];
     }
}

void dk(){
     ll k;
     cin>>k;
     ll ind=lower_bound(all(dp),k)-dp.begin();
     if(dp[ind]>k) ind--;
     cout<<ind<<endl;
}
```
</details>
