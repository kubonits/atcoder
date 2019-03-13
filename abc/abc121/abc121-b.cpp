#include<cstdio>
using namespace std;
int main(){
    int n,m,c,a[20][20],b[20],cnt=0,x;
    scanf("%d %d %d",&n,&m,&c);
    for(int i=0;i<m;i++){
        scanf("%d",&b[i]);
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            scanf("%d",&a[i][j]);
        }
    }
    for(int i=0;i<n;i++){
        x=0;
        for(int j=0;j<m;j++){
            x+=a[i][j]*b[j];
        }
        if(x+c>0){
            cnt++;
        }
    }
    printf("%d\n",cnt);
}