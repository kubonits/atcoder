#include<cstdio>
#include<algorithm>
#include<cstring>
#include<vector>
#include<set>
#include<map>
#define mod 1000000007
using namespace std;
int main(){
    char s[5];
    int a[26]={},ans=0;
    scanf("%s",s);
    for(int i=0;i<4;i++){
        a[s[i]-'A']++;
    }
    for(int i=0;i<26;i++){
        if(a[i]==2){
            ans++;
        }
    }
    if(ans==2){
        printf("Yes\n");
    }
    else{
        printf("No\n");
    }
}