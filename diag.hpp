#pragma once

#include <string>

class diag
{
public:
    diag(const char* id, int number);
    ~diag();
    void p();
private:
    std::string m_id;
    int m_number;
};

class diag_consumer
{
public:
    diag_consumer(diag* d);
    void p();
    diag* m_d;
};
