#include <bits/stdc++.h>
using namespace std;

string prefixToInfix(string exp)
{
  stack<string> store;
  for (int i = exp.length() - 1; i >= 0; i--)
  {
    if (ispunct(exp[i]))
    {
      string op1 = store.top();
      store.pop();
      string op2 = store.top();
      store.pop();
      store.push("(" + op1 + exp[i] + op2 + ")");
    }
    else
    {
      store.push(exp.substr(i, 1));
    }
  }
  return store.top();
}

string prefixToPostfix(string exp)
{
  stack<string> store;
  for (int i = exp.length() - 1; i >= 0; i--)
  {
    if (ispunct(exp[i]))
    {
      string op1 = store.top();
      store.pop();
      string op2 = store.top();
      store.pop();
      store.push(op1 + op2 + exp[i]);
    }
    else
    {
      store.push(exp.substr(i, 1));
    }
  }
  return store.top();
}

string PostfixToPrefix(string exp)
{
  stack<string> store;
  for (int i = 0; i < exp.length(); i++)
  {
    if (ispunct(exp[i]))
    {
      string op1 = store.top();
      store.pop();
      string op2 = store.top();
      store.pop();
      store.push(exp[i] + op2 + op1);
    }
    else
    {
      store.push(exp.substr(i, 1));
    }
  }
  return store.top();
}

string postfixToInfix(string exp)
{
  stack<string> store;
  for (int i = 0; i < exp.length(); i++)
  {
    if (ispunct(exp[i]))
    {
      string op1 = store.top();
      store.pop();
      string op2 = store.top();
      store.pop();
      store.push("(" + op2 + exp[i] + op1 + ")");
    }
    else
    {
      store.push(exp.substr(i, 1));
    }
  }
  return store.top();
}

int main(int argc, char const *argv[])
{

  string prefixInput = "*-A/BC-/AKL";
  cout << prefixToInfix(prefixInput) << endl;
  cout << prefixToPostfix(prefixInput) << endl;
  cout << PostfixToPrefix(prefixToPostfix(prefixInput)) << endl;
  cout << postfixToInfix(prefixToPostfix(prefixInput)) << endl;
  return 0;
}
