F = -g

all:
	cmake . -B build && cmake --build build && ./build/test_all
