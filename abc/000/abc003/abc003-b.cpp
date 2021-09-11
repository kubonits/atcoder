#include<cstdio>
#include<cstring>
using namespace std;
int main(){
    char s[11],t[11];
    int n,m,f=1;
    scanf("%s",s);
    scanf("%s",t);
    n=strlen(s);
    m=strlen(t);
    for(int i=0;i<n;i++){
        if(s[i]!=t[i]){
            if(s[i]!='@'&&t[i]!='@'){
                f=0;
            }
            else if(s[i]=='@'){
                if(t[i]!='a'&&t[i]!='t'&&t[i]!='c'&&t[i]!='o'&&t[i]!='d'&&t[i]!='e'&&t[i]!='r'){
                    f=0;
                }
            }
            else{
                if(s[i]!='a'&&s[i]!='t'&&s[i]!='c'&&s[i]!='o'&&s[i]!='d'&&s[i]!='e'&&s[i]!='r'){
                    f=0;
                }
            }
        }
    }
    if(f){
        printf("You can win\n");
    }
    else{
        printf("You will lose\n");
    }
}