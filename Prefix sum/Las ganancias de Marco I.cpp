#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 5;

int x[N];
long long prefixSum[N];
int n, q;

int main() {
  cin.tie(0)->sync_with_stdio(0), cout.tie(0);

  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> x[i];
  }

  // vamos a hacer el prefix sum 1-indexado
  prefixSum[0] = 0;
  for (int i = 1; i <= n; i++) {
    prefixSum[i] = prefixSum[i - 1] + x[i];
  }

  auto query = [&](int l, int r) {
    return prefixSum[r] - prefixSum[l - 1];
  };

  cin >> q;
  while (q--) {
    int a, b;
    cin >> a >> b;
    cout << query(a, b) << "\n";
  }

  return 0;
}