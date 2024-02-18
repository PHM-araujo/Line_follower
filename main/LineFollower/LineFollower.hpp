#include "State.hpp"

class LineFollower{
    public:
        LineFollower();
        LineFollower(State* initial_state);
        ~LineFollower();
        void TransitionTo(State* state);
        
        // Routines
        static void UpdateStateRoutine(void *pvParameters);

    private:

        static State* current_state;
};
