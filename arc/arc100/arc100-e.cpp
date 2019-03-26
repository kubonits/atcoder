#include<cstdio>
#include<queue>
#include<utility>
#include<algorithm>
using namespace std;
int n,two[30],a[300000],ans[300000],f;
pair<int,int> p[300000][2];
priority_queue<pair<int,int> > q;
int main(){
    two[0]=1;
    for(int i=1;i<30;i++){
        two[i]=2*two[i-1];
    }
    scanf("%d",&n);
    for(int i=0;i<two[n];i++){
        scanf("%d",&a[i]);
    }
    p[0][0].first=a[0];
    p[0][0].second=0;
    p[0][1].first=0;
    p[0][1].second=0;
    ans[0]=-1;
    for(int i=1;i<two[n];i++){
        q.push(make_pair(a[i],i));
        q.push(make_pair(a[0],0));
        for(int j=0;j<30;j++){
            if(i&two[j]){
                q.push(p[i^two[j]][0]);
                q.push(p[i^two[j]][1]);
            }
        }
        f=0;
        p[i][0]=q.top();
        q.pop();
        while(!q.empty()){
            if(f==0&&q.top()!=p[i][0]){
                f=1;
                p[i][1]=q.top();
            }
            q.pop();
        }
        ans[i]=p[i][0].first+p[i][1].first;
        ans[i]=max(ans[i],ans[i-1]);
    }
    for(int i=1;i<two[n];i++){
        printf("%d\n",ans[i]);
    }
}