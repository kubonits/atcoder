#include<algorithm>
#include<cstdio>
using namespace std;
long n,x,t[1000000],ans=0;
    char s[1000010];
int main(){
    scanf("%ld %ld",&n,&x);
    scanf("%s",s);
    for(long i=0;i<n;i++){
        scanf("%ld",&t[i]);
    }
        for(long i=0;i<n;i++){
            if(s[i]=='0'){
                ans+=t[i];
            }
            else{
                ans+=min(t[i],x);
            }
        }
    printf("%ld\n",ans);
}