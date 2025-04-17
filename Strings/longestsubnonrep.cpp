/**
Given a string s, find the length of the longest substring without duplicate characters.

 

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

class Solution {
    public:
    int lengthOfLongestSubstring(string s){
        unorderd_set<char> visited;
        int left, maxlen = 0;
        for(int right = 0; right<s.length(); right++){
            //check if visited then clear all
            while(visited.find(s[right]) != visited.end()){
                visited.erase(s[left]);
                left++;
            }
            visited.insert(s[right]);
            maxlen = max(maxlen, right-left+1);
        }
        return maxlen;
    }
}