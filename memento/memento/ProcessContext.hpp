#pragma once
#include "EProcess.hpp"
#include "ProcessStackAttacher.hpp"
#include "Win.h"

class ProcessContext final
{
public:
    ProcessContext(UINT32 pid, bool& result);
    ~ProcessContext() = default;

private:
    EProcess _process;
    ProcessStackAttacher _stack_attacher;
};