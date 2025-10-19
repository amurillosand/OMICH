#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 5;

int a[N];
int n, t;

int main() {
  cin.tie(0)->sync_with_stdio(0), cout.tie(0);

  while (cin >> n >> t) {
    for (int i = 0; i < n; i++) {
      cin >> a[i];
    }

    int sum = 0;
    int mxRead = 0;
    // f(l, r) = sum(a[l..r]) <= t
    for (int l = 0, r = 0; l < n; l++) {
      while (r < n && sum + a[r] <= t) {
        sum += a[r];
        r++;
      }

      // [l, r)
      mxRead = max(mxRead, r - l);

      // f(l, r) => f(l + 1, r)
      sum -= a[l];
    }

    cout << mxRead << "\n";
  }

  return 0;
}