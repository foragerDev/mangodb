#include <gtest/gtest.h>
#include "database.h"


using namespace mangodb;

TEST(DatabaseTest, DatabaseDoesNotExist) {
    auto mangodb = Database::open("/hello");

    EXPECT_EQ(mangodb, nullptr);
}