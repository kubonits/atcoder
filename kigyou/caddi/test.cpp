#include<cstdio>
using namespace std;
int main(){
  int g[100][100]={};
  g[0][0]=0;
  g[0][1]=g[1][0]=1;
  for(int i=2;i<100;i++){
    g[0][i]=g[i][0]=i%2;
  }
  for(int i=1;i<100;i++){
    for(int j=1;j<100;j++){
      if(!g[i-1][j]||!g[i][j-1]||!g[i-1][j-1]){
        g[i][j]=1;
      }
    }
  }
  for(int i=0;i<10;i++){
    for(int j=0;j<10;j++){
      printf("%d",g[i][j]);
    }
    printf("\n");
  }
}