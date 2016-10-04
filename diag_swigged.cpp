#include "diag_wrap.cxx"
#include "diag.hpp"

#include <Python.h>

PyObject* makeDiagPyObject(std::shared_ptr<diag> d)
{
    SWIG_init();
    printf("before get type info\n");
    swig_type_info *ty =
        SWIG_MangledTypeQuery("_diagswig");
    if (ty == nullptr)
    {
        printf("could not get typeinfo\n");
    }
    PyObject *data_obj =
        SWIG_NewPointerObj(d.get(), ty, 0);
    return data_obj;
}

