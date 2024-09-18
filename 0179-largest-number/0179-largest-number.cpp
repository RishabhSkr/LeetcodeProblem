class Solution {
public:
/*
    We use a.b to represent the concatenation of non-negative integers a and b .

Theorem:

Let a, b, and c be non-negative integers. If a.b > b.a and b.c > c.b , we have a.c > c.a .

Proof:

We use [a] to denote the length of the decimal representation of a . For example, if a = 10 , we have [a] = 2 .

Since a.b > b.a and b.c > c.b , we have

a * 10^[b] + b > b * 10^[a] + a
b * 10^[c] + c > c * 10^[b] + b

, which is equivalent to

a * (10^[b] - 1) > b * (10^[a] - 1)
b * (10^[c] - 1) > c * (10^[b] - 1)

Obviously, 10^[a] - 1 > 0 , 10^[b] - 1 > 0 , and 10^[c] - 1 > 0 . Since c >= 0 , according to the above inequalities, we know that b > 0 and a > 0 . After multiplying the above two inequalities and cancelling b and (10^[b] - 1) , we have

a * (10^[c] - 1) > c * (10^[a] - 1)

This is equivalent to

a * 10^[c] + c > c * 10^[a] + a

, which means a.c > c.a .
*/
    static bool compare(int &a,int &b){
        return to_string(a)+to_string(b)>to_string(b)+to_string(a);
    }
    string largestNumber(vector<int>& nums) {
        sort(nums.begin(),nums.end(),compare);
        string ans = "";
        
        for(auto x:nums){
            ans+=to_string(x);
        }
        if(ans[0]=='0')return "0";
        return ans;
    }
};