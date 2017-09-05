#ifndef ISTATES_H
#define ISTATES_H

/*!
 *\brief Events which are handled by the state machine
 */
class IStateMachineEvents
{
public:
  virtual ~IStateMachineEvents() {}
  /*!
   * \brief Causes value to increment
   * \return True if function was successful
   */
  virtual bool OnIncrement() = 0;
  /*!
   * \brief Causes value to decrement
   * \return True if function was successful
   */
  virtual bool OnDecrement() = 0;
  /*!
   * \brief Example for a common state which can be reached from either IncrementState or DecrementState
   * \details After this is event is handled the state machine will return to the previous state
   * \return True if function was successful
   */
  virtual bool OnCommon() = 0;
};

#endif // ISTATES_H
