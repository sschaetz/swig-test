#include "diag.hpp"
#include "diag_swigged.hpp"
#include <Python.h>

#include <memory>
#include <stdio.h>

int main(void)
{
    // Create shared instance of diag.
    auto d = std::make_shared<diag>("super-id", 42);

    // Try to call a ptyhon script.
    {
        Py_Initialize();

        // Import module.
        PyObject* pModuleName = PyUnicode_FromString("test_backward");
        PyObject* pModule = PyImport_Import(pModuleName);

        if (pModule == nullptr)
        {
            PyErr_Print();
            return -1;
        }

        // Call function in module.
        PyObject* pFunc = PyObject_GetAttrString(pModule, "test");
        if (pFunc == nullptr && PyCallable_Check(pFunc))
        {
            PyErr_Print();
            return -1;
        }

        PyObject* pValue = PyObject_CallObject(pFunc, nullptr);

        Py_Finalize();
    }


    // Try to call a ptyhon script.
    {
        Py_Initialize();

        // Import module.
        PyObject* pModuleName = PyUnicode_FromString("test_forward");
        PyObject* pModule = PyImport_Import(pModuleName);

        if (pModule == nullptr)
        {
            PyErr_Print();
            return -1;
        }

        // Call function in module.
        PyObject* pFunc = PyObject_GetAttrString(pModule, "test");
        if (pFunc == nullptr && PyCallable_Check(pFunc))
        {
            PyErr_Print();
            return -1;
        }

        // Wrap in python callable thing.
        auto obj = makeDiagPyObject(d);

        auto args = PyTuple_New(1);
        PyTuple_SetItem(args, 0, obj);

        PyObject* pValue = PyObject_CallObject(pFunc, args);

        Py_Finalize();
    }

    // Call python, pass wrapped thing.

    return 0;
}

