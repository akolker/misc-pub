#include "ProcessContext.hpp"

ProcessContext::ProcessContext(UINT32 pid, bool& result) :
    _process(pid, result),
    _stack_attacher(_process)
{
}