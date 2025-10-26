#include <bits/stdc++.h>
using namespace std;

#define fore(i, a, b) for (int i = (a); i < (b); i++)

using lli = long long;

const int N = 1e5 + 5;
int a[N];
int n, p;

bool can(int x) {
  int sum = 1;
  // el primero pues va a a[0]
  int pos = 0;
  while (pos < n) {
    // para cada cubiculo asignado, quiero encontrar el siguiente cubiculo que este a distancia x
    // con respecto a a[pos]
    int nxt = lower_bound(a, a + n + 1, a[pos] + x) - a;
    // es un cubiculo falso
    if (nxt == n)
      break;

    // lo puedo agregar a un cubiculo
    sum++;
    pos = nxt;
  }

  return sum >= p;
}

int main() {
  cin.tie(0)->sync_with_stdio(0), cout.tie(0);

  cin >> n >> p;

  // a[n] es un cubiculo falso
  a[n] = 2e9;
  fore (i, 0, n) {
    cin >> a[i];
  }

  // todos los cubiculos ya estan ordenados
  sort(a, a + n);

  int low = 1, high = a[n - 1];
  while (low + 1 < high) {
    int mid = (low + high) / 2;

    if (can(mid)) {
      low = mid;
    } else {
      high = mid;
    }
  }

  cout << low << "\n";

  return 0;
}