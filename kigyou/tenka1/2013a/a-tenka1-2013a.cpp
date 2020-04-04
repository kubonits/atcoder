#include <cstdio>
using namespace std;
int main() {
  long long n = 42LL;
  while (n < 130000000) {
    n *= 2;
  }
  printf("%lld\n", n);
}