#include<cstdio>
#include<queue>
#include<cstring>
#include<utility>
#include<set>
using namespace std;
int main(){
    int dp[100001],n,a,b;
    char s[100001];
    long long ans=0;
    set<int> x;
    pair<int,int> p;
    priority_queue<pair<int,int>,vector<pair<int,int> >,greater<pair<int,int> > > pq;
    queue<int> q;
    scanf("%s",s);
    n=strlen(s);
    dp[0]=0;
    pq.push(make_pair(dp[0],0));
    for(int i=0;i<n;i++){
        if(s[i]=='('){
            dp[i+1]=dp[i]+1;
        }
        else{
            dp[i+1]=dp[i]-1;
        }
        pq.push(make_pair(dp[i+1],i+1));
    }
    p=pq.top();
    pq.pop();
    a=p.first;
    q.push(p.second);
    while(!pq.empty()){
        p=pq.top();
        pq.pop();
        if(p.first==a){
            while(!q.empty()){
                decltype(x)::iterator it =x.lower_bound(q.front());
                if(it==x.end()||*it>p.second){
                    ans+=q.size();
                    break;
                }
                else{
                    x.insert(q.front());
                    q.pop();
                }
            }
            q.push(p.second);
        }
        else{
            while(!q.empty()){
                x.insert(q.front());
                q.pop();
            }
            a=p.first;
            q.push(p.second);
        }
    }
    printf("%lld\n",ans);
}