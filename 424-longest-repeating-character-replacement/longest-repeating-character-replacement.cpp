class Solution {
public:
    int find(vector<int>& a) {
        int maxc = -1;
        for (int i = 0; i < 256; i++)
            maxc = max(maxc, a[i]);
        return maxc;
    }

    int characterReplacement(string s, int k) {
        int n = s.size();
        int high = 0;
        int low = 0;
        int res = INT_MIN;

        vector<int> f(256, 0);
        for (int high = 0; high < n; high++) {
            f[s[high]]++;
            int len = high - low + 1;
            int max_count = find(f);

            int diff = len - max_count;

            while (diff > k) {
                f[s[low]]--;
                low++;
                max_count = find(f);
                len = high - low + 1;
                diff = len - max_count;
            }

            // diff<k or diff=k , so both condition are true.
            len = high - low + 1;
            res = max(len, res);
        }

        return res;
    }
};