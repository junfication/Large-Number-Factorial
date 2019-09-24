#include <string>
#include <algorithm>
#include <iostream>
#include <limits>

std::string multiply(std::string s, int coeff)
{
    std::string result;
    result.resize(s.size());
    int carry = 0;
    for(int i = 0; i < s.size(); ++i)
    {
        std::string numString;
        numString.push_back(s[i]);
        int num = std::stoi(numString);
        num *= coeff;
        if(carry) num += carry;
        int val = num % 10;
        carry = num / 10;
        result[i] = std::to_string(val)[0];
    }
    while(carry)
    {
      int val = carry % 10;
      carry /= 10;
      result.push_back(std::to_string(val)[0]);
    }
    return result;
}

// Complete the extraLongFactorials function below.
void extraLongFactorials(int n) 
{
    std::string result;
    result.push_back('1');
    for(int i = 1; i <= n; ++i)
    {
        result = multiply(result, i);
    }
    std::reverse(result.begin(), result.end());
    std::cout << result << std::endl;
}

int main()
{
    int n;
    std::cin >> n;
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    extraLongFactorials(n);

    return 0;
}