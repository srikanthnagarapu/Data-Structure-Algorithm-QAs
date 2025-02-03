/**

You are given a string s and an integer k. You can choose any character of the string and change it to any other uppercase English character. You can perform this operation at most k times.

Return the length of the longest substring containing the same letter you can get after performing the above operations.

 

Example 1:

Input: s = "ABAB", k = 2
Output: 4
Explanation: Replace the two 'A's with two 'B's or vice versa.
Example 2:

Input: s = "AABABBA", k = 1
Output: 4
Explanation: Replace the one 'A' in the middle with 'B' and form "AABBBBA".
The substring "BBBB" has the longest repeating letters, which is 4.
There may exists other ways to achieve this answer too.
 */

/**
    Approach 1: Brute Force 
    Approach 2: Sliding window + two pointers 
 */

class Solution {
public:
    int characterReplacement(string s, int k) {
        int maxLen = 0, int left = 0, right = 0, maxOccurence = 0;
        // array to check occurence of chars
        vector<int> occurence(26, 0);

        while(right != s.length()) {
            // check maxOccurence
            // Formula : Length - maxOccurence <= k 
             /**
                Length is between right and left
                maxOccurence of chars 
                if formula is not found then 
                decrease occurence and increase left pointer
              */
            int length = right-left+1;
            
            maxOccurence = max(maxOccurence,++occurence[s[right]-'A']);
            
            if(length - maxOccurence <= k) {
                // continue;
            } else {
                left++;
                --occurence[s[left]-'A'];
            }
            
            maxLen = max(maxLen, right-left+1);

            // Pointers increase 
            right++;
        }

        return maxLen;
    }
};