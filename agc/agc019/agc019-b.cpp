#include<cstdio>
#include<cstring>
using namespace std;
int main(){
    long n,cnt[30]={},ans=1;
    char s[200010];
    scanf("%s",s);
    n=strlen(s);
    for(int i=0;i<n;i++){
        cnt[s[i]-'a']++;
    }
    for(int i=0;i<30;i++){
        for(int j=i+1;j<30;j++){
            ans+=cnt[i]*cnt[j];
        }
    }
    printf("%ld\n",ans);
}