#ifndef DB_CONFIGURATION
#define DB_CONFIGURATION

#include <string>
#include <filesystem>
namespace mangodb
{
    class DatabaseConfiguration
    {
    private:
        std::string db_name;
        bool create_if_missing;
        bool is_mem_only;
        size_t page_size = 4096; // Default size of the Page is 4KB
    public:
        const std::string &getDBName() const
        {
            return db_name;
        }

        bool isMemOnly() const
        {
            return is_mem_only;
        }
    };
}
#endif // DB_CONFIGURATION