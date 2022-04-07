//given an array we have to find continous subarray with given sum or else return -1
//Function to find a continuous sub-array which adds up to a given number.
    vector<int> subarraySum(int arr[], int n, long long s)
    {
        // Your code here
        vector<int> v;
        int i=0,j=0;
        long long sum=s;
        while(i<n || j<n){
            if(sum<0){
                sum=s;
                i++;
                j=i;
            }
            if(sum>0){
                sum=sum-arr[j];
                j++;
            }
            if(sum==0){
                return {i+1,j};
            }
            
        }
        return {-1};
    }
