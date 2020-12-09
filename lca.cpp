 #include <bits/stdc++.h>
    #include <iostream>
    #define ll long long

    ll Ceil(ll a, ll b) { return ((a / b) + (a % b != 0)); }
    using namespace std;
    void build_table(vector<ll> adj[], vector<vector<ll> >& par, vector<ll>& depth, int n, int D)
    { //par should be intailized by -1 and sent
        queue<ll> q;

        vector<bool> vis(n + 1, false);
        q.push(1);
        vis[1] = true;
        while (!q.empty()) {
            ll node = q.front();
            q.pop();

            for (auto neigh : adj[node]) {
                if (!vis[neigh]) {
                    vis[neigh] = true;
                    depth[neigh] = depth[node] + 1;
                    par[neigh][0] = node;
                    q.push(neigh);
                }
            }
        }

        for (int d = 1; d <= D; d++) {
          for (int i = 1; i <= n; i++) {
            ll mid = par[i][d - 1];
            if (mid != -1) {
              par[i][d]=par[mid][d-1];
            }
          }
        }
    }
    ll walk(ll i, ll k, ll D, vector<vector<ll> >& par) //d=log2(n)
    {
        for (int j = D; j>=0;j--)
          if ((k & (1ll << j)) > 0)
            i = par[i][j];
        
            return i;
    }
    ll lca(ll i, ll j, vector<vector<ll> >& par, vector<ll>& depth, ll D)
    {
        if (depth[i] > depth[j]) {
            i = walk(i, depth[i] - depth[j], D, par); //make their depth equal
        }
        if (depth[j] > depth[i]) {
            j = walk(j, depth[j] - depth[i], D, par);
        }
        if (i == j)
            return i;
        
            for (int d = D; d >= 0; d--) {
                if (par[i][d] != par[j][d]) {
                    i = par[i][d];                    //i is a node just less than lca
                    j = par[j][d];
                }
            }

            return par[i][0];
        
    }
    ll distance(ll i, ll j, vector<vector<ll> >& par, vector<ll>& depth, ll D)
    {

        return depth[i] + depth[j] - 2 * (depth[lca(i, j, par, depth, D)]);
    }

    int main()
    {

        ll n;
        cin >> n;
        vector<ll> adj[n + 1];
        for (int i = 1; i <= n - 1; i++) {
            ll a, b;
            cin >> a >> b;
        
            adj[a].push_back(b);
            adj[b].push_back(a);
        }
        ll D = log2(n);
        vector<vector<ll> > par(n + 1, vector<ll>(D + 1, -1)); //intialized by -1
        vector<ll> depth(n + 1);
        build_table(adj, par, depth, n, D);
        //distance(i, j, par, depth, D)
 
        
    }
