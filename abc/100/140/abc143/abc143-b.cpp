#include<cstdio>
#include<algorithm>
#include<vector>
#include<queue>
#include<cstring>
#include<set>
#include<map>
using namespace std;

int main(){
    int n,ans=0,sum=0,d;
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        scanf("%d",&d);
        ans+=sum*d;
        sum+=d;
    }
    printf("%d\n",ans);
}