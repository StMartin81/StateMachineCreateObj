#include <iostream>
#include "statemachine.h"

using std::cerr;

StateMachine::StateMachine()
  : mStateMachineData()
  , mInitialState(mStateMachineData)
  , mIncrementState(mStateMachineData)
  , mDecrementState(mStateMachineData)
  , mCommonState(mStateMachineData)
  , mpCurrentState(&mInitialState)
{
  ChangeState(mpCurrentState->OnLeaveInitialState());
}

bool StateMachine::OnIncrement()
{
  return ChangeState(mpCurrentState->OnIncrement());
}

bool StateMachine::OnDecrement()
{
  return ChangeState(mpCurrentState->OnDecrement());
}

bool StateMachine::OnCommon()
{
  return ChangeState(mpCurrentState->OnCommon());
}

bool StateMachine::ChangeState(NextStateWithStatus newState)
{
  bool result{ true };
  // Only change state if it was explicitly requested
  if (States::CURRENT_STATE != newState.nextState)
  {
    result = result && mpCurrentState->OnExit();
    switch (newState.nextState)
    {
    case States::INCREMENT_STATE:
    {
      mpCurrentState = &mIncrementState;
      break;
    }
    case States::DECREMENT_STATE:
    {
      mpCurrentState = &mDecrementState;
      break;
    }
    case States::COMMON_STATE:
    {
      StoreCurrentState();
      mpCurrentState = &mCommonState;
      break;
    }
    case States::PREVIOUS_STATE:
    {
      RestoreLastState();
      break;
    }
    default:
    {
      cerr << "Illegal state event detected";
      break;
    }
    }
    result = result && ChangeState(mpCurrentState->OnEnter());
  }

  return result;
}

void StateMachine::RestoreLastState()
{
  mpCurrentState = mStateHistory.back();
  mStateHistory.pop_back();
}

void StateMachine::StoreCurrentState()
{
  mStateHistory.push_back(mpCurrentState);
}
