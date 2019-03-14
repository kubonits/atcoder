#include<cstdio>
#include<algorithm>
#include<vector>
#include<utility>
#define mod 1000000007
using namespace std;
int main(){
    int a[100000],b[100000];
    vector<pair<int,int> > p;
    long long ans=1LL,l=0LL,n,x=0,y=0;
    scanf("%lld",&n);
    for(int i=0;i<n;i++){
        scanf("%d",&a[i]);
        p.push_back(make_pair(a[i],1));
    }
    for(int i=0;i<n;i++){
        scanf("%d",&b[i]);
        p.push_back(make_pair(b[i],-1));
    }
    sort(p.begin(),p.end());
    for(long long i=0;i<p.size();i++){
        if(p[i].second==1){
            if(y){
                ans*=y;
                ans%=mod;
                y--;
            }
            else{
                x++;
            }
        }
        else{
            if(x){
                ans*=x;
                ans%=mod;
                x--;
            }
            else{
                y++;
            }
        }
    }
    printf("%ld\n",ans);
}