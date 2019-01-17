#include<cstdio>
using namespace std;
int main(){
    int a,b,flag=1;
    char s[12];
    scanf("%d %d",&a,&b);
    scanf("%s",s);
    for(int i=0;i<a+b+1;i++){
        if(i==a&&s[i]!='-'){
            flag=0;
        }
        else if(i!=a&&(s[i]>'9'||s[i]<'0')){
            flag=0;
        }
    }
    if(flag){
        printf("Yes\n");
    }
    else{
        printf("No\n");
    }
}