class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n=s.size();
        int low=0,high=0;
        int res=INT_MIN;
        unordered_map<char,int>f;
        for(int high=0;high<n;high++){
            f[s[high]]++;
            int k=high-low+1;
            while(f.size()<k){
                f[s[low]]--;
                if(f[s[low]]==0){
                    f.erase(s[low]);
                }
                low++;
                k=high-low+1;
            }
            int len=high-low+1;
            res=max(res,len);
        }
        if(res==INT_MIN)
        return 0;
        

        return res;

        
        
    }
};