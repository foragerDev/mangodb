#include <gtest/gtest.h>
#include <stdio.h>
#include "database.h"

using namespace mangodb;

class DatabaseTest : public testing::Test
{
public:
    static inline std::string db_path = "test.mangodb";

protected:
    static void SetUpTestSuite()
    {
        DatabaseConfiguration db_configuration("test");
        Database::create(db_configuration);
    }
    static void TearDownTestSuite()
    {
        remove(db_path.data());
    }
};

TEST_F(DatabaseTest, CreateDatabase)
{
    EXPECT_EQ(fs::exists(DatabaseTest::db_path), true);
}

TEST_F(DatabaseTest, DatabaseDoesNotExist)
{
    EXPECT_THROW(Database::open("tests.mangodb"), std::runtime_error);
}
