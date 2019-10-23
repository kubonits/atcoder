#include<cstdio>
#include<algorithm>
#include<vector>
#include<cmath>
#include<queue>
#include<cstring>
using namespace std;

int main(){
    int n,d;
    scanf("%d %d",&n,&d);
    if(n%(2*d+1)){
        printf("%d\n",n/(2*d+1)+1);
    }
    else{
        printf("%d\n",n/(2*d+1));
    }
    
}