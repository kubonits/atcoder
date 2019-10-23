#include<cstdio>
#include<algorithm>
#include<cstring>
#include<vector>
#include<queue>
#include<utility>
#include<deque>
using namespace std;
#define MOD 1000000007
typedef long long ll;

ll kai[100001];
ll n,ans;
vector<ll> l,r;
char s[200010];
int a[200001];
int main(){
    scanf("%lld",&n);
    scanf("%s",s);
    if(s[0]=='W'||s[2*n-1]=='W'){
        printf("0\n");
        return 0;
    }
    kai[0]=1;
    for(ll i=1;i<=n;i++){
        kai[i]=kai[i-1]*i;
        kai[i]%=MOD;
    }
    for(int i=1;i<2*n;i++){
        if(s[i]==s[i-1]){
            a[i]=a[i-1]^1;
        }
        else{
            a[i]=a[i-1];
        }
    }
    ans=1;
    for(int i=0;i<2*n;i++){
        if(a[i]){
            if(l.size()>r.size()){
                ans*=(ll)(l.size()-r.size());
                ans%=MOD;
            }
            else{
                printf("0\n");
                return 0;
            }
            r.push_back(i);
        }
        else{
            l.push_back(i);
        }
    }
    ans*=kai[n];
    ans%=MOD;
    if(l.size()!=r.size()){
        ans=0LL;
    }
    printf("%lld\n",ans);
}