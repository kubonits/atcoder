#include<cstdio>
#include<algorithm>
#include<cstring>
#include<vector>
#include<cmath>
using namespace std;

int main(){
    int n,d,x[10][10],sum,r,sa,ans=0;
    scanf("%d %d",&n,&d);
    for(int i=0;i<n;i++){
        for(int j=0;j<d;j++){
            scanf("%d",&x[i][j]);
        }
    }
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            sum=0;
            for(int k=0;k<d;k++){
                sa=x[i][k]-x[j][k];
                sum+=sa*sa;
            }
            r=sqrt(sum);
            if(r*r==sum){
                ans++;
            }
        }
    }
    printf("%d\n",ans);
}