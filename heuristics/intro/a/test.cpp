#include <cstdlib>
#include <ctime>
#include <iostream>
using namespace std;
int main() {
  srand(time(NULL));
  cout << 365 << endl;
  for (int i = 0; i < 26; i++) {
    cout << rand() % 101 << " ";
  }
  cout << endl;
  for (int i = 0; i < 365; i++) {
    for (int j = 0; j < 26; j++) {
      cout << rand() % 20001 << " ";
    }
    cout << endl;
  }
}