#include<cstdio>
#include<vector>
#include<algorithm>
using namespace std;
int main(){
    long long n,k,r;
    vector<long long> le,ri;
    scanf("%lld %lld %lld",&n,&k,&r);
    if((n-k)*(n-k+1)/2<r){
        printf("No Luck\n");
        return 0;
    }
    for(long long i=n;i>=1;i--){
        if(r>=(max(0LL,i-k))){
            le.push_back(i);
            r-=max(0LL,i-k);
        }
        else{
            ri.push_back(i);
        }
    }
    for(int i=0;i<le.size();i++){
        printf("%lld ",le[i]);
    }
    for(int i=ri.size()-1;i>=0;i--){
        printf("%lld ",ri[i]);
    }
    printf("\n");
}