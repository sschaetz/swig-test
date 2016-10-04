#include "diag.hpp"

#include <stdio.h>
#include <iostream>

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

void diag::p()
{
    std::cout << m_id << " " << m_number << std::endl;
}

diag_consumer::diag_consumer(diag* d)
    : m_d(d)
{
}

void diag_consumer::p()
{
    m_d->p();
}
