#pragma once
#include "Win.h"

class SymbolicLink final
{
public:
    explicit SymbolicLink(PUNICODE_STRING link_name, PUNICODE_STRING device_name, bool& result);
    ~SymbolicLink();

private:
    PUNICODE_STRING _link_name;
};