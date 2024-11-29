"""
Have the function StringChallenge(strArr) read the array of strings stored in strArr, which will contain two elements, 
the first will be a decimal number and the second element will be a binary number. 
Your goal is to determine how many digits in the binary number need to be changed to represent the decimal number correctly 
(either 0 change to 1 or vice versa).
For example: if strArr is ["56", "011000"] then your program should return 1 
because only 1 digit needs to change in the binary number (the first zero needs to become a 1) 
to correctly represent 56 in binary.

Input: ["5624", "0010111111001"]
Output: 2
Input: ["44", "111111"]
Output: 3
"""

def stringChallenge(strArr):
    decimal_number = int(strArr[0])
    binary_number = strArr[1]
    
    # Convert the decimal number to binary and remove the '0b' prefix
    binary_representation = bin(decimal_number)[2:]
    
    # Pad the binary number with leading zeros if necessary
    max_length = max(len(binary_representation), len(binary_number))
    binary_representation = binary_representation.zfill(max_length)
    binary_number = binary_number.zfill(max_length)
    
    # Count the number of differing bits
    changes_needed = sum(1 for a, b in zip(binary_representation, binary_number) if a != b)
    
    return changes_needed

print(stringChallenge(["5624", "0010111111001"])) # 2
print(stringChallenge(["44", "111111"])) # 3