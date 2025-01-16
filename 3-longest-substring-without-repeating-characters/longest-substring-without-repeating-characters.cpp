// class Solution {
// public:
//     int lengthOfLongestSubstring(string s) {
//         unordered_set<char> charSet;
//         int l = 0;
//         int res = 0;

//         for (int r = 0; r < s.size(); r++) {
//             while (charSet.find(s[r]) != charSet.end()) {
//                 charSet.erase(s[l]);
//                 l++;
//             }
//             charSet.insert(s[r]);
//             res = max(res, r - l + 1);
//         }
//         return res;
//     }
// };

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char, int> mp;
        int l = 0, res = 0;
        
        for (int r = 0; r < s.size(); r++) {
            if (mp.find(s[r]) != mp.end()) {
                l = max(mp[s[r]] + 1, l);
            }
            mp[s[r]] = r;
            res = max(res, r - l + 1);
        }
        return res;
    }
};