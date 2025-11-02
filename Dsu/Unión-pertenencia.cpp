#include <bits/stdc++.h>
using namespace std;

struct Dsu {
  vector<int> par;

  Dsu(int n) : par(n) {
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
    char op;
    int x, y;
    cin >> op >> x >> y;

    if (op == 'P') {
      int px = dsu.find(x);
      int py = dsu.find(y);

      cout << (px == py) << "\n";
    } else {
      dsu.unite(x, y);
    }
  }

  return 0;
}