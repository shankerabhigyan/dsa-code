class Solution {
public:
    int myAtoiHelper(string& s, int i, long result, int sign) {
        if (i >= s.length() || !isdigit(s[i])) {
            return static_cast<int>(result * sign);
        }

        result = result * 10 + (s[i] - '0');

        if (result * sign >= INT_MAX) return INT_MAX;
        if (result * sign <= INT_MIN) return INT_MIN;

        return myAtoiHelper(s, i + 1, result, sign);
    }
    int myAtoi(string s) {
        int i = 0, n = s.length();
        long result = 0;
        int sign = 1;

        while (i < n && s[i] == ' ') {
            i++;
        }

        if (i < n && (s[i] == '-' || s[i] == '+')) {
            sign = (s[i] == '-') ? -1 : 1;
            i++;
        }

        return myAtoiHelper(s, i, result, sign);
    }
};