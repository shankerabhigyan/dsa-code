#include<iostream>
#include<math.h>
using namespace std;

int BinaryToDecimal(string n){
    int answer = 0;
    int power = 0;
    for (int i = n.length()-1; i >= 0; i--){
        if (n[i] == '1'){
            answer += pow(2, power);
        }
        power++;
    }
    return answer;
}

int DecimalToBinary(int n){
    int answer =0;
    int power = 0,bit=0;
    while(n!=0)
    {
        bit = n&1;
        answer += bit*pow(10, power++);
        n = n>>1;
    }
    return answer;
}
int main(){
    //Uncomment this block to test BinaryToDecimal
    /* 
    string n;
    cin >> n;
    int ans =0;
    ans = BinaryToDecimal(n);
    cout << ans << endl;
    */

    //Uncomment this block to test DecimalToBinary
    /*
    int n,ans=0;
    cin >> n;
    ans = DecimalToBinary(n);
    cout << ans << endl;
    */

    return 0;
}