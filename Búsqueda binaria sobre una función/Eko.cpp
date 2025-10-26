#include <bits/stdc++.h>
using namespace std;

#define fore(i, a, b) for (int i = (a); i < (b); i++)

using lli = long long;

const int N = 1e6 + 5;
lli a[N];
lli m;
int n;

// esta funcion intenta poner la sierra en una altura h y contar cuanta madera obtiene
bool cut(lli h) {
  lli sum = 0;
  fore (i, 0, n) {
    if (a[i] > h) {
      sum += (a[i] - h);
    } else {
      break;
    }

    if (sum >= m)
      break;
  }
  return sum >= m;
}

int main() {
  cin.tie(0)->sync_with_stdio(0), cout.tie(0);

  while (cin >> n >> m) {
    fore (i, 0, n) {
      cin >> a[i];
    }

    // los arboles estan ordenados del mas alto al mas chiquito
    // para que la funcion cut(h) termine antes
    sort(a, a + n, [&](int x, int y) {
      return x > y;
    });

    // la sierra tiene que ser a lo mas a[0] que es el arbol mas alto
    lli low = 0, high = a[0];
    while (low + 1 < high) {
      lli mid = (low + high) / 2;

      if (cut(mid)) {
        low = mid;
      } else {
        high = mid;
      }
    }

    // cut(low) = true, porque es la ultima altura donde alcanzo a conseguir >= m madera
    // cut(high) = false, no me alcanza para conseguir >= m madera

    cout << low << "\n";
  }

  return 0;
}