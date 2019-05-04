#include<cstdio>
using namespace std;
int main(){
    int n,cnt=0;
    char s[110];
    scanf("%d",&n);
    scanf("%s",s);
    for(int i=0;i<n;i++){
        if(s[i]=='R'){
            cnt++;
        }
    }
    if(cnt>n/2){
        printf("Yes\n");
    }
    else{
        printf("No\n");
    }
}