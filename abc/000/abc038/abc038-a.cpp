#include<cstdio>
#include<cstring>
using namespace std;
int main(){
    int n;
    char s[60];
    scanf("%s",s);
    n=strlen(s);
    if(s[n-1]=='T'){
        printf("YES\n");
    }
    else{
        printf("NO\n");
    }
}