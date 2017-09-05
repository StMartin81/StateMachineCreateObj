#ifndef STATEMACHINEDATA_H
#define STATEMACHINEDATA_H

/*!
 * \brief Structure with data which gets commonly used by all states
 */
struct StateMachineData
{
public:
  StateMachineData() = default;
  virtual ~StateMachineData(){}

  int number{ 0 }; //!< Current value

private:
  StateMachineData &operator=(const StateMachineData &) = delete;
  StateMachineData &operator=(StateMachineData &&other) = delete;
  StateMachineData(const StateMachineData &) = delete;
  StateMachineData(StateMachineData &&other) = delete;
};

#endif // STATEMACHINEDATA_H
