#ifndef _HEADER_H_
#define _HEADER_H_


#include <string>
namespace mangodb
{

    using PageSize = uint32_t;
    using PageID = uint64_t;

    struct FileHeader
    {
        char magic_string[16] = "mangodb";
        PageSize page_size;
        uint64_t file_change_counter;
        const uint8_t max_payload_fraction = 64;
        const uint8_t min_payload_fraction = 32;
        uint64_t database_size;
    };


    enum class PageType : uint8_t
    {
        LEAF,
        ITERNAL,
    };

    struct PageHeader
    {
        PageType page_type;
        PageID page_id;
    };
}

#endif // _HEADER_H_