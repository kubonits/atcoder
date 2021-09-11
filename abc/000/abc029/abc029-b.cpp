#include<cstdio>
#include<cstring>
using namespace std;

int main(){
    int flag,ans=0,n;
    char s[11];
    for(int i=0;i<12;i++){
        flag=0;
        scanf("%s",s);
        n=strlen(s);
        for(int j=0;j<n;j++){
            if(s[j]=='r'){
                flag=1;
                break;
            }
        }
        ans+=flag;
    }
    printf("%d\n",ans);
}