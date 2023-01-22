#include<iostream>
#include<string>
#include<vector>
#include<stack>
using namespace std;

int evaluateRPN(vector<string>& tokens)
{
    stack<int> nums;
    for(string s: tokens)
    {
        if(isdigit(s[s.length()-1]))
        {
            nums.push(stoi(s));
        }
        else{
            char ch=s[0];
            int num1=nums.top();
            nums.pop();
            int num2=nums.top();
            nums.pop();
            cout<<ch<<" on"<<num1<<" "<<num2<<endl;
            
            if(ch=='+') nums.push(num1+num2);
            else if(ch=='-') nums.push(num2-num1);
            else if(ch=='*') nums.push(num1*num2);
            else if(ch=='/') nums.push(num2/num1);
        } 
    }
    return nums.top();
}
int main()
{
    vector<string> v{"10","6","9","3","+","-11","*","/","*","17","+","5","+"};
    cout<<evaluateRPN(v)<<endl;
    return 0;
}
