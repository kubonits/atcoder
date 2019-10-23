#include<cstdio>
using namespace std;
int main(){
    int n;
    scanf("%d",&n);
    if(n%2){
        printf("%d\n",n+1);
    }
    else{
        printf("%d\n",n-1);
    }
}