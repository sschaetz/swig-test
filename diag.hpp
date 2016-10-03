#pragma once

#include <string>

class diag
{
public:
    diag(){}
    diag(const char* id, int number);
    ~diag();
private:
    std::string m_id;
    int m_number;
};
