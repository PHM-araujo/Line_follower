#include "State.hpp"
#include "Motor.hpp"

class LineFollower{
    public:
        LineFollower();
        ~LineFollower();
        void TransitionTo(State* state);
        
        // Routines
        static void UpdateStateRoutine(void *pvParameters);

        // Behaviors
        void InitSubsystems();

        // Test functions
        void TestMotors();

    private:

        static State* current_state;

        // Components
        Motor motor_left;
        Motor motor_right;
};
