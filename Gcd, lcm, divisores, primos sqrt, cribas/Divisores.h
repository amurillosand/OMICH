vector<int> divisores(int p) {
  vector<int> d;

  for (int x = 1; 1LL * x * x <= p; x++) {
    int y = p / x;

    if (p % x == 0) {
      d.push_back(x);
      if (x != y)
        d.push_back(y);
    }
  }

  sort(d.begin(), d.end());

  return d;
}