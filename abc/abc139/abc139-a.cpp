#include<cstdio>
#include<algorithm>
#include<cstring>
#include<vector>
#include<queue>
#include<deque>
using namespace std;

int main(){
    int ans=0;
    char s[5],t[5];
    scanf("%s",s);
    scanf("%s",t);
    for(int i=0;i<3;i++){
        if(s[i]==t[i]){
            ans++;
        }
    }
    printf("%d",ans);
}