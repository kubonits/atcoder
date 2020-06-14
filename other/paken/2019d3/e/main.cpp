#include <iostream>
using namespace std;
int main() {
  long long a = 0;
  for (long long i = 0; i <= 1500; i++) {
    a += i * i;
  }
  cout << a << endl;
}