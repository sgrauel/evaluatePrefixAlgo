/*
On my honor,
The following program is a result of personal effort. I have not discussed with
anyone other than my instructor or any appropriate person in charge of the class.
I have not used, or slightly modified code or portion of code from another
student, or an unauthorized source.
If any C++ language code or documentation used in my program was obtained from
another source, such as a textbook or course notes, that has been clearly noted
with a proper citation in the comments of my program.
I have not designed this program in such a way as to defeat or interfere with the
normal operation of the eniac system or cslab machines at Hunter College.
Sincerely,
- Shawn M. Grauel
*/

/*

USAGE: after compiling and creating a binary please pass in arguments
at the command-line as follows:

./a.out <arg1> <arg2> ... <argN>

where arguments are assumed to be operators followed by operands in
polish notation. Operands can only be integers as the implementation
is non-generic for simplicity's sake.
*/

#include <stack>
#include <iostream>
#include <cstdlib>
#include <sstream>
#include <cstring>

using namespace std;

bool isOperator(char* oper) {
  if (strcmp(oper,"*") == 0) return true;
  if (strcmp(oper,"+") == 0) return true;
  if (strcmp(oper,"-") == 0) return true;
  if (strcmp(oper,"/") == 0) return true;
  else return false;
}

int evaluate(char* oper,char* oper1, char* oper2) {
  
  stringstream ss1(oper1);
  stringstream ss2(oper2);
  
  int oper1Num;
  int oper2Num;
  
  ss1 >> oper1Num;
  ss2 >> oper2Num;
  
  if (ss1.fail() || ss2.fail()) {
    cerr << "operands failed to cast" << endl;
    exit(1);
  }
  
  if (strcmp(oper,"*") == 0) return oper1Num * oper2Num;
  if (strcmp(oper,"+") == 0) return oper1Num + oper2Num;
  if (strcmp(oper,"-") == 0) return oper1Num - oper2Num;
  if (strcmp(oper,"/") == 0) return oper1Num / oper2Num;
  
  ss1.str("");
  ss2.str("");  
  
}

int evaluatePrefix(int argc, char** argv) {
  
  stack<char*> operators;
  stack<char*> operands;
  int result;
  char* resultStr;
  
  for (int i = (argc - 1); i >= 0; i--) {
    if (isOperator(argv[i]) == false) {
      operands.push(argv[i]);
    } else {
      char* oper1 = operands.top();
      operands.pop();
      
      char* oper2 = operands.top(); 
      operands.pop();
      
      result = evaluate(argv[i],oper1,oper2);

      // convert result (int) to (char*)
      stringstream xs;
      xs << result;
      string temp_str = xs.str();
      xs.str("");
      char* char_type = (char*) temp_str.c_str();
      
      operands.push(char_type);
    }
  }

  return result;
  
}

int main(int argc, char* argv[]) {
  cout << evaluatePrefix(argc,argv) << endl;
}
