set(FSM_SRC
	<FSM/Ready/Ready.cpp>
	<FSM/Starting/Starting.cpp>
	<FSM/Updating/Updating.cpp>
	<FSM/Navigating/Navigating.cpp>
	<FSM/Stopping/Stopping.cpp>
	<FSM/Stopped/Stopped.cpp>
)

set(NavigationSubsystem_SRC
	<NavigationSubsystem/Motor/Motor.cpp>
	<NavigationSubsystem/ReflectanceSensor/ReflectanceSensor.cpp>
)



idf_component_register(
	SRCS 
		"main.cpp"
		"LineFollower/LineFollower.cpp"
		${FSM_SRC}
		${NavigationSubsystem_SRC}
		
	INCLUDE_DIRS
    	"."
    	"FSM/State/"
		"LineFollower/"
		"FSM/Ready/"
		"FSM/Starting/"
		"FSM/Updating/"
		"FSM/Navigating/"
		"FSM/Stopping/"
		"FSM/Stopped/"
		"NavigationSubsystem/Motor/"
		"NavigationSubsystem/ReflectanceSensor/"
)
