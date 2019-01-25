/*
https://atcoder.jp/contests/code-festival-2018-qualb/tasks/code_festival_2018_qualb_c
*/
#include<cstdio>
using namespace std;
int n,g[1002][1002],f=0,dx[4],dy[4];
int main(){
    
    dx[0]=1;
    dx[2]=-1;
    dy[1]=1;
    dy[3]=-1;
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            if((i+3*j)%5==0){
                g[i][j]=1;
            }
        }
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            f=1;
            if(g[i][j]==1){
                printf("X");
            }
            else{
                for(int k=0;k<4;k++){
                    if(g[i+dx[k]][j+dy[k]]==1){
                        f=0;
                    }
                }
                if(f){
                    printf("X");
                }
                else{
                    printf(".");
                }
            }
        }
        printf("\n");
    }
}