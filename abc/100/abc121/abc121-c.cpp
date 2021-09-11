#include<cstdio>
#include<algorithm>
#include<utility>
using namespace std;

int main(){
    int n,m;
    long long ans=0;
    pair<long long ,int> p[100000];
    scanf("%d %d",&n,&m);
    for(int i=0;i<n;i++){
        scanf("%lld %d",&p[i].first,&p[i].second);
    }
    sort(p,p+n);
    for(int i=0;i<n;i++){
        if(m>p[i].second){
            ans+=(long long)p[i].second*p[i].first;
            m-=p[i].second;
        }
        else{
            ans+=(long long)m*p[i].first;
            m=0;
        }
    }
    printf("%lld\n",ans);
}