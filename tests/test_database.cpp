#include <gtest/gtest.h>
#include "database.h"

using namespace mangodb;

TEST(DatabaseTest, DatabaseDoesNotExist)
{
    auto mangodb = Database::open("/hello");

    EXPECT_EQ(mangodb, nullptr);
}

TEST(DatabaseTest, CreateDatabase)
{
    DatabaseConfiguration db_cfg(testing::TempDir() + "test");

    EXPECT_EQ(Database::create(db_cfg.getDBFullPath()), 0);
}