#include<cstdio>
#include<queue>
#include<algorithm>
using namespace std;
int main(){
    int n,m,sum=0,ans=0,x,y;
    priority_queue<int,vector<int>,greater<int> > q;
    scanf("%d %d",&n,&m);
    for(int i=0;i<n;i++){
        scanf("%d %d",&x,&y);
        sum+=x;
        if(i>=m){
            sum-=q.top();
            q.pop();
        }
        q.push(x-y);
        ans=max(ans,sum);
    }
    printf("%d\n",ans);
}