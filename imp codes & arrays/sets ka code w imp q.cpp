//question is like->
/*
Input: nums = [100,4,200,1,3,2]
Output: 4
Explanation: The longest consecutive elements sequence is [1, 2, 3, 4]. Therefore its length is 4.
*/
//we store all the ele in a set, and then we check for conseutive numbers like if 1234 is there in the set, 
//lets assume first we get 3, so we check the prev ele first, if 2 exists then we dont do anything, skip the ele go nect, 
//like that we go till 1, and check if 0 is there, if it is not there, then we check for 2, then 3 and then we update the length
// ka count we increase and return


/*
st.find(x):

If x is in the set → returns an iterator pointing to x.

If x is not in the set → returns st.end() (a special iterator meaning "not found").
*/
/*
if (st.find(it - 1) == st.end())
means:

"If (current number - 1) is not in the set, then it is the start of a new sequence."*/

class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int n=nums.size();
        if(n==0) return 0;
        int longest=1;
        unordered_set<int> st;
        for(int i=0;i<n;i++) st.insert(nums[i]);
        for(auto it:st){
            if(st.find(it-1)==st.end()){
                int count=1;
                int x=it;
                while(st.find(x+1) !=st.end()){
                    x=x+1;
                    count=count+1;
                }
                longest=max(longest,count);
            }
        }
        return longest;
    }
};