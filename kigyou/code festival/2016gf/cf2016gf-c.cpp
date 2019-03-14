#include<cstdio>
#include<algorithm>
using namespace std;
int n,a[100000],dp[100001][30][2],two[30],x=0,y,cnt=0,f[30]={};
int main(){
    scanf("%d",&n);
    two[0]=2;
    for(int i=1;i<30;i++){
        two[i]=2*two[i-1];
    }
    for(int i=0;i<n;i++){
        scanf("%d",&a[i]);
        x=x^a[i];
        y=a[i]^(a[i]-1);
        for(int j=0;j<30;j++){
            if(y+1==two[j]){
                f[j]=1;
            }
        }
    }
    for(int i=29;i>=0;i--){
        if(f[i]){
            if((x^(two[i]-1))<x){
                x=x^(two[i]-1);
                cnt++;
            }
        }
    }
    if(x){
        printf("-1\n");
    }
    else{
        printf("%d\n",cnt);
    }
}