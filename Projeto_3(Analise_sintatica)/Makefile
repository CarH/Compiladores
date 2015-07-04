all: compile run

compile:
	@bison -d parser.y
	@flex myscanner.l
	@g++ parser.tab.c lex.yy.c -std=c++11 -lfl -o parser 

run:
	#######################################################################################
	# RUNNING TEST FOR DEBUGGING - IF YOU WANT TO RUN IT PROPERLY EXECUTE : bash script.sh 
	#
	# TEST: attr_real_to_integer: 
	@./parser < tests/attr_real_to_integer.in
	#
	############################
	# TEST: global_variables
	@./parser < tests/global_variables.in
	#
	############################
	# TEST: proc_not_declared
	@./parser < tests/proc_not_declared.in
	#
	############################
	# TEST: proc_parameter
	@./parser < tests/proc_parameter.in
	#
	############################
	# TEST: proc_redeclared
	@./parser < tests/proc_redeclared.in
	#
	############################
	# TEST: read_write
	@./parser < tests/read_write.in
	#
	############################
	# TEST: var_not_declared
	@./parser < tests/var_not_declared.in
	#
	############################
	# TEST: var_redeclared
	@./parser < tests/var_redeclared.in
	#
	############################
	# TEST: wrong_scope
	@./parser < tests/wrong_scope.in