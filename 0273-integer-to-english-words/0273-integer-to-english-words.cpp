class Solution {
public:
    //below10 numbers
    unordered_map<int,string>below10= {
            {0,""},
            {1, "One"},
            {2, "Two"},
            {3, "Three"},
            {4, "Four"},
            {5, "Five"},
            {6, "Six"},
            {7, "Seven"},
            {8, "Eight"},
            {9, "Nine"}
        };
        unordered_map<int,string>below20={
            {10, "Ten"},
            {11, "Eleven"},
            {12, "Twelve"},
            {13, "Thirteen"},
            {14, "Fourteen"},
            {15, "Fifteen"},
            {16, "Sixteen"},
            {17, "Seventeen"},
            {18, "Eighteen"},
            {19, "Nineteen"}
        };
        unordered_map<int,string>below100={
            {1,"Ten"},
            {2, "Twenty"},
            {3, "Thirty"},
            {4, "Forty"},
            {5, "Fifty"},
            {6, "Sixty"},
            {7, "Seventy"},
            {8, "Eighty"},
            {9, "Ninety"}
        };
    // solved using recursion
    // num<1e2 // Eighty 
    // num<1e3 hundred
    // num<1e5 thousand
    // num<1e9  million
    // num>=1e9 billion
    string solve(int num ){
        if(num<10){
            return below10[num];
        }
        if(num<20){  
            return below20[(num)];
        }
        if(num<100){  // 89 
            return below100[(num/10)] +((num%10!=0)? " "+below10[num%10]:"");
        }
        if(num<1000){ // 765/100  // Hundred
            return solve(num/100)+" Hundred" +((num%100!=0)? " "+solve(num%100):"");
        }
        if(num<1000000){ // 797965/1000  // thousand
            return solve(num/1000)+" Thousand" +((num%1000!=0)? " "+solve(num%1000):"");
        }
        if(num<1000000000){ // 27999865/1000000  // Million
            return solve(num/1000000)+" Million" +((num%1000000!=0)? " "+solve(num%1000000):"");
        }
        return solve(num/1000000000)+" Billion" +((num%1000000000!=0)? " "+solve(num%1000000000):"");
    }

    string numberToWords(int num) {
       if(num==0)return "Zero";
       return solve(num);
    }
};