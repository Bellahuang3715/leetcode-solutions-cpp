class Solution {
public:
    string addBinary(string a, string b) {
        string result = "";
        int aPtr = a.length() - 1, bPtr = b.length() - 1;
        int carry = 0;
        
        while (aPtr >= 0 || bPtr >= 0 || carry)
        {
            int sum = carry;
            if (aPtr >= 0) sum += a[aPtr--] - '0';    // - '0' converts char to int
            if (bPtr >= 0) sum += b[bPtr--] - '0';
            
            carry = sum / 2;
            result += (sum % 2) + '0';   // + '0' converts int to char
        }
        
        reverse(result.begin(), result.end());
        return result;
    }
};