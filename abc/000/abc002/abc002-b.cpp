#include<cstdio>
#include<cstring>
using namespace std;
int main(){
    int n;
    char s[32];
    scanf("%s",s);
    n=strlen(s);
    for(int i=0;i<n;i++){
        if(s[i]!='a'&&s[i]!='i'&&s[i]!='u'&&s[i]!='e'&&s[i]!='o'){
            printf("%c",s[i]);
        }
    }
    printf("\n");
}