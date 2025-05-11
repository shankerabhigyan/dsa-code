# https://leetcode.com/problems/fraction-to-recurring-decimal/description/?envType=problem-list-v2&envId=math

class Solution:
    def fractionToDecimal(self, numerator: int, denominator: int) -> str:
        if numerator%denominator==0:
            return str(numerator//denominator)
        
        sign = numerator>0 and denominator>0

        numerator, denominator = abs(numerator), abs(denominator)

        integer = numerator // denominator

        result = "-" if not sign else ""
        result += str(integer)+"."

        remainder = numerator%denominator
        remainders = {}
        decimal_part = []

        while remainder!=0:
            if remainder in remainders:
                idx = remainders[remainder]
                decimal_part.insert(idx,"(")
                decimal_part.append(")")
                break
            remainders[remainder] = len(decimal_part)
            remainder*=10
            digit = remainder//denominator
            decimal_part.append(str(digit))
            remainder%=denominator
        
        return result + "".join(decimal_part)

