#include<bits/stdc++.h>
# define ll long long
using namespace std;
int sum(vector<int>&bit,int i){
   int s=0;
   
    while(i>0){
       s+=bit[i];
       i-=i&(-i);
    }
    return s;
}
void update(vector<int>&bit,int i,int n,int v){
   while(i<=n){
     bit[i]+=v;
     i+=i&(-i);
   }
 
}

int solve(int n, vector<int> arr) {
   int BIT_SIZE=100005;
   vector<int>bit(BIT_SIZE,0);
   vector<int>small(n+1,0);
   vector<int>big(n+1,0);
   unordered_set<int>s;
   for(int i=0;i<n;i++){
      
      small[i]=sum(bit,arr[i]-1);
       if(s.find(arr[i])==s.end()){                       //no of elemnts less on left side
      update(bit,arr[i],BIT_SIZE,1);
      s.insert(arr[i]);
 
       }
   }
   s.clear();
   for(int i=0;i<=BIT_SIZE;i++) bit[i]=0;
   for(int i=n-1;i>=0;i--){                            // no of elements greater on right side
      
     big[i]= sum(bit,BIT_SIZE)-sum(bit,arr[i]);
      if(s.find(arr[i])==s.end()){
     update(bit,arr[i],BIT_SIZE,1);
       s.insert(arr[i]);
        }
   }
   int ans=0;
   for(int i=0;i<n;i++){
      ans=max({ans,big[i],small[i]});

   }
   return ans;
}
 
 
int main() {
 
   
    int N;
    cin >> N;
    vector<int> arr(N);
    for(int i_arr = 0; i_arr < N; i_arr++)
    {
    	cin >> arr[i_arr];
    }
 
    int out_;
    out_ = solve(N, arr);
    cout << out_;
}