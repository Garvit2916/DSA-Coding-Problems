class Solution {
public:
    int maxLength(vector<int>& nums) {
        int n = nums.size();
        int ans = 1;

        for(int i = 0; i < n; i++) {
            for(int j = i; j < n; j++) {
                bool ok = true;

                if(j - i + 1 >= 3) {
                    for(int a = i; a <= j; a++) {
                        for(int b = a + 1; b <= j; b++) {
                            if(gcd(nums[a], nums[b]) != 1) {
                                ok = false;
                                break;
                            }
                        }

                        if(!ok)
                            break;
                    }
                }

                if(ok)
                    ans = max(ans, j - i + 1);
            }
        }

        return ans;
    }
};