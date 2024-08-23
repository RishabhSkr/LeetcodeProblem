class Solution {
public:
    int findGCD(int a,int b){
        if(a==0)return b;
        return findGCD(b%a,a);
    }
    string fractionAddition(string exp) {
        stack<pair<int, int>> st;
        int n = exp.size();
        
        int i = 0;
        while (i < n) {
            int sign = 1;
            if (exp[i] == '-') {
                sign = -1;
                i++;
            } else if (exp[i] == '+') {
                i++;
            }

            // Extract numerator
            int num = 0;
            while (i < n && isdigit(exp[i])) {
                num = num * 10 + (exp[i] - '0');
                i++;
            }
            num *= sign;
            i++; // Skip the '/'

            // Extract denominator
            int denom = 0;
            while (i < n && isdigit(exp[i])) {
                denom = denom * 10 + (exp[i] - '0');
                i++;
            }

            if (st.empty()) {
                st.push({num, denom});
            } else {
                auto [prevNum, prevDenom] = st.top();
                st.pop();

                // Find common denominator
                int commonDenom = prevDenom * denom;
                int newNum = prevNum * denom + num * prevDenom;

                // Simplify the fraction
                int gcd = findGCD(abs(newNum), commonDenom);
                newNum /= gcd;
                commonDenom /= gcd;

                st.push({newNum, commonDenom});
            }
        }

        // The result is in the stack
        auto [finalNum, finalDenom] = st.top();
        return to_string(finalNum) + "/" + to_string(finalDenom);
    }
};