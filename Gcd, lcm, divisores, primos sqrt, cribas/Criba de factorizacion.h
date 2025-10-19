const int N = 1e6 + 5;
int factor[N];

void cribaFactorizacion() {
  // el primer factor de cada numero es si mismo
  for (int x = 0; x < N; x++) {
    factor[x] = x;
  }

  // solo necesitamos ir hasta la raiz de N, si nadie lo tacha es primo :D
  for (int x = 2; 1LL * x * x < N; x++) {
    if (factor[x] == x) {
      // x es primo, para cada multiplo, vamos a agregar el primer primo que lo divide
      for (int m = 1LL * x * x; m < N; m += x) {
        factor[m] = x;
      }
    }
  }
}

// para factorizar un numero n, tenemos que dividirlo entre sus factores y hacer la cuenta
map<int, int> factorizar(int n) {
  map<int, int> cnt; // {{p1, k1}, {p2, k2} ...}
  while (n > 1) {
    int x = factor[n];
    cnt[x]++;
    n /= x;
  }
  return cnt;
}

bool esPrimo(int n) {
  // un numero es primo si su primer factor es el mismo
  return n >= 2 && factor[n] == n;
}