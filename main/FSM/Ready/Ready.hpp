#ifndef READY_HPP
#define READY_HPP
#include "State.hpp"

class Ready : public State{
  public:
    Ready(); // constructor
    ~Ready(); // destructor

    void Enter() override;
    void Update() override;
    void Exit() override;
};

#endif 