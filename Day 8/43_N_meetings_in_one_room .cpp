// Optimised Approach - TC: O(2*n)  SC: O(n)
// --------------------------------------------
// First we create a vector pair in which we will store the starting and the finishing time, and then we will sort the 
// vector according to the finishing time and if 2 finishing time matches then we Lesser one first. Then we will iterate 
// and check if the finishing time is lesser than the starting time of others we do a count++. Lastly we return count.

class Solution{
    public:
    
    static bool comp(pair<int,int> a,pair<int,int> b){
        if(a.second == b.second) return a.first < b.first;
        return a.second < b.second;
    }
    int maxMeetings(int s[], int f[], int n){
        vector<pair<int,int>>ans(n);
        for(int i=0;i<n;i++){
            ans[i] = {s[i],f[i]};
        }
        sort(ans.begin(),ans.end(),comp);
        int i=0,j=1,c=1;
        while(j<n){
            if(ans[i].second < ans[j].first){
                c++;
                i=j;
            }
            j++;
        }
        return c;
    }
};