#include<cstdio>
#include<cstring>
using namespace std;

int i;
int n;
char s[100010];

int p(char c){
    printf("(");
    i+=2;
    for(;i<n;i++){
        if(s[i]==')'){
            printf(")");
            return 0;
        }
        else if(s[i]>='0'&&s[i]<='9'){
            printf("%c",s[i]);
        }
        else if(s[i]==','){
            printf("%c",c);
        }
        else{
            p(s[i]);
        }
    }
}

int main(){

    scanf("%s",s);
    n=strlen(s);
    for(i=0;i<n;i++){
        if(s[i]>='0'&&s[i]<='9'){
            printf("%c",s[i]);
        }
        else{
            p(s[i]);
        }
    }
}