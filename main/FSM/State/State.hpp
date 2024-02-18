#ifndef STATE_HPP
#define STATE_HPP

class LineFollower; // forward declaration

class State {
  protected:
    LineFollower* line_follower;
  public:
    virtual ~State(){}
    void SetLineFollower(LineFollower* line_follower){
      this->line_follower = line_follower;
    }
    virtual void Enter() = 0;
    virtual void Update() = 0;
    virtual void Exit() = 0;
};

#endif // STATE_HPP