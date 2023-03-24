#ifndef DB_CONFIGURATION
#define DB_CONFIGURATION

#include <string>
#include <filesystem>
#include <stdexcept>

#include <header.h>
#include <utility.h>
namespace mangodb
{
    namespace fs = std::filesystem;
    class DatabaseConfiguration
    {
    private:
        fs::path db_path;
        std::string db_name;
        PageSize page_size = 512; // Default size of the Page is 512
    public:
        DatabaseConfiguration(fs::path _db_path, PageSize _page_size = 512) : db_path(_db_path)
        {

            if (_page_size < 512 && !is_power_of_two(_page_size))
            {
                throw std::invalid_argument("Invalid page size, it should be greater than 512 and power of 2");
            }
            page_size = _page_size;

            if (!_db_path.has_filename())
            {
                throw std::invalid_argument("Invalid path, path should contain the name of the file");
            }

            db_name = _db_path.filename().string();
        }

        const fs::path &getDBFullPath()
        {
            return db_path.replace_extension("mangdb");
        }
        const std::string &getDBName() const
        {
            return db_name;
        }
        const PageSize getPageSize() const
        {
            return page_size;
        }
    };
}
#endif // DB_CONFIGURATION