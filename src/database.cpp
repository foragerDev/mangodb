#include "database.h"
#include "mangodb.h"
#include "header.h"
#include "io_mgr.h"

#include <filesystem>
#include <fstream>
#include <cstring>
#include <iostream>

namespace fs = std::filesystem;
namespace mangodb
{
    std::shared_ptr<MangoDB> Database::open(const fs::path &path)
    {
        auto io_manager = get_io_manager(path);

        char *header_buffer[sizeof(FileHeader)];

        if (io_manager->read(reinterpret_cast<char *>(header_buffer), 0, sizeof(FileHeader)) < 0)
        {
            throw std::runtime_error("Couldn't read the file.");
        };
        FileHeader *header = reinterpret_cast<FileHeader *>(header_buffer);
        return nullptr;
    }
    int Database::create(const DatabaseConfiguration &db_cfg)
    {
        auto io_manager = get_io_manager(db_cfg.getDBFullPath(), true);

        FileHeader file_header{};
        file_header.page_size = db_cfg.getPageSize();
        char *file_header_buffer = reinterpret_cast<char *>(&file_header);

        if (io_manager->write(file_header_buffer, 0, sizeof(file_header)) < 0)
        {
            throw std::runtime_error("Failed to write file header");
        };

        return 0;
    }
}