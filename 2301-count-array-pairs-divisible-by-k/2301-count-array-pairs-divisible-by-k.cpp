class Solution {
public:
/*
    Intuition
Let's first understand this property:

If (a*b)%k==0, then
gcd(a,k) * gcd(b,k) % k is also 0

Let’s assume two numbers 504 and 819. Their prime factorization can be written as:

504 = (2^3) * (3^2) * 7
819 = (3^2) * 7 * 13

Now gcd(504,819) = 63 and 63 = (3^2) * 7

gcd(a,b) is the multiplication of common prime factors of a and b.

Coming back to the statement
How gcd(a,k) * gcd(b,k) % k is 0 ?

For any number to be divisble by k it need to have atleast all the prime factors of k.

gcd(a,k) = Multiplication of all prime factors of k available in a.
and
gcd(b,k) = Multiplication of all prime factors of k available in b.

If gcd(a,k) * gcd(b,k) % k is 0, it means some of the prime factors of k are contributed by a and some of the prime factors of k are contributed by b and thier multiplication has all the prime factors of k which means a*b is divisble by k.

We dont care about prime factors of a or b which are not prime factors of k because they will not help us in making a*b divisible by k.

Example:

Let k=84, a=24, b=273

k = 84 = (2^2) * 3 * 7
a = 24 = (2^3) * 3
b = 273 = 3 * 7 * 13

gcd(a,k) = (2^2) * 3 (Common prime factors of a and k)
gcd(b,k) = 7 * 3 (Common prime factors of b and k)

gcd(a,k) * gcd(b,k) = (2^2) * (3^2) * 7
which has all prime factors of k thus a*b is divisble by k.
*/
// LearNing : for a number to be divisible by k prime factorization must be present in num;
    #define ll long long

    int getGCD(int a,int b){
        if(a==0)return b;
        return getGCD(b%a,a);
    }
     ll countPairs(vector<int>& nums, int k) {
       ll ans = 0;
       ll n = nums.size();
       unordered_map<int,int>mp;
       for(ll i = 0;i<n;++i){
            ll curr_gcd = getGCD(nums[i],k);
            for(auto [prev_gcd ,freq]: mp){
                if((curr_gcd*prev_gcd)%k==0)ans+=freq;
            }
            mp[curr_gcd]++;

       }
       return ans;
    }
};