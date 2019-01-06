class Solution {
public:
    string addStrings(string num1, string num2) {
        stack<int> s1;
        stack<int> s2;
        for (int i = 0; i < num1.size(); i++) {
            s1.push(num1[i]-'0');
        }
        for (int i = 0; i < num2.size(); i++) {
            s2.push(num2[i]-'0');
        }
         int carry = 0;
         int sum = 0;
 
         stack<int> s3;
 
         while(!s1.empty() || !s2.empty())
         {
             int num1 = 0;
             int num2 = 0;
             sum = 0;
             if(!s1.empty())
             {
                 num1 = s1.top();
                 s1.pop();
             }
 
             if(!s2.empty())
             {
                 num2 = s2.top();
                 s2.pop();
             }
 
             sum = num1 + num2 + carry;
             if(sum >= 10)
             {
                 carry = 1;
                 sum = sum%10;
             }
             else
             {
                 carry = 0;
             }
 
             s3.push(sum);
         }
 
         if(carry != 0)
         {
             s3.push(carry);
         }
        string ans;
        while(!s3.empty())
        {
             ans+=to_string(s3.top());
             s3.pop();
        }
        return ans;
    }
};
//the fatest method
class Solution {
public:
    string 
    addStrings(string num1, string num2) 
    {
        int difference = 0;
        std::string longString = "";
        std::string shortString = "";
        if (num1.size()>=num2.size())
        {
            difference = num1.size()-num2.size();
            longString = num1;
            shortString.resize(difference, '0');
            shortString = shortString + num2;
        }
        else
        {
            difference = num2.size()-num1.size();
            longString = num2;
            shortString.resize(difference, '0');
            shortString = shortString + num1;
        }
        
        
        int carryOut = 0;
        int i = longString.size()-1;
        for (; i>=0; --i)
        {
            longString[i] = longString[i]+shortString[i]-48+carryOut;
            if (longString[i]>=58)
            {
                carryOut = 1;
                longString[i]-=10;
            }
            else carryOut = 0;
        }
        if (carryOut==1 && i<0)
        {
            longString = '1'+longString;
        }
        
        
        return longString;
    }
};
