#include <stdio.h>

static inline int quadrado(int x)
{
  printf("Quadrado de %d", x);
  return x * x;
}
int func1(int x) { return quadrado(x); }
int func2(int x) { return quadrado(x); }
int func3(int x) { return quadrado(x); }

int main()
{
  int n = 0xAA;

  quadrado(n);

  func1(2);
  func2(4);
  func3(6);
  return 0;
}
