#include<cstdio>
#include<algorithm>
#include<cmath>
using namespace std;

int f[24],c[13];

int dfs(int x){
    int ans=24;
    if(x==12){
        for(int i=0;i<24;i++){
            for(int j=i+1;j<24;j++){
                if(f[i]&&f[j]){
                    ans=min(ans,min(j-i,24-j+i));
                }
            }
        }
        return ans;
    }
    if(c[x]!=1){
        return dfs(x+1);
    }
    f[x]=1;
    ans=dfs(x+1);
    f[x]=0;
    f[24-x]=1;
    ans=max(ans,dfs(x+1));
    f[24-x]=0;
    return ans;
}

int main(){
    int n,d;
    f[0]=1;
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        scanf("%d",&d);
        c[d]++;
    }
    if(c[0]){
        printf("0\n");
        return 0;
    }
    for(int i=1;i<13;i++){
        if(c[i]==2){
            if(i==12){
                printf("0\n");
                return 0;
            }
            f[i]=1;
            f[24-i]=1;
        }
        if(c[i]>2){
            printf("0\n");
            return 0;
        }
    }
    f[12]=c[12];
    printf("%d\n",dfs(1));
}