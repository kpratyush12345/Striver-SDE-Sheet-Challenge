// Greedy Approach - TC: O(n)  SC: O(1)
// ---------------------------------------
// We start iterating from the back and check if currency[i]<=N then we push that currency in ans and decrement our N value 
// else we just do i--, Lastly we return ans vector.

class Solution{
public:
    vector<int> minPartition(int N){
        vector<int> ans;
        vector<int> currency={1,2,5,10,20,50,100,200,500,2000};
        int i=currency.size()-1;
        while(N>0){
            if(currency[i]<=N){
                N-=currency[i];
                ans.push_back(currency[i]);
            }
            else if(currency[i]>N)
                i--;
        }
        return ans;
    }
};