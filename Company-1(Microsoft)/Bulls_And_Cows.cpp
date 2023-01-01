/*
299. Bulls and Cows

You are playing the Bulls and Cows game with your friend.

You write down a secret number and ask your friend to guess what the number is. When your friend makes a guess, 
you provide a hint with the following info:

The number of "bulls", which are digits in the guess that are in the correct position.
The number of "cows", which are digits in the guess that are in your secret number but are located in the wrong position. 
Specifically, the non-bull digits in the guess that could be rearranged such that they become bulls.
Given the secret number secret and your friend's guess guess, return the hint for your friend's guess.

The hint should be formatted as "xAyB", where x is the number of bulls and y is the number of cows. 
Note that both secret and guess may contain duplicate digits.

 

Example 1:

Input: secret = "1807", guess = "7810"
Output: "1A3B"
Explanation: Bulls are connected with a '|' and cows are underlined:
"1807"
  |
"7810"


Example 2:

Input: secret = "1123", guess = "0111"
Output: "1A1B"
Explanation: Bulls are connected with a '|' and cows are underlined:
"1123"        "1123"
  |      or     |
"0111"        "0111"
Note that only one of the two unmatched 1s is counted as a cow since the non-bull digits can only be rearranged to allow one 1 to be a bull.299. Bulls and Cows

*/

#include<bits/stdc++.h>
using namespace std;

string getHint(string secret, string guess) {
        
        int n=secret.length();string ans="";
        vector<int> s(10,0);vector<int> g(10,0);
        
        for(int i=0;i<n;i++)
        {
            s[secret[i]-'0']++;
            g[guess[i]-'0']++;
        }
        int c=0;int d=0;
        if(s==g)
        {
            for(int i=0;i<n;i++)
            {
                if(secret[i]==guess[i])
                    c++;
                else
                    d++;
            }
            ans=ans+to_string(c)+'A'+to_string(d)+'B';
        }
        else
        {
            int common=0;
            for(int i=0;i<10;i++)
            {
                if(s[i]>0 && g[i]>0)
                    common+=min(s[i],g[i]);
            }
            for(int i=0;i<n;i++)
            {
                if(secret[i]==guess[i])
                    c++;
            }
            d=common-c;
            ans=ans+to_string(c)+'A'+to_string(d)+'B';
        }
        return ans;
        
}

int main(){
    string secret = "1807", guess = "7810";
    cout<<getHint(secret,guess);
}