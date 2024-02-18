set(FSM_SRC
	<FSM/Ready/Ready.cpp>
	<FSM/Starting/Starting.cpp>
	<FSM/Updating/Updating.cpp>
	<FSM/Navigating/Navigating.cpp>
	<FSM/Stopping/Stopping.cpp>
	<FSM/Stopped/Stopped.cpp>
)



idf_component_register(
	SRCS 
		"main.cpp"
		"LineFollower/LineFollower.cpp"
		${FSM_SRC}
		
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
)
