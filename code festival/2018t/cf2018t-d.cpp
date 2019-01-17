#include<cstdio>
#include<cstring>
using namespace std;
int main(){
    int n,ans=1,p;
    char s[100010];
    scanf("%s",s);
    n=strlen(s);
    p=0;
    for(int i=1;i<n;i++){
        if(s[i]<=s[p]){
            ans++;
            p=i;
        }
    }
    printf("%d\n",ans);
}