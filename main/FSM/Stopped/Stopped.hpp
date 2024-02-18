#ifndef STOPPED_HPP
#define STOPPED_HPP
#include "State.hpp"

class Stopped : public State{
  public:
    Stopped(); // constructor
    ~Stopped(); // destructor

    void Enter() override;
    void Update() override;
    void Exit() override;
};

#endif 