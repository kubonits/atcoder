#include<cstdio>
#include<cstring>
using namespace std;
int main(){
    int n;
    char s[110],t[10];
    strcpy(t,"keyence");
    scanf("%s",s);
    n=strlen(s);
    for(int i=0;i<7;i++){
        int flag=1;
        for(int j=0;j<7;j++){
            if(j<i){
                if(s[j]!=t[j]){
                    flag=0;
                    break;
                }
            }
            else{
                if(s[j+n-7]!=t[j]){
                    flag=0;
                    break;
                }
            }
        }
        if(flag){
            printf("YES\n");
            return 0;
        }
    }
    printf("NO\n");
}