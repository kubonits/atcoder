#include<cstdio>
using namespace std;
int main(){
    int n;
    char s[6];
    scanf("%s",s);
    scanf("%d",&n);
    printf("%c%c\n",s[(n+4)/5-1],s[(n+4)%5]);
}