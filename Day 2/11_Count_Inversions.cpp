// Brute Force - TC: O(N^2)  SC: O(1)
// -------------------------------------
// Simply loop through each pair using 2 loops and checking if arr[i] > arr[j] then we do a count++ lastly we return the count

class Solution{
public:
    long long int inversionCount(long long arr[], long long N){
        long long int count = 0;
        for(int i =0;i<N;i++){
            for(int j = i + 1;j<N;j++){
                if(arr[i] > arr[j]){
                    count++;
                }
            }
        }
        return count;
    }
};

// Merge Sort Approach - TC: O(nlogn)  SC: O(n)
// ----------------------------------------------
// For best Explaination - https://www.youtube.com/watch?v=kQ1mJlwW-c0&t=183s

class Solution{
public:
    long long int merge(long long arr[],long long temp[],long long int left,long long int mid,long long int right){
        long long int i,j,k;
        long long int count =0;
        i = left;
        j=mid;
        k=left;
        while((i<=mid - 1) && (j<=right)){
            if(arr[i]<=arr[j]) temp[k++] = arr[i++];
            else {
                temp[k++] = arr[j++];
                count = count + (mid - i);
            }
        }
        while(i<=mid-1) temp[k++] = arr[i++];
        while(j<=right) temp[k++] = arr[j++];
        for(i=left;i<=right;i++) arr[i] = temp[i];
        
        return count;
    }

    long long int mergeSort(long long arr[],long long temp[],long long int left ,long long int right){
        long long int mid,count=0;
        if(right>left){
            mid = (right+left)/2;
            count += mergeSort(arr,temp,left,mid); 
            count += mergeSort(arr,temp,mid+1,right); 
            count += merge(arr,temp,left,mid+1,right); 
        }
        return count;
    }

    long long int inversionCount(long long arr[], long long N){
        long long  temp[N];
        long long int ans = mergeSort(arr,temp,0,N-1);
        return ans;
    }
};