#ifndef NAVIGATING_HPP
#define NAVIGATING_HPP
#include "State.hpp"

class Navigating : public State{
  public:
    Navigating(); // constructor
    ~Navigating(); // destructor

    void Enter() override;
    void Update() override;
    void Exit() override;
};

#endif 