LIB = ../test.cpp test_entrypoint.cpp
SRC = SomeClass.cpp

pass:
	clang++ $(SRC) SomeClassTest_pass.cpp $(LIB) -o TestPass && ./TestPass

fail:
	clang++ $(SRC) SomeClassTest_fail.cpp $(LIB) -o TestFail && ./TestFail
