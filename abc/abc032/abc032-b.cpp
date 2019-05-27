#include<cstdio>
#include<cstring>
using namespace std;

int n,k,ans,flag;
char s[310],t[300][310];
int main(){
    scanf("%s",s);
    scanf("%d",&k);
    n=strlen(s);
    for(int i=0;i<n-k+1;i++){
        for(int j=0;j<k;j++){
            t[i][j]=s[i+j];
        }
        flag=1;
        for(int j=0;j<i;j++){
            if(strcmp(t[i],t[j])==0){
                flag=0;
                break;
            }
        }
        ans+=flag;
    }
    printf("%d\n",ans);
}