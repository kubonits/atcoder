#include<cstdio>
#define mod 1000000007
using namespace std;
int main(){
    long long n,x[26]={},ans=1;
    char s[100000];
    scanf("%lld",&n);
    scanf("%s",s);
    for(int i=0;i<n;i++){
        x[s[i]-'a']++;
    }
    for(int i=0;i<26;i++){
        ans*=x[i]+1;
        ans%=mod;
    }
    printf("%lld\n",ans-1);
}