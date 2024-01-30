#include <gtest/gtest.h>

extern "C" {
#include "google_test.h"
}

/* **********    MYTEST    ********** */

TEST( MyTest, alwaysTrue )
{
    EXPECT_EQ( true, true );
}

/* ********** MAIN ROUTINE ********** */

int main( int argc, char **argv )
{
    /* run google tests */
    ::testing::InitGoogleTest( &argc, argv );
    return RUN_ALL_TESTS();
}