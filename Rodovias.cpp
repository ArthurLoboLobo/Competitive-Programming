#include<bits/stdc++.h>
using namespace std;

int n, m, has[200010];
vector<int> adj_out[200010];

int main() {
    cin >> n >> m;

    for(int i = 1; i <= m; i++) {
        int x,y; cin >> x >> y;
        adj_out[x].push_back(y);
    }

    for(int u = 1; u <= n; u++) {
        for(auto x : adj_out[u]) {
            has[x] = 1;
        }

        for(auto w : adj_out[u]) {
            // u -> w existe
            for(auto v : adj_out[w]) {
                // w -> v existe
                if(has[v] == 0 && u != v) {
                    // u -> v não existe, então encontramos uma reposta
                    cout << u << " " << v << endl;
                    return 0;
                }
            }
        }

        for(auto x : adj_out[u]) {
            has[x] = 0;
        }
    }
    cout << -1 << endl;
}
