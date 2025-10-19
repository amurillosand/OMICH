const int N = 1e6 + 5;
bitset<N> esPrimo;
vector<int> primos;

void criba() {
  // vamos a decir que "todos los numeros son primos"
  esPrimo.set();

  // el 0 y 1 no lo son
  esPrimo[0] = esPrimo[1] = 0;

  // para cada numero x, vamos a ver si nadie lo ha tachado, solo revisamos hasta la raiz de N
  // porque ya tachamos todos los numeros
  for (int x = 2; 1LL * x * x < N; x++) {
    if (esPrimo[x]) {
      // como x es primo, vamos a descartar a todos sus multiplos
      for (int m = 1LL * x * x; m < N; m += x) {
        esPrimo[m] = 0;
      }
    }
  }

  for (int x = 2; x < N; x++) {
    if (esPrimo[x]) {
      // x es primo
      primos.push_back(x);
    }
  }
}
