class Solution {
public:
    int getLucky(string s, int k) {
        string transformed; //numberic value of string
        // s = abc
        for(char c : s)
        {
            transformed += to_string(c - 'a' + 1); // it will convert to numberic
            //transformed = 123
        }

        while(k--){
            int sumString = 0;
            for(char digit : transformed)
            {
                sumString += digit - '0'; // 1+2+3 = 6
            }
            transformed = to_string(sumString);
        }
        return stoi(transformed);
    }
};