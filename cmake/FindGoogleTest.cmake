if(HEY_BUILD_TESTS)
    function(findgt)
        include(FetchContent)

        FetchContent_Declare(
            googletest
            URL https://github.com/google/googletest/archive/main.zip
            )

        FetchContent_MakeAvailable(googletest)
    endfunction(findgt)
    findgt()

endif(HEY_BUILD_TESTS)
