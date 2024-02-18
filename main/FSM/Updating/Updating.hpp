#ifndef UPDATING_HPP
#define UPDATING_HPP
#include "State.hpp"

class Updating : public State{
  public:
    Updating(); // constructor
    ~Updating(); // destructor

    void Enter() override;
    void Update() override;
    void Exit() override;
};

#endif 