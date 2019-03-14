#include<cstdio>
#include<vector>
#include<utility>
#include<algorithm>
using namespace std;
int main(){
    int n;
    long long int k,a[100000],c;
    vector<long long int> bi;
    vector<pair<long long int ,long> > k1;
    long b[100000],ans=0;
    scanf("%d %lld",&n,&k);
    k1.push_back(make_pair(k,0));
    while(k){
        bi.push_back(k%2);
        k/=2;
    }
    for(int i=bi.size()-1;i>=1;i--){
        if(bi[i]==1){
            c=0;
            for(int j=bi.size()-1;j>=0;j--){
                c*=2;
                if(j<i||(j!=i&&bi[j])){
                    c+=1;
                }
            }
            k1.push_back(make_pair(c,0));
        }
    }
    for(int i=0;i<n;i++){
        scanf("%lld %ld",&a[i],&b[i]);
        for(int j=0;j<k1.size();j++){
            c=a[i]|k1[j].first;
            if(c==k1[j].first){
                k1[j].second+=b[i];
            }
        }
    }
    for(int i=0;i<k1.size();i++){
        ans=max(ans,k1[i].second);
    }
    printf("%ld\n",ans);
}