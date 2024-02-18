#ifndef STOPPING_HPP
#define STOPPING_HPP
#include "State.hpp"

class Stopping : public State{
  public:
    Stopping(); // constructor
    ~Stopping(); // destructor

    void Enter() override;
    void Update() override;
    void Exit() override;
};

#endif 