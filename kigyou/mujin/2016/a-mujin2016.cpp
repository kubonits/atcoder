#include <cstdio>
using namespace std;
int main() {
  char c;
  scanf("%c", &c);
  if (c == 'O' || c == 'P' || c == 'K' || c == 'L') {
    printf("Right\n");
  } else {
    printf("Left\n");
  }
}