#include <bits/stdc++.h>
using namespace std;

struct Dsu {
  vector<int> par;
  int cc;

  Dsu(int n) : par(n + 1) {
    cc = n;
    for (int i = 0; i < n; i++)
      par[i] = i;
  }

  int find(int u) {
    return par[u] == u ? u : par[u] = find(par[u]);
  }

  bool unite(int u, int v) {
    u = find(u);
    v = find(v);

    if (u != v) {
      par[v] = u;
      cc--;

      return true;
    }

    return false;
  }
};

int n, m;

int main() {
  cin.tie(0)->sync_with_stdio(0), cout.tie(0);

  cin >> n >> m;

  Dsu dsu(n);
  while (m--) {
    int x, y;
    cin >> x >> y;

    dsu.unite(x, y);
  }

  cout << dsu.cc << "\n";

  return 0;
}