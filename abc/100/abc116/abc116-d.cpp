#include<cstdio>
#include<utility>
#include<queue>
#include<algorithm>
using namespace std;
long long n,k,ans,t,d,sum,cnt;
vector<pair<long long,long long> > p;
priority_queue<long long, vector<long long>, greater<long long> > pq;
long long flag[100001];
queue<long long> q;
int main(){
    scanf("%ld %ld",&n,&k);
    for(int i=0;i<n;i++){
        scanf("%ld %ld",&t,&d);
        p.push_back(make_pair(d,t));
    }
    sort(p.begin(),p.end());
    for(int i=0;i<n;i++){
        if(i<k){
            sum+=p[n-1-i].first;
            if(flag[p[n-1-i].second]==1){
                pq.push(p[n-1-i].first);
            }
            flag[p[n-1-i].second]=1;
        }
        else{
            if(flag[p[n-1-i].second]==0){
                q.push(p[n-1-i].first);
                flag[p[n-1-i].second]=2;
            }
        }
    }
    for(long i=1;i<=n;i++){
        if(flag[i]==1){
            cnt++;
        }
    }
    ans=sum+cnt*cnt;
    while(!q.empty()&&!pq.empty()){
        sum+=q.front();
        sum-=pq.top();
        cnt++;
        q.pop();
        pq.pop();
        ans=max(ans,sum+cnt*cnt);
    }
    printf("%ld\n",ans);
}