#include "database.h"
#include "mangodb.h"
#include "header.h"

#include <filesystem>
#include <fstream>
#include <cstring>

namespace fs = std::filesystem;

namespace mangodb
{
    std::shared_ptr<MangoDB> Database::open(const fs::path &path)
    {
        if (!fs::exists(path))
            return nullptr;
    }
    int Database::create(const DatabaseConfiguration &db_cfg)
    {
        std::ofstream database_file(db_cfg.getDBName(), database_file.binary);

        if (!database_file.is_open())
        {
            return -1;
        }
        FileHeader file_header;
        uint8_t file_header_buffer[sizeof(file_header)];
        file_header.page_size = db_cfg.getPageSize();
        std::memcpy(&file_header, &file_header, sizeof(file_header));

        database_file.write(reinterpret_cast<char *>(file_header_buffer), sizeof(file_header_buffer));

        return 0;
    }
}