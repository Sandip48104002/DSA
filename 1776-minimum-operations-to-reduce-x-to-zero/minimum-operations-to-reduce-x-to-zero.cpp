class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        int count=-1;int n=nums.size();
        int start=-1,end=-1;
        int left=0,sum=0;
        for(int i=0;i<n;i++){
            sum+=nums[i];
        }
        if(x > sum) return -1;
        int temp=0;
        for(int i=0;i<n;i++){
            temp+=nums[i];
            if(temp==sum-x) {
                if(i-left+1 > count ) {
                    count=i-left+1;
                }
            }
            if(temp > sum-x){
                while(temp > sum-x){
                    temp-=nums[left];
                    left++;
                }
                if(temp==sum-x) {
                    if(i-left+1 > count ) {
                        count=i-left+1;
                    }
                }
            }
        }
        return count==-1 ?-1: n-count;
    }
};