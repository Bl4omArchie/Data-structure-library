#include <iostream>
#include "includes/google_test.hpp"


extern "C" {
    #include "includes/file_struct.h"
}



int main( int argc, char **argv )
{
    /* run google tests */
    ::testing::InitGoogleTest( &argc, argv );
    return RUN_ALL_TESTS();
}