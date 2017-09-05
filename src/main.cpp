#include <iostream>
#include "statemachine.h"

using namespace std;

int main()
{
  StateMachine stateMachine;
  cout << "State machine should have been constructed by now" << endl << endl;

  stateMachine.OnIncrement();
  stateMachine.OnCommon();
  stateMachine.OnDecrement();
  stateMachine.OnCommon();

  cout << endl << "Now the destructors should be called" << endl;
  return 0;
}
