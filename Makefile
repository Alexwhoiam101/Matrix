all:
	g++ -o prm main.cpp fun_for_mat.cpp -std=c++17

clean:
	rm prm
