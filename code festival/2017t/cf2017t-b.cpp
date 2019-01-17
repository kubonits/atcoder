#include<cstdio>
#include<cstring>
int main(){
    int n,ans=0,flag;
    char s[51];
    scanf("%s",s);
    n=strlen(s);
    for(int i=0;i<n;i++){
        flag=1;
        for(int j=0;i+j<=n-1-j;j++){
            if(s[i+j]!=s[n-1-j]){
                flag=0;
                break;
            }
        }
        if(flag){
            printf("%d\n",i);
            return 0;
        }
    }
    printf("%d\n",n);
}