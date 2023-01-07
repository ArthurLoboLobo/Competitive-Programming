#include<bits/stdc++.h>
using namespace std;

int main() {
    cin >> n >> m;

    for(int i = 1; i <= m; i++) {
        int x,y; cin >> x >> y;
        adj_out[x].pb(y);
        adj_in[y].pb(x);
    }

    for(int w = 1; w <= n; w++) {
        for(auto u : adj)
    }
}