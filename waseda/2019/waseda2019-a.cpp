#include<cstdio>
#include<cstring>
using namespace std;
int main(){
    int n;
    char s[100010];
    scanf("%s",s);
    n=strlen(s);
    for(int i=n-2;i>=0;i--){
        if(s[i]=='W'&&s[i+1]=='A'){
            s[i]='A';
            s[i+1]='C';
        }
    }
    printf("%s\n",s);
}