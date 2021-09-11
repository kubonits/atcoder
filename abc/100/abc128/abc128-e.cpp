#include<cstdio>
#include<cstring>
#include<vector>
#include<utility>
#include<algorithm>
#include<set>
#define mod 1000000007
using namespace std;
int main(){
    int n,q,s,t,x,d,left,right,mid,cnt=0;
    vector<pair<pair<int,int> ,int> >st;
    multiset<int> ms;
    scanf("%d %d",&n,&q);
    for(int i=0;i<n;i++){
        scanf("%d %d %d",&s,&t,&x);
        st.push_back(make_pair(make_pair(s-x,1),x));
        st.push_back(make_pair(make_pair(t-x,-1),x));
    }
    int it=0;
    sort(st.begin(),st.end());
    for(int i=0;i<q;i++){
        scanf("%d",&d);
        while(it!=st.size()&&st[it].first.first<=d){
            if(st[it].first.second==1){
                ms.insert(st[it].second);
                cnt++;
            }
            else{
                ms.erase(st[it].second);
                cnt--;
            }
            it++;
        }
        if(cnt){
            multiset<int>::iterator ans=ms.begin();
            printf("%d\n",*ans);
        }
        else{
            printf("-1\n");
        }
    }
}