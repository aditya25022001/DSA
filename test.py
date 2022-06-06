def maximumImportance(n, roads):
    deg=[0]*n
    for i,j in roads:
        deg[i]+=1
        deg[j]+=1
    print(deg)
    deg.sort()
    print(deg)
    ans=0
    for i in range(n,0,-1):
        # print(deg[i-1],i)
        ans+=(deg[i-1])*i
        #print(ans)
    return ans

print(maximumImportance(5,[[0,1],[1,2],[2,3],[0,2],[1,3],[2,4]]))


#define ll long long
# ll st[4*50000];
# ll a[50006];
# //0-based range
# void build(int ss,int se,int si){
#     if(ss==se){
#         st[si]=a[ss];
#         return;
#     }
#     int mid=(ss+se)/2;
#     build(ss,mid,2*si+1);
#     build(mid+1,se,2*si+2);
#     st[si]=max(st[2*si+1],st[2*si+2]);
#     return;
# }
# ll rangeQuery(int ss,int se,int qs,int qe,int si){
#     if(ss>qe || qs>se) return 0;
#     if(ss>=qs && se<=qe) return st[si];
#     int mid=(ss+se)/2;
#     return max(rangeQuery(ss,mid,qs,qe,2*si+1),rangeQuery(mid+1,se,qs,qe,2*si+2));
# }
# void update(int ss,int se,int si,int qi){
#     if(ss==se){
#         st[si]=a[qi];
#         return;
#     }
#     int mid=(ss+se)/2;
#     if(qi<=mid){
#         update(ss,mid,2*si+1,qi);
#     }
#     else{
#         update(mid+1,se,2*si+2,qi);
#     }
#     st[si]=max(st[2*si+1],st[2*si+2]);
# }
# #include<bits/stdc++.h>
# using namespace std;
# class FENWICK{
#     public:
#     vector<ll>BIT;
#     int n;
#     FENWICK(int x){
#         BIT.resize(x+1);
#         n=x;
#         for(int i=0;i<=n;i++){
#             BIT[i]=0;
#         }
#     }
#     void update(int ind ,int val){
#         while(ind<=n){
#             BIT[ind]+=val;
#             ind+=(ind&(-ind));
#         }
#     }
#     long long sum(int ind){
#         long long ans=0;
#         while(ind>0){
#             ans+=BIT[ind];
#             ind-=(ind&(-ind));
#         }
#         return ans;
#     }
#     //only in case of range update and point query
#     void range_update(int l,int r){
#         update(l,1);
#         update(r+1,-1);
#     }
#     //range update point value
#     long long pt_val(int ind){
#         return sum(ind);
#     }
#     long long range_sum(int l,int r){
#         return sum(r)-sum(l-1);
#     }
#     void build_T(vector<int> a){
#         for(int i=0;i<a.size();i++){
#             update(i+1,a[i]);
#         }
#     }
# };

# class BookMyShow {
# public:
#     FENWICK f=FENWICK(1);
#     int n,m,last=0;
#     BookMyShow(int n, int m) {
#         this->n=n;
#         this->m=m;
#        this->f=FENWICK(n);
#         for(int i=0;i<n;i++){
#             f.update(i+1,m);
#             a[i]=m;
#         }
#         build(0,n-1,0);
#     }
    
#     vector<int> gather(int k, int maxRow) {
#         int low=0;
#         int high=maxRow;
#         int ans=-1;
#         while(low<=high){
#             int mid=(low+high)>>1;
#             if(rangeQuery(0,n-1,0,mid,0)>=k){
#                 ans=mid;
#                 high=mid-1;
#             }
#             else{
#                 low=mid+1;
#             }
#         }
#         vector<int>tot;
#         if(ans==-1)return tot;
#         tot.push_back(ans);
#         ll mx=rangeQuery(0,n-1,0,ans,0);
#         tot.push_back(m-mx);
#         a[ans]-=k;
#         update(0,n-1,0,ans);
#         f.update(ans+1,-k);
#         return tot;
#     }
    
#     bool scatter(int k, int maxRow) {
#         ll sm=f.sum(maxRow+1);
#         if(sm<k)return false;
#         while(k>0){
#             ll temp=min(a[last],(ll)k);;
#             a[last]-=temp;
#             update(0,n-1,0,last);
#             f.update(last+1,-temp);
#             k-=temp;
#             if(a[last]!=0)break;
#             last++;
#         }
#         return true;
#     }
# };

# /**
#  * Your BookMyShow object will be instantiated and called as such:
#  * BookMyShow* obj = new BookMyShow(n, m);
#  * vector<int> param_1 = obj->gather(k,maxRow);
#  * bool param_2 = obj->scatter(k,maxRow);
#  */