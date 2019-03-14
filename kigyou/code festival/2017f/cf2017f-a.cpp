#include<cstdio>
#include<cstring>
using namespace std;
int main(){
    char s[51],t[16][10];
    int n;
    strcpy(t[0],"KIHBR");
    strcpy(t[1],"KIHBRA");
    strcpy(t[2],"KIHBAR");
    strcpy(t[3],"KIHBARA");
    strcpy(t[4],"KIHABR");
    strcpy(t[5],"KIHABRA");
    strcpy(t[6],"KIHABAR");
    strcpy(t[7],"KIHABARA");
    strcpy(t[8],"AKIHBR");
    strcpy(t[9],"AKIHBRA");
    strcpy(t[10],"AKIHBAR");
    strcpy(t[11],"AKIHBARA");
    strcpy(t[12],"AKIHABR");
    strcpy(t[13],"AKIHABRA");
    strcpy(t[14],"AKIHABAR");
    strcpy(t[15],"AKIHABARA");
    scanf("%s",s);
    n=strlen(s);
    if(n>9){
        printf("NO\n");
        return 0;
    }
    for(int i=0;i<16;i++){
        if(strcmp(s,t[i])==0){
            printf("YES\n");
            return 0;
        }
    }
    printf("NO\n");
}