cmake_minimum_required(VERSION 3.26)
project(MALL)

set(CMAKE_CXX_STANDARD 20)

add_executable(
        main.cpp
        ARCHITECTURE/Item/Item.cpp
        ARCHITECTURE/Date/Date.cpp
        ARCHITECTURE/Shop/Shop.cpp
        main.cpp
        ARCHITECTURE/ShoppingCart/ShoppingCart.cpp
        ARCHITECTURE/Brand/Brand.cpp
        ARCHITECTURE/Mall/Mall.cpp
)

