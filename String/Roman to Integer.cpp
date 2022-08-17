class Solution {
public:
    int romanToInt(string s) {
        map<char, int> table;
        table['I'] = 1;
        table['V'] = 5;
        table['X'] = 10;
        table['L'] = 50;
        table['C'] = 100;
        table['D'] = 500;
        table['M'] = 1000;
        
        if(s.empty()){
            return 0;
        }
        int sum = table[s[s.length()-1]];
        for(int i=s.length()-2; i>=0; i--){
            if(table[s[i]] < table[s[i+1]]){
                sum -= table[s[i]];
            }else{
                sum += table[s[i]];
            }
        }
        
        return sum;
    }
};