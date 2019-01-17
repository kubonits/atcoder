#include<cstdio>
using namespace std;
int main(){
    char s[5];
    int ans=0;
    scanf("%s",s);
    for(int i=0;i<4;i++){
        if(s[i]=='2'){
            ans++;
        }
    }
    printf("%d\n",ans);
}