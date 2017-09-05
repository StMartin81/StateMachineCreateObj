#ifndef STATEMACHINE_H
#define STATEMACHINE_H

#include <vector>
#include "istatemachineevents.h"
#include "states.h"

/*!
 * \brief Creates the state objects and is responsible for the state changes
 */
class StateMachine final: public IStateMachineEvents
{
public:
  StateMachine();
  /*!
   * \see  IStateMachineEvents::OnIncrement
   */
  virtual bool OnIncrement() override final;
  /*!
   * \see  IStateMachineEvents::OnDecrement
   */
  virtual bool OnDecrement() override final;
  /*!
   * \see  IStateMachineEvents::OnCommon
   */
  virtual bool OnCommon() override final;

private:
  /*!
   * \brief ChangeState
   * \param[in] newState Struct with next state state machine should change to and status if state function was successful
   * \return True if state change was successful
   */
  virtual bool ChangeState(NextStateWithStatus newState) final;
  /*!
   * \brief Save a pointer to the current state so that it is possible to return to this state later
   */
  virtual void StoreCurrentState() final;
  /*!
   * \brief Return to the last state which was stored previously
   */
  virtual void RestoreLastState() final;

  StateMachineData mStateMachineData; //!< Common data which gets used by the states
  InitialState mInitialState; //!< Initial state object
  IncrementState mIncrementState; //!< Increment state object
  DecrementState mDecrementState; //!< Decrement state object
  CommonState mCommonState; //!< Common state object
  BaseState *mpCurrentState; //!< Pointer to the current state object
  std::vector< BaseState * > mStateHistory; //!< Used to store the state history
};

#endif // STATEMACHINE_H
