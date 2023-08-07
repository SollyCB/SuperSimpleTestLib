LIB = ../test.cpp test_entrypoint.cpp
SRC = SomeClass.cpp

pass:
	g++ $(SRC) SomeClassTest_pass.cpp $(LIB) -o TestPass && ./TestPass

fail:
	g++ $(SRC) SomeClassTest_fail.cpp $(LIB) -o TestFail && ./TestFail
