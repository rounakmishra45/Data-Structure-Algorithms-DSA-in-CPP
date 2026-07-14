class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        int n = nums.size();
        vector<int> a; // For zero and positives
        vector<int> b; // For negatives

        // 1. Separate the numbers
        for(int i = 0; i < n; i++) {
            if(nums[i] >= 0)
                a.push_back(nums[i]);
            else
                b.push_back(nums[i]);
        } // --> CLOSED THE FOR LOOP HERE!

        int N = a.size();
        int M = b.size();

        // 2. Square both arrays
        for(int i = 0; i < N; i++) {
            a[i] = a[i] * a[i];
        }
        for(int i = 0; i < M; i++) {
            b[i] = b[i] * b[i]; 
        }

        // 3. Reverse the negative squares so they are sorted ascending
        reverse(b.begin(), b.end());

        // 4. Merge the two sorted arrays back into nums
        int i = 0; // Pointer for a
        int j = 0; // Pointer for b
        int id = 0; // Pointer for nums

        while(i < N && j < M) {
            if(a[i] < b[j]) {
                nums[id] = a[i];
                i++;
            } else {
                nums[id] = b[j];
                j++;
            }
            id++;
        }
        
        while(i < N) {
            nums[id] = a[i];
            i++;
            id++;
        } 
        
        while(j < M) {
            nums[id] = b[j];
            j++;
            id++;
        } 

        // 5. Actually return the result!
        return nums;
    }   
};