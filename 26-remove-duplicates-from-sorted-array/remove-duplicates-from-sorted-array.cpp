class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int n=nums.size();
        int k=1;
        int officer=0;
        int cm=1;
        while(cm<n){
            if(nums[cm]==nums[cm-1]){
                cm++;
                continue;
            }
            
            nums[officer+1]=nums[cm];
            officer++;
            cm++;
            k++;
            
        }
        return k;

        
    }
};