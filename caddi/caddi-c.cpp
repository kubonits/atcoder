#include<cstdio>
#include<vector>
#include<cmath>
#include<utility>
using namespace std;
int main(){
    long long n,p,m,ans=1;
    vector<pair<long long,long> >so;
    scanf("%lld %lld",&n,&p);
    if(n==1){
        printf("%lld\n",p);
        return 0;
    }
    m=sqrt(p);

    for(long long i=2;i<m;i++){
        if(p%i==0){
            so.push_back(make_pair(i,0));
        }
        while(p%i==0){
            so[so.size()-1].second++;
            p/=i;
        }
    }
    for(int i=0;i<so.size();i++){
        if(so[i].second>=n){
            for(long long j=0;j<so[i].second/n;j++){
                ans*=so[i].first;
            }
        }
    }
    printf("%lld\n",ans);
}