#ifndef _MANGODB_H_
#define _MANGODB_H_

#include "btree.h"
#include "header.h"
#include <string_view>
#include <span>

namespace mangodb
{

    class MangoDB
    {
    private:
    
    FileHeader database_head;
    std::string_view database_name;
    };
}

#endif // _MANGODB_H_