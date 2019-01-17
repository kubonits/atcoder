#include<cstdio>
#include<cstdlib>
using namespace std;
int main(){
    int n;
    scanf("%d",&n);
    srand(n);
    for(int i=0;i<100;i++){
        if(rand()%2){
            printf("(");
        }
        else{
            printf(")");
        }
    }
    printf("\n");
}