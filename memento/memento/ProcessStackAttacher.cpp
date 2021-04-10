#include "ProcessStackAttacher.hpp"

ProcessStackAttacher::ProcessStackAttacher(const EProcess& process)
{
    KeStackAttachProcess(process.get(), &_apc_state);
}

ProcessStackAttacher::~ProcessStackAttacher()
{
    KeUnstackDetachProcess(&_apc_state);
}