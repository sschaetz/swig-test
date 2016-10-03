# Swig diag

PYTHONINCLUDES := $(shell python-config --cflags)
PYTHONLIBS := $(shell python-config --ldflags)

swig: diag.i diag.cpp
	swig -python -c++ diag.i
	g++ -std=c++14 -c diag.cpp -fPIC -o diag.o
	g++ -std=c++14 -c diag_wrap.cxx $(PYTHONINCLUDES) -fPIC -o diag_wrap.o
	g++ -std=c++14 diag.o diag_wrap.o -shared -o _diagswig.so $(PYTHONLIBS)

diag: swig diag.cpp diag.hpp main.cpp
	g++ -std=c++14 diag.cpp main.cpp $(PYTHONINCLUDES) $(PYTHONLIBS) -o diag

test:
	python test_forward.py
	python test_backward.py
