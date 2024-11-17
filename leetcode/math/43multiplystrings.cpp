#include<bits/stdc++.h>
using namespace std;

void printVector(const vector<int>& vec) {
    for (const auto& str : vec) {
        cout << str << " ";
    }
    cout << endl;
}

class Solution{
    public:
    string multiply(string num1, string num2){
        int l1 = num1.length();
        int l2 = num2.length();
        string sum = "";
        vector<string> vec(l1);
        for(int x = l1-1; x>=0; x--){
            sum="";
            int carry=0;
            for(int y=l2-1;y>=0;y--){
                int a = num1[x] - 48;
                int b = num2[y] - 48;
                int m = a*b + carry;
                sum = char(m%10 + '0') + sum;
                carry = m/10;
            }
            if(carry>0){
                sum = char(carry%10 + '0') + sum;
            }
            string sub(l1-x-1, '0');
            sum = sum+sub;
            vec[x]=sum;
        }
        //printVector(vec);
        string ans = "";
        int i = 0;
        int carry = 0;
        while(true){
            int x = 0;
            bool mark = false;
            for(string num:vec){
                if(i<num.length()){
                    x+=num[num.length()-i-1]-48;
                    mark = true;
                }
            }
            if(!mark){
                if(carry>0){
                    ans = char(carry+'0') + ans;
                }
                break;
            }
            x+=carry;
            ans = char(x%10+'0') + ans;
            carry = x/10;
            i++;
        }
        
        return ans[0]=='0'? "0":ans;
    }
};

// BETTER SOLUTION

class Solution2 {
public:
    string multiply(string num1, string num2) {
        if (num1 == "0" || num2 == "0") return "0";
        
        // Result can't be longer than the sum of lengths
        vector<int> result(num1.length() + num2.length(), 0);
        
        // Calculate partial products directly into result array
        for (int i = num1.length() - 1; i >= 0; i--) {
            for (int j = num2.length() - 1; j >= 0; j--) {
                int digit1 = num1[i] - '0';
                int digit2 = num2[j] - '0';
                
                int pos1 = i + j;
                int pos2 = i + j + 1;
                
                int product = digit1 * digit2 + result[pos2];
                
                result[pos2] = product % 10;
                result[pos1] += product / 10;
                printVector(result);
            }
        }
        
        // Convert result to string, skipping leading zeros
        string answer;
        bool leadingZero = true;
        for (int digit : result) {
            if (digit != 0) leadingZero = false;
            if (!leadingZero) answer += (digit + '0');
        }
        
        return answer.empty() ? "0" : answer;
    }
};

int main() {
    string num1, num2;
    cin >> num1;
    cin >> num2;

    Solution2 sol;
    string result = sol.multiply(num1, num2);
    cout << result << endl;

    return 0;
}