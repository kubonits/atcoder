#include<cstdio>
#include<algorithm>
#include<cstring>
#include<vector>
#include<queue>
#include<deque>
using namespace std;

int main(){
    int n,h[100000],cnt,ans=0;
    cnt=0;
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        scanf("%d",&h[i]);
    }
    for(int i=0;i<n-1;i++){
        if(h[i]>=h[i+1]){
            cnt++;
        }
        else{
            cnt=0;
        }
        ans=max(ans,cnt);
    }
    printf("%d\n",ans);
}