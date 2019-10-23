#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
int main(){
    int k,cnt=8;
    char s[20];
    scanf("%s",s);
    k=strlen(s);
    for(int i=0;i<k;i++){
        if(s[i]=='x'){
            cnt--;
        }
    }
    if(cnt>0){
        printf("YES\n");
    }
    else{
        printf("NO\n");
    }
}