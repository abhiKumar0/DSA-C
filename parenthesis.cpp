#include <iostream>
#include <stack>

using namespace std;

int match(char a, char b){
  if (a =='(' && b == ')') return 1;
  if (a =='{' && b == '}') return 1;
  if (a =='[' && b == ']') return 1;
  return 0;
}

bool validParentheses(string s) {
  stack<char> st;
  char p;
  for (int i = 0; i < s.size(); i++) {
    if ( s[i] == '(' || s[i] == '{' || s[i] == '[' ){
      st.push(s[i]);
    } 
    else if (s[i] == ')' || s[i] == '}' || s[i] == ']'){ 
      if (st.empty()) return false;

      p = st.top();
      st.pop(); 

      if (!match(p, s[i])) return false;
      
    }
  }
  if (st.empty()) {
    return true;
  }
  return false;
}

int countParentheses(string s) {
  stack<char> st;
  char p;
  int count = 0;
  for (int i = 0; i < s.size(); i++) {
    if ( s[i] == '(' || s[i] == '{' || s[i] == '[' ){
      st.push(s[i]);
    } 
    else if (s[i] == ')' || s[i] == '}' || s[i] == ']'){ 
      if (!st.empty()) {
        p = st.top();
        st.pop();
        if (match(p, s[i])){
          count++;
          continue;
        }
      }
      
    }
  }
  return count;
}

int main()
{
  string s = "(()";
  // bool a = validParentheses(s);
  // if (validParentheses(s))
  //   cout <<"It is valid"<<endl;
  // else
  //   cout <<"It's not valid"<<endl;
  cout <<countParentheses(s)<<endl;
  return 0;
}