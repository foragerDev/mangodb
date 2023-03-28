#ifndef _IO_MANAGER_H_
#define _IO_MANAGER_H_

#include <string>
#include <filesystem>
#include <memory>

namespace fs = std::filesystem;

// Reader class  to support multiple platform

namespace mangodb
{

    class IOManager
    {
    public:
        virtual int read(char *out_buffer, size_t offset, size_t size) = 0;
        virtual int write(char *in_buffer, size_t offset, size_t size) = 0;
        virtual ~IOManager(){};
    };

    // Unix based implemenation
    class PosixIOManager : public IOManager
    {
    private:
        fs::path file_path;
        int file_descriptor;

    public:
        PosixIOManager(fs::path _file_path, bool create = false);

        int read(char *out_buffer, size_t offset, size_t size) override;
        int write(char *in_buffer, size_t offset, size_t size) override;

        ~PosixIOManager();
    };

    inline std::shared_ptr<IOManager> get_io_manager(const fs::path &file_path, bool create = false)
    {
#if defined(__linux__)
        return std::make_shared<PosixIOManager>(file_path, create);
#endif
        return nullptr;
    }

}

#endif