#include<cstdio>
#include<queue>
#include<utility>
using namespace std;
int main(){
    int n,k;
    long long ans=0,a[100000],b[100000];
    pair<long long ,int> p;
    priority_queue<pair<long long,int>> t;
    scanf("%d %d",&n,&k);
    for(int i=0;i<n;i++){
        scanf("%ld %ld",&a[i],&b[i]);
        t.push(make_pair(-1*a[i],i));
    }
    for(int i=0;i<k;i++){
        p=t.top();
        ans-=p.first;
        p.first-=b[p.second];
        t.pop();
        t.push(p);
    }
    printf("%lld\n",ans);
}