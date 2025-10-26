#include <bits/stdc++.h>
using namespace std;

const int N = 1005;

int a[N][N];
long long prefixSum2D[N][N];
int n, m, q;

int main() {
  cin.tie(0)->sync_with_stdio(0), cout.tie(0);

  cin >> n >> m;
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      cin >> a[i][j];
    }
  }

  // construimos un prefix sum 2D 1-indexado
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      prefixSum2D[i][j] =
          prefixSum2D[i][j - 1] + prefixSum2D[i - 1][j] - prefixSum2D[i - 1][j - 1] + a[i][j];
    }
  }

  auto query = [&](int r1, int c1, int r2, int c2) {
    return prefixSum2D[r2][c2] - prefixSum2D[r2][c1 - 1] - prefixSum2D[r1 - 1][c2] +
           prefixSum2D[r1 - 1][c1 - 1];
  };

  cin >> q;
  while (q--) {
    int r1, c1, r2, c2;
    cin >> r1 >> c1 >> r2 >> c2;
    cout << query(r1, c1, r2, c2) << "\n";
  }

  return 0;
}