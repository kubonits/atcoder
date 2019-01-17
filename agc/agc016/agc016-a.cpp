#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int main(){
    char s[110],t[110];
    int n,ans=100,f[30]={},flag;
    scanf("%s",s);
    n=strlen(s);
    for(int i=0;i<n;i++){
        f[s[i]-'a']++;
        if(f[s[i]-'a']==n){
            printf("0\n");
            return 0;
        }
    }
    for(int i=0;i<30;i++){
        if(f[i]){
            for(int j=0;j<n;j++){
                t[j]=s[j];
            }
            for(int j=n-1;j>1;j--){
                flag=1;
                for(int k=0;k<j;k++){
                    if(t[k]==i+'a'||t[k+1]==i+'a'){
                        t[k]=i+'a';
                    }
                    else{
                        flag=0;
                    }
                }
                if(flag){
                    ans=min(ans,n-j);
                    break;
                }
            }
        }
    }
    printf("%d\n",ans);
}