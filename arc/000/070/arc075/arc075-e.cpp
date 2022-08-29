#include<cstdio>
#include<vector>
#include<queue>
#include<utility>
#define MAX_V 262144
typedef long long ll;
using namespace std;

int bit[MAX_V+1],n,cnt;

int sum(int i){
    int s=0;
    while(i>0){
        s+=bit[i];
        i-=(i&-i);
    }
    return s;
}

void add(int i,int x){
    while(i<=n+1){
        bit[i]+=x;
        i += i & -i;
        if(i==0){
            break;
        }
    }
}
ll ans=0;
ll suma[200001],a[200000],k;
int main(){
    pair<ll,int> p;
    suma[0]=0;
    priority_queue<pair<ll,int> > q;
    scanf("%d %lld",&n,&k);
    q.push(make_pair(0,0));
    for(int i=0;i<n;i++){
        scanf("%lld",&a[i]);
        a[i]-=k;
        suma[i+1]=suma[i]+a[i];
        q.push(make_pair(suma[i+1],i+1));
    }
    while(!q.empty()){
        p=q.top();
        q.pop();
        ans+=sum(n+1)-sum(p.second+1);
        add(p.second+1,1);
    }
    printf("%lld\n",ans);
}