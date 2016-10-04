%module diagswig
%{
#include "diag.hpp"
%}

%ignore diag::diag();

class diag
{
public:
    diag(){}
    diag(const char* id, int number);
    ~diag();
    void p();
};


class diag_consumer
{
public:
    diag_consumer(diag* d);
    void p();
};
