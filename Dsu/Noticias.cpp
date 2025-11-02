#include <bits/stdc++.h>
using namespace std;

struct Dsu {
  vector<int> par, size;
  vector<int> mnIndex;
  vector<vector<int>> group;
  int cc;

  Dsu(int n) : par(n + 1), size(n + 1), mnIndex(n + 1), group(n + 1) {
    cc = n;
    for (int i = 0; i <= n; i++) {
      par[i] = i;
      mnIndex[i] = i;
      group[i] = {i};
      size[i] = 1;
    }
  }

  int find(int u) {
    return par[u] == u ? u : par[u] = find(par[u]);
  }

  bool unite(int u, int v) {
    u = find(u);
    v = find(v);

    if (u != v) {
      // u es el lider
      par[v] = u;
      // el lider es el que va a tener toda la información
      size[u] += size[v];

      // el índice más pequeño
      mnIndex[u] = min(mnIndex[u], mnIndex[v]);

      {
        // juntar el grupo mas pequeño al más grande
        if (group[v].size() > group[u].size())
          swap(group[u], group[v]);
        // siempre juntar al lider, que es u
        for (int i : group[v])
          group[u].push_back(i);
        // ya no necesitamos la info en v porque ya esta en u
        group[v].clear();
      }

      // la cantidad de componetes disminuye en 1 cuando se unen
      cc--;
      return true;
    }

    return false;
  }

  int getSize(int u) {
    return size[find(u)];
  }

  vector<int> getGroup(int u) {
    return group[find(u)];
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
    cin >> op;

    if (op == 'A') {
      cin >> x >> y;
      dsu.unite(x, y);
    } else {
      cin >> x;
      cout << dsu.getSize(x) << "\n";
    }
  }

  return 0;
}