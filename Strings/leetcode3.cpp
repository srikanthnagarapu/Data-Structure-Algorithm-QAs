/**
    Example 1:

    Input: s = "abcabcbb"
    Output: 3
    Explanation: The answer is "abc", with the length of 3.
    Example 2:

    Input: s = "bbbbb"
    Output: 1
    Explanation: The answer is "b", with the length of 1.
    Example 3:

    Input: s = "pwwkew"
    Output: 3
    Explanation: The answer is "wke", with the length of 3.
    Notice that the answer must be a substring, "pwke" is a subsequence and not a substring.
 */

 /**

    Approaches 1 : Brute Force checking all the permutations and also check max lenght of non visited chars
    Approaches 2 : Sliding window with 2 pointers Left , Right 
  */
// Approache 2 Solution
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        
        // unordered set is to check any visited char 
        unordered_set<char> visited;
        int left = 0, maxLength = 0;
        // taking two pointer Right at 0 and left is at 0
        for(int right = 0; right<s.length(); right++) {

            // check any visited char if visited then move left to that poistion of right
            while(visited.find(s[right]) != visited.end()) {
                visited.erase(s[left]); // removes all the visited till now
                left++;
            }

            // not visited then insert into set
            visited.insert(s[right]);
            // calculate max lenght of the string why left +1 because of left start at index 0 so
            /**
                Example left is index 0 and right is at index 2 
                length should be 3 but if we do right-left = 2 so left +1 gives us crct string length
             */

            maxLength = max(maxLength, right-left+1);
        }
        return maxLength;
    }
};