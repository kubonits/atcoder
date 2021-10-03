#include<cstdio>
#include<cmath>
#include<cstring>
#include<algorithm>
using namespace std;
int main(){
    long n,ans=1000,a;
    char s[11];
    scanf("%s",s);
    n=strlen(s);
    for(int i=0;i+2<n;i++){
        a=0;
        for(int j=0;j<3;j++){
            a*=10;
            a+=s[j+i]-'0';
        }
        //printf("%d\n",a);
        ans=min(ans,abs(a-753));
    }
    printf("%d\n",ans);
}