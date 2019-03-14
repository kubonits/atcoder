/*
https://atcoder.jp/contests/nikkei2019-qual/tasks/nikkei2019_qual_c
*/
#include<cstdio>
#include<algorithm>
#include<utility>
using namespace std;
int n;
    long long a,b,ans=0;
    pair<long long,pair<long long,long long> > p[100000];
int main(){
    
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        scanf("%lld %lld",&a,&b);
        p[i]=make_pair(a+b,make_pair(a,b));
    }
    sort(p,p+n);
    for(int i=0;i<n;i++){
        if(i%2==0){
            ans+=p[n-1-i].second.first;
        }
        else{
            ans-=p[n-1-i].second.second;
        }
    }
    printf("%lld\n",ans);
}

