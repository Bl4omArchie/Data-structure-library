#include <iostream>
#include "includes/google_test.hpp"




int main( int argc, char **argv )
{
    // run google tests 
    ::testing::InitGoogleTest( &argc, argv );
    return RUN_ALL_TESTS();
}