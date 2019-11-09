#include<cstdio>
using namespace std;

int f(int x){
  if (x<=1)
    return 0;
  else if(x%2==0)
    return f(x+1)+x;
  else
    return f(x-3)-x;
}

int main(){
    printf("%d\n",f(10));
}