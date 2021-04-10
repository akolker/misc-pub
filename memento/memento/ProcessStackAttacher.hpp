#pragma once
#include "EProcess.hpp"

class ProcessStackAttacher final
{
public:
    explicit ProcessStackAttacher(const EProcess& process);
    ~ProcessStackAttacher();

private:
    KAPC_STATE _apc_state;
};