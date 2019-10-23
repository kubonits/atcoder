#include<cstdio>
using namespace std;
int main(){
    int n,a,b,c,d,flag=0;
    char s[200010];
    scanf("%d %d %d %d %d",&n,&a,&b,&c,&d);
    scanf("%s",s);
    if(s[c-1]=='#'||s[d-1]=='#'){
        printf("No\n");
        return 0;
    }
    if(c>d){
        for(int i=a-1;i+2<=c-1;i++){
            if(s[i+1]=='#'&&s[i+2]=='#'){
                printf("No\n");
                return 0;
            }
            if(s[i]=='.'&&s[i+1]=='.'&&s[i+2]=='.'&&i+2>b-1&&i+2<=d){
                flag=1;
            }
        }
        if(flag==0){
            printf("No\n");
            return 0;
        }
    }
    else{
        for(int i=b-1;i+2<=d-1;i++){
            if(s[i+1]=='#'&&s[i+2]=='#'){
                printf("No\n");
                return 0;
            }
        }
        for(int i=a-1;i+2<=c-1;i++){
            if(s[i+1]=='#'&&s[i+2]=='#'){
                printf("No\n");
                return 0;
            }
        }
    }
    printf("Yes\n");
}