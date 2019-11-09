#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
char s[500010];
long long a[500010]={},ans,num;
int main(){
    int n;
    
    scanf("%s",s);
    n=strlen(s);
    num=0;
    for(int i=0;i<n;i++){
        if(s[i]=='<'){
            num++;
        }
        else{
            num=0;
        }
        a[i+1]=max(a[i+1],num);
    }
    for(int i=n-1;i>=0;i--){
        if(s[i]=='>'){
            num++;
        }
        else{
            num=0;
        }
        a[i]=max(a[i],num);
    }
    for(int i=0;i<=n;i++){
        ans+=a[i];
    }
    printf("%lld\n",ans);
}