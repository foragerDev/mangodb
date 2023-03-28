#include "io_mgr.h"

#include <fcntl.h>
#include <unistd.h>
#include <iostream>

namespace mangodb
{
    PosixIOManager::PosixIOManager(fs::path _file_path, bool create) : file_path(_file_path)
    {
        auto flags = O_APPEND | O_RDWR;
        if (create)
        {
            flags |= O_CREAT;
        }
        file_descriptor = open(file_path.c_str(), flags);

        if (file_descriptor == -1)
        {
            throw std::runtime_error("Could not open file " + _file_path.string());
        }
    }

    int PosixIOManager::read(char *out_buffer, size_t offset, size_t size)
    {
        // Seek will not used for now.
        off_t file_offset = lseek(file_descriptor, offset, SEEK_SET);

        if (file_offset < 0)
        {
            return -1;
        }

        auto read_bytes = ::read(file_descriptor, static_cast<void *>(out_buffer), size);
        return read_bytes < 0 ? -1 : read_bytes;
    }
    int PosixIOManager::write(char *in_buffer, size_t offset, size_t size)
    {
        off_t file_offset = lseek(file_descriptor, offset, SEEK_END);

        if (file_offset < 0)
        {
            return -1;
        }

        auto written_bytes = ::write(file_descriptor, in_buffer, size);
        return written_bytes < 0 ? -1 : written_bytes;
    }

    PosixIOManager::~PosixIOManager()
    {
        close(file_descriptor);
    }

}