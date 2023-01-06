#include <iostream>
#include <string>
#include <sstream>
using namespace std;

class mc{
  public:
    string input;
    string no1 = "";
    string op = "";
    string no2 = "";
    int op1 = 0;
    int op2 = 0;

    void add (int op1, int op2){
      int result = op1 + op2;
      cout << "Result = " << result << "\n";
    }

    void sub (int op1, int op2){
      int result = op1 - op2;
      cout << "Result = " << result << "\n";
    }

    void mul (int op1, int op2){
      int result = op1 * op2;
      cout << "Result = " << result << "\n";
    }

    void div (int op1, int op2){
      int result = op1 / op2;
      cout << "Result = " << result << "\n";
    }

    void split (string input){
      int count = 0;
      for (int i = 0; i <= input.length(); i++){

        if (input[i] == ' '){
          count += 1;

        }
        else{
          if (count == 0){
            no1.push_back(input[i]);
          }
          else if (count == 1){
            op.push_back(input[i]);
          }
          else{
            no2.push_back(input[i]);
          }
        }
      }
    }

    void convert (string no1, string no2){
      stringstream num1(no1);
      stringstream num2(no2);
      num1 >> op1;
      num2 >> op2;
    }
};

int main()
{
  mc n;

  while (1){
    getline (cin, n.input);
    n.split(n.input);
    n.convert(n.no1, n.no2);

    if (n.op == "+"){
      n.add(n.op1, n.op2);
    }
    else if (n.op == "-"){
      n.sub(n.op1, n.op2);
    }
    else if (n.op == "*"){
      n.mul(n.op1, n.op2);
    }
    else if (n.op == "/"){
      n.div(n.op1, n.op2);
    }
    else {
      cout << "invalid operator";
    }

    cout << "\n\n";
    n.input = "";
    n.no1 = "";
    n.op = "";
    n.no2 = "";
    n.op1 = 0;
    n.op2 = 0;
  }
}
