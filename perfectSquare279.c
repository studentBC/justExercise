int numSquares(int n) {
    int largest = sqrt(n);
    //printf("%d \n",largest);
    int value[largest];
    int stamp[n+1];
    int leftvalue;
    stamp[0] = 0;
    for (int i = 1; i <= largest; i++) {
        value[i-1] = i*i;
    }
    int min = INT_MAX;
    for (int i = 1; i <= n; i++) {
        min = INT_MAX;
        for (int j = 0; j < largest; j++) {
            leftvalue = i-value[j];
            if (leftvalue > -1  && stamp[leftvalue] < min) {
                min = 1 + stamp[leftvalue];
            }
        }
        stamp[i] = min;
        //printf("%d ,",stamp[i]);
    }
    return stamp[n];
}
//fatest method
static inline int8_t
min_i8(int8_t a, int8_t b) {
    return a > b ? b : a;
}

int numSquares(int n) {
#if 0
  int8_t pn[n+1];
  memset(pn, INT8_MAX, n+1);

  {
    int i = 0;
    do {
      register int sn = i*i;
      if (sn > n) {
        break;
      }
      pn[sn] = 1;
      ++i;
    } while (true);
  }

  for (int i=1; i<n; ++i) {
    int j = 0;
    do {
      register int num = i+j*j;
      if (num > n) {
        break;
      }
      pn[num] = min_i8(pn[num], pn[i]+1);
      ++j;
    } while (true);
  }
  return pn[n];
#else
  while (n % 4 == 0) {
    n /= 4;
  }

  if (n % 8 == 7) {
    return 4;
  }

  int a = 0;
  do {
    register int a2 = a * a;
    if (a2 > n) {
      break;
    }
    int b = sqrt(n - a2);
    if (a2 + b * b == n) {
      return !!a + !!b;
    }
    ++a;
  } while (true);

  return 3;
#endif
}
