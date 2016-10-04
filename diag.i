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
    void print();
private:
    std::string m_id;
    int m_number;
};

