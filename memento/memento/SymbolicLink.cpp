#include "SymbolicLink.hpp"

SymbolicLink::SymbolicLink(PUNICODE_STRING link_name, PUNICODE_STRING device_name, bool& result) :
    _link_name(link_name) // TODO: This is a bug
{
    /*CHECK_NTSTATUS(*/IoCreateSymbolicLink(link_name, device_name)/*)*/;

    result = true;
}

SymbolicLink::~SymbolicLink()
{
    if (_link_name != nullptr) 
    {
        IoDeleteSymbolicLink(_link_name);
        _link_name = nullptr;
    }
}