#include <bits/stdc++.h>
using namespace std;

string p;
int n;

int main() {
  cin.tie(0)->sync_with_stdio(0), cout.tie(0);

  while (cin >> n >> p) {
    set<int> st;
    for (char c : p) {
      st.insert(c);
    }

    int k = st.size();

    int mnLen = n;
    map<int, int> cnt;
    for (int l = 0, r = 0; l < n; l++) {
      while (r < n && cnt.size() < k) {
        cnt[p[r]]++;
        r++;
      }

      // [l, r) y ya vio los k pokemons distintos
      if (cnt.size() == k) {
        mnLen = min(mnLen, r - l);
      }

      // f(l, r) => f(l + 1, r)
      if (--cnt[p[l]] == 0) {
        cnt.erase(p[l]);
      }
    }

    cout << mnLen << "\n";
  }

  return 0;
}