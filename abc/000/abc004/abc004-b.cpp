#include<cstdio>
using namespace std;
int main(){
    char s[35][5];
    for(int i=0;i<16;i++){
        scanf("%s",&s[i]);
    }
    for(int i=0;i<4;i++){
        for(int j=0;j<4;j++){
            printf("%c ",s[15-(4*i+j)][0]);
        }
        printf("\n");
    }
}
