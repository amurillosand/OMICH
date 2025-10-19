const int N = 1e6 + 5;
vector<int> divisores[N];

void cribaDivisores() {
  for (int d = 1; d < N; d++) {
    // d es un divisor, entonces para cada multiplo vamos a agregar a d como divisor
    for (int m = d; m < N; m += d) {
      divisores[m].push_back(d);
    }
  }
}