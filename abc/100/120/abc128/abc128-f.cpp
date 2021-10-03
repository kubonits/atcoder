#include<cstdio>
#include<cstring>
#include<vector>
#include<algorithm>
#include<set>
#define mod 1000000007
using namespace std;
typedef long long ll;
int main(){
    int n;
    ll s[100000],ans=0,sum;
    set<int> st;
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        scanf("%lld",&s[i]);
    }
    for(int i=1;i<n-1;i++){
        st.clear();
        st.insert(0);
        sum=0;
        if(i<n-1-i){
            for(int j=1;i*j<n-1;j++){
                if(n-1-i*j<=i){
                    break;
                }
                set<int>::iterator it=st.find(i*j);
                if(it!=st.end()){
                    break;
                }
                st.insert(i*j);
                it=st.find(n-1-i*j);
                if(it!=st.end()){
                    break;
                }
                st.insert(n-1-i*j);
                sum+=s[i*j]+s[n-1-i*j];
                ans=max(ans,sum);
            }
        }
    }
    printf("%lld\n",ans);
}