#ifndef STARTING_HPP
#define STARTING_HPP
#include "State.hpp"

class Starting : public State{
  public:
    Starting(); // constructor
    ~Starting(); // destructor

    void Enter() override;
    void Update() override;
    void Exit() override;
};

#endif 