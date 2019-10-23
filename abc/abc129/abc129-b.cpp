#include<cstdio>
#include<algorithm>
#include<vector>
#include<cstring>
#include<utility>
#include<queue>
#include<cmath>
#define mod 1000000007
#define INF 1000000000000000
using namespace std;

int main(){
    int n,w,sum[101]={},ans=10000000;
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        scanf("%d",&w);
        sum[i+1]=sum[i]+w;
    }
    for(int i=1;i<n;i++){
        ans=min(ans,abs(sum[n]-2*sum[i]));
    }
    printf("%d\n",ans);
}