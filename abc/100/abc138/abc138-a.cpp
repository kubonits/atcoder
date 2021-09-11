#include<cstdio>
#include<algorithm>
#include<vector>
#include<cstring>
using namespace std;
int main(){
    int a;
    char s[11];
    scanf("%d",&a);
    scanf("%s",s);
    if(a<3200){
        printf("red\n");
    }
    else{
        printf("%s\n",s);
    }
}