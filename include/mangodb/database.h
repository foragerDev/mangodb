#ifndef _DATABASE_H_
#define _DATABASE_H_


#include "db_configurations.h"
#include <mangodb.h>
#include <memory>
#include <filesystem>


namespace mangodb
{



    namespace fs = std::filesystem;
    class Database
    {
    public:
        // Later it should return errors will be implemented later
        static std::shared_ptr<MangoDB> open(const fs::path& paths);
        static int create(const DatabaseConfiguration &configurationss);
        static int destroy(const DatabaseConfiguration &configurations);
        
    private:
        bool validate_database_header();
    };
}

#endif // _DATABASE_H