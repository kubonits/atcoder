#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int main(){
    int g[26][26]={},n,x,y,f,used[26]={},ff;
    char a[1001],b[1001];
    char s[27];
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        scanf("%s",a);
        scanf("%s",b);
        x=strlen(a);
        y=strlen(b);
        f=0;
        for(int i=0;i<min(x,y);i++){
            if(a[i]!=b[i]){
                f=1;
                g[a[i]-'a'][b[i]-'a']=1;
                break;
            }
        }
        if(f==0&&x>y){
            printf("-1\n");
            return 0;
        }
    }
    for(int i=0;i<26;i++){
        for(int j=0;j<26;j++){
            if(g[i][j]==1&&g[j][i]==1){
                printf("-1\n");
                return 0;
            }
        }
    }
    for(int i=0;i<26;i++){
        ff=0;
        for(int j=0;j<26;j++){
            if(used[j]==0){
                f=1;
                for(int k=0;k<26;k++){
                    if(g[k][j]==1&&used[k]==0){
                        f=0;
                    }
                }
                if(f){
                    ff=1;
                    used[j]=1;
                    s[i]=j+'a';
                    break;
                }
            }
        }
        if(ff==0){
            printf("-1\n");
            return 0;
        }
    }
    printf("%s\n",s);
}