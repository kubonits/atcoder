#include<cstdio>
#include<algorithm>
#include<queue>
#include<utility>
using namespace std;

int main(){
    int x[2],y[2],h,w,t,g[10][10][10][10],l,r,mid;
    char s[10][11];
    scanf("%d %d %d",&h,&w,&t);
    for(int i=0;i<h;i++){
        scanf("%s",s[i]);
    }
    for(int i=0;i<h;i++){
        for(int j=0;j<w;j++){
            if(s[i][j]=='S'){
                x[0]=i;
                y[0]=j;
            }
            else if(s[i][j]=='G'){
                x[1]=i;
                y[1]=j;
            }
        }
    }
    l=0;
    r=1000000000;
    while(l<=r){
        mid=(l+r)/2;
        for(int i=0;i<h;i++){
            for(int j=0;j<w;j++){
                for(int k=0;k<h;k++){
                    for(int o=0;o<w;o++){
                        if(i==k&&j+1==o){
                            if(s[k][o]=='#'){
                                g[i][j][k][o]=mid;
                            }
                            else{
                                g[i][j][k][o]=1;
                            }
                        }
                        else if(i==k&&j-1==o){
                            if(s[k][o]=='#'){
                                g[i][j][k][o]=mid;
                            }
                            else{
                                g[i][j][k][o]=1;
                            }
                        }
                        else if(i+1==k&&j==o){
                            if(s[k][o]=='#'){
                                g[i][j][k][o]=mid;
                            }
                            else{
                                g[i][j][k][o]=1;
                            }
                        }
                        else if(i-1==k&&j==o){
                            if(s[k][o]=='#'){
                                g[i][j][k][o]=mid;
                            }
                            else{
                                g[i][j][k][o]=1;
                            }
                        }
                        else{
                            g[i][j][k][o]=1000000001;
                        }
                    }
                }
                g[i][j][i][j]=0;
            }
        }
        for(int a=0;a<h;a++){
            for(int b=0;b<w;b++){
                for(int c=0;c<h;c++){
                    for(int d=0;d<w;d++){
                        for(int e=0;e<h;e++){
                            for(int f=0;f<w;f++){
                                g[c][d][e][f]=min(g[c][d][e][f],g[c][d][a][b]+g[a][b][e][f]);
                            }
                        }
                    }
                }
            }
        }
        if(g[x[0]][y[0]][x[1]][y[1]]<=t){
            l=mid+1;
        }
        else{
            r=mid-1;
        }
    }
    printf("%d\n",r);
}