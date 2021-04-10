#pragma once
#include "Win.h"

class EProcess final
{
public:
    EProcess(UINT32 pid, bool& result);
    ~EProcess();

public:
    PEPROCESS get() const;

private:
    bool _initialized;
    PRKPROCESS _eprocess;
};