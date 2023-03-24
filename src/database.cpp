#include "database.h"
#include "mangodb.h"

#include <filesystem>
#include <fstream>

namespace fs = std::filesystem;

namespace mangodb {
    std::shared_ptr<MangoDB> Database::open(const fs::path& path) {
        if(!fs::exists(path)) return nullptr;
    
        

    
    }
    int Database::create(const DatabaseConfiguration& db_cfg) {
        
    }
}