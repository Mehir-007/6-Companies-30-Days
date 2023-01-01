/*
150. Evaluate Reverse Polish Notation

You are given an array of strings tokens that represents an arithmetic expression in a Reverse Polish Notation.

Evaluate the expression. Return an integer that represents the value of the expression.

Note that:

The valid operators are '+', '-', '*', and '/'.
Each operand may be an integer or another expression.
The division between two integers always truncates toward zero.
There will not be any division by zero.
The input represents a valid arithmetic expression in a reverse polish notation.
The answer and all the intermediate calculations can be represented in a 32-bit integer.
Example 1:

Input: tokens = ["2","1","+","3","*"]
Output: 9
Explanation: ((2 + 1) * 3) = 9
Example 2:

Input: tokens = ["4","13","5","/","+"]
Output: 6
Explanation: (4 + (13 / 5)) = 6
*/

#include<bits/stdc++.h>
using namespace std;


int evalRPN(vector<string>& tokens) {
        stack<int> s;
        for(int i=0;i<tokens.size();i++)
        {
            if(tokens[i]=="*" || tokens[i]=="-" || tokens[i]=="+" ||tokens[i]=="/")
            {
                int x=s.top();s.pop();
                int y=s.top();s.pop();int z;
                if(tokens[i]=="*")
                {
                    z=x*y;
                }
                else if(tokens[i]=="+")
                {
                    z=x+y;
                }
                else if(tokens[i]=="-")
                {
                    z=y-x;
                }
                else if(tokens[i]=="/")
                {
                    z=y/x;
                }
                s.push(z);

            }
            else
            {
                int num=stoi(tokens[i]);
                
                s.push(num);
            }
        }
        return s.top();
}
int main()
{
    vector<string> v={"4","13","5","/","+"};
    cout<<evalRPN(v);
}