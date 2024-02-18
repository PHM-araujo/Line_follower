#ifndef CALIBRATING_HPP
#define CALIBRATING_HPP
#include "State.hpp"

class Calibrating : public State{
  public:
    Calibrating(); // constructor
    ~Calibrating(); // destructor

    void Enter() override;
    void Update() override;
    void Exit() override;
};

#endif 