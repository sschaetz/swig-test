#include "diag.hpp"

#include <stdio.h>

diag::diag(const char* id, int number)
    : m_id(id)
    , m_number(number)
{
    printf("ctor!\n");
}

diag::~diag()
{
    printf("dtor!\n");
}
