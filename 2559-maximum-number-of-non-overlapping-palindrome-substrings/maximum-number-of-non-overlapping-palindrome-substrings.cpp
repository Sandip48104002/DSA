class Solution {
public:
    int maxPalindromes(string s, int k) {
        int n = s.length();
        int ans = 0 , end = -1;
        for(int i=0; i<n; i++){
            for( int left: {i-1, i}){  
                int right = i;
                while(left >=0 && right < n && s[left]==s[right]){
                    if(right-left+1>= k && left > end){
                        ans++;
                        end=right;
                        break;
                    }
                    left--;
                    right++;
                }
            }
        }
        return ans;

    }
};