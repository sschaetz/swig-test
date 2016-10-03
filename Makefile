# Swig diag

diag: diag.cpp diag.hpp main.cpp
	g++ -std=c++14 diag.cpp main.cpp -o diag
