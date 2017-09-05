#ifndef STATES_H
#define STATES_H

#include "istatemachineevents.h"
#include "statemachinedata.h"

/*!
 * \brief This class describes all the possible states
 * \details The values from this class will be used by the state machine to switch the states
 */
enum class States
{
  INITIAL_STATE, //!< InitialState
  INCREMENT_STATE, //!< IncrementState
  DECREMENT_STATE, //!< DecrementState
  COMMON_STATE, //!< CommonState
  CURRENT_STATE, //!< Stay in current state
  PREVIOUS_STATE //!< Return to previous state
};

/*!
 * \brief Result class for the state functions which gets used by the state machine to determine the next state
 */
struct NextStateWithStatus
{
  States nextState{States::CURRENT_STATE}; //!< Next state to which teh state machine should change to
  bool status{ false }; //!< Signal if function was executed successfully
};

/*!
 * \brief The common state class which implements all events handled by the states
 */
class BaseState
{
public:
  virtual ~BaseState();
  /*!
   * \brief This function will be called when a new state is entered
   * \return Next state to which the state machine should change to and status if the function was successful
   */
  virtual NextStateWithStatus OnEnter();
  /*!
   * \brief This function will be called when exiting the old state
   * \return True if function was successful
   */
  virtual bool OnExit();
  /*!
   * \brief Signal that initial state should be exited
   * \return Next state to which the state machine should change to and status if the function was successful
   */
  virtual NextStateWithStatus OnLeaveInitialState();
  /*!
   * \brief Increment counter event
   * \return Next state to which the state machine should change to and status if the function was successful
   */
  virtual NextStateWithStatus OnIncrement();
  /*!
   * \brief Decrement counter event
   * \return Next state to which the state machine should change to and status if the function was successful
   */
  virtual NextStateWithStatus OnDecrement();
  /*!
   * \brief Switch to common state
   * \return Next state to which the state machine should change to and status if the function was successful
   */
  virtual NextStateWithStatus OnCommon();

protected:
  /*!
   * \brief BaseState constructor
   * \param[in] stateMachineData Reference for state machine data which is used by all states
   */
  BaseState(StateMachineData &stateMachineData);

  StateMachineData &mStateMachineData; //!< Data which is shared by all states
};

/*!
 * \brief Initial state the state machine will be set to on construction
 */
class InitialState final: public BaseState
{
public:
  /*!
   * \brief InitialState constructor
   * \param[in] stateMachineData Reference for state machine data which is used by all states
   */
  InitialState(StateMachineData &stateMachineData);
  virtual ~InitialState();
  virtual bool OnExit() override final;
  virtual NextStateWithStatus OnLeaveInitialState() override final;
};

/*!
 * \brief State machine will change to this state when OnIncrement event was received
 */
class IncrementState final: public BaseState
{
public:
  /*!
   * \brief IncrementState constructor
   * \param[in] stateMachineData Reference for state machine data which is used by all states
   */
  IncrementState(StateMachineData &stateMachineData);
  virtual ~IncrementState();
  /*!
   * see BaseState::OnEnter
   */
  virtual NextStateWithStatus OnEnter() override final;
  /*!
   * see BaseState::OnExit
   */
  virtual bool OnExit() override final;
  virtual NextStateWithStatus OnIncrement() override final;
  virtual NextStateWithStatus OnDecrement() override final;
  virtual NextStateWithStatus OnCommon() override final;
};

/*!
 * \brief State machine will change to this state when OnDecrement event was received
 */
class DecrementState final: public BaseState
{
public:
  /*!
   * \brief DecrementState constructor
   * \param[in] stateMachineData Reference for state machine data which is used by all states
   */
  DecrementState(StateMachineData &stateMachineData);
  virtual ~DecrementState();
  /*!
   * see BaseState::OnEnter
   */
  virtual NextStateWithStatus OnEnter() override final;
  /*!
   * see BaseState::OnExit
   */
  virtual bool OnExit() override final;
  virtual NextStateWithStatus OnIncrement() override final;
  virtual NextStateWithStatus OnDecrement() override final;
  virtual NextStateWithStatus OnCommon() override final;
};

/*!
 * \brief State machine will change to this state when OnCommon event was received
 */
class CommonState final: public BaseState
{
public:
  /*!
   * \brief CommonState constructor
   * \param[in] stateMachineData Reference for state machine data which is used by all states
   */
  CommonState(StateMachineData &stateMachineData);
  virtual ~CommonState();
  /*!
   * see BaseState::OnEnter
   */
  virtual NextStateWithStatus OnEnter() override final;
  /*!
   * see BaseState::OnExit
   */
  virtual bool OnExit() override final;
};

#endif // STATES_H
