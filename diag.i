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

%extend diag_consumer
{
    void set_device(PyObject* d)
    {
        printf("set device called\n");
        void* ptr = PyCapsule_GetPointer(d, nullptr);
        printf("%x\n", ptr);
        $self->m_d = reinterpret_cast<diag*>(ptr);
    }
};
