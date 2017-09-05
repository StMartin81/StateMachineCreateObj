#include "states.h"

#include <iostream>

using namespace std;

BaseState::~BaseState()
{
  cout << "BaseState::~BaseState" << endl;
}

BaseState::BaseState(StateMachineData &stateMachineData)
  : mStateMachineData(stateMachineData)
{
  cout << "BaseState::BaseState" << endl;
}

NextStateWithStatus BaseState::OnEnter()
{
  cout << "BaseState::OnEnter not implemented" << endl;
  return { States::CURRENT_STATE, true };
}

bool BaseState::OnExit()
{
  cout << "BaseState::OnExit not implemented" << endl;
  return true;
}

NextStateWithStatus BaseState::OnLeaveInitialState()
{
  cout << "BaseState::OnLeaveInitialState not implemented" << endl;
  return { States::CURRENT_STATE, false };
}

NextStateWithStatus BaseState::OnIncrement()
{
  cout << "BaseState::OnIncrement not implemented" << endl;
  return { States::CURRENT_STATE, false };
}

NextStateWithStatus BaseState::OnDecrement()
{
  cout << "BaseState::OnDecrement not implemented" << endl;
  return { States::CURRENT_STATE, false };
}

NextStateWithStatus BaseState::OnCommon()
{
  cout << "BaseState::OnCommon not implemented" << endl;
  return { States::CURRENT_STATE, false };
}



InitialState::InitialState(StateMachineData &stateMachineData)
  : BaseState(stateMachineData)
{
  cout << "InitialState::InitialState" << endl;
}

InitialState::~InitialState()
{
  cout << "InitialState::~InitialState" << endl;
}

bool InitialState::OnExit()
{
  cout << "InitialState::OnExit" << endl;
  return true;
}

NextStateWithStatus InitialState::OnLeaveInitialState()
{
  cout << "InitialState::LeaveInitialState" << endl;
  return { States::INCREMENT_STATE, true };
}



IncrementState::IncrementState(StateMachineData &stateMachineData)
  : BaseState(stateMachineData)
{
  cout << "IncrementState::IncrementState" << endl;
}

IncrementState::~IncrementState()
{
  cout << "IncrementState::~IncrementState" << endl;
}

NextStateWithStatus IncrementState::OnEnter()
{
  cout << "IncrementState::OnEnter" << endl;
  return OnIncrement();
}

bool IncrementState::OnExit()
{
  cout << "IncrementState::OnExit" << endl;
  return true;
}

NextStateWithStatus IncrementState::OnIncrement()
{
  cout << "IncrementState::Increment: " << ++mStateMachineData.number << endl;
  return { States::CURRENT_STATE, true };
}

NextStateWithStatus IncrementState::OnDecrement()
{
  cout << "IncrementState::Decrement" << endl;
  return { States::DECREMENT_STATE, true };
}

NextStateWithStatus IncrementState::OnCommon()
{
  cout << "IncrementState::OnCommon" << endl;
  return { States::COMMON_STATE, true };
}



DecrementState::DecrementState(StateMachineData &stateMachineData)
  : BaseState(stateMachineData)
{
  cout << "DecrementState::DecrementState" << endl;
}

DecrementState::~DecrementState()
{
  cout << "DecrementState::~DecrementState" << endl;
}

NextStateWithStatus DecrementState::OnEnter()
{
  cout << "DecrementState::OnEnter" << endl;
  return OnDecrement();
}

bool DecrementState::OnExit()
{
  cout << "DecrementState::OnExit" << endl;
  return true;
}

NextStateWithStatus DecrementState::OnIncrement()
{
  cout << "DecrementState::Increment" << endl;
  return { States::INCREMENT_STATE, true };
}

NextStateWithStatus DecrementState::OnDecrement()
{
  cout << "DecrementState::Decrement: " << --mStateMachineData.number << endl;
  return { States::CURRENT_STATE, true };
}

NextStateWithStatus DecrementState::OnCommon()
{
  cout << "DecrementState::OnCommon" << endl;
  return { States::COMMON_STATE, true };
}


CommonState::CommonState(StateMachineData &stateMachineData)
  : BaseState(stateMachineData)
{
  cout << "CommonState::CommonState" << endl;
}

CommonState::~CommonState()
{
  cout << "CommonState::~CommonState" << endl;
}

NextStateWithStatus CommonState::OnEnter()
{
  cout << "CommonState::OnEnter" << endl;
  return { States::PREVIOUS_STATE, true };
}

bool CommonState::OnExit()
{
  cout << "CommonState::OnExit" << endl;
  return true;
}
