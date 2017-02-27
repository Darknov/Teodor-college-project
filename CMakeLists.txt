cmake_minimum_required(VERSION 3.4)
project(Teodor)

#specify set of project's source files
set(SOURCE_FILES
        include/game.h
        include/introstate.h
        include/menustate.h
        include/playstate.h
        include/state.h
		include/teststate.h
		include/enemy.h
		include/entity.h
		include/map.h
		include/player.h
		include/world.h
		include/bullet.h
		include/console.h
		include/intro.h
		include/scoreboard.h

        src/game.cpp
        src/introstate.cpp
        src/menustate.cpp
        src/playstate.cpp
        src/teststate.cpp
		src/enemy.cpp
		src/entity.cpp
		src/map.cpp
		src/player.cpp
		src/world.cpp
		src/bullet.cpp
		src/console.cpp
		src/intro.cpp
		src/scoreboard.cpp
		
        src/main.cpp
        )

#add following files to executable file 'Teodor'
#add_executable(Teodor ${SOURCE_FILES})
add_library(Teodor ${SOURCE_FILES})
#add header files from 'include' directory of main project
target_include_directories(Teodor PUBLIC include)



#SEKCJA TESTÓW
find_package (Boost 1.60.0 COMPONENTS "unit_test_framework" REQUIRED)

include_directories(
 	${CMAKE_CURRENT_SOURCE_DIR}/include
 	${Boost_INCLUDE_DIRS}
)

set(SOURCE_TEST_STATE_FILES
 	test/master.cpp
 	test/TestState.cpp)

add_executable (TestState ${SOURCE_TEST_STATE_FILES})

target_link_libraries (TestState
 	Teodor
 	${Boost_UNIT_TEST_FRAMEWORK_LIBRARY}
 	)

set(SOURCE_TEST_WORLD_FILES
 	test/master.cpp
 	test/TestWorld.cpp)

add_executable (TestWorld ${SOURCE_TEST_WORLD_FILES})

target_link_libraries (TestWorld
 	Teodor
 	${Boost_UNIT_TEST_FRAMEWORK_LIBRARY}
 	)	
	
set(SOURCE_TEST_ENTITY_FILES
 	test/master.cpp
 	test/TestEntity.cpp)

add_executable (TestEntity ${SOURCE_TEST_ENTITY_FILES})

target_link_libraries (TestEntity
 	Teodor
 	${Boost_UNIT_TEST_FRAMEWORK_LIBRARY}
 	)	
	
enable_testing()
add_test(TestTeodor1 TestState
 --report_level=detailed
 --log_level=all
 --color_output=yes
 )
 add_test(TestTeodor2 TestWorld
 --report_level=detailed
 --log_level=all
 --color_output=yes
 )
 add_test(TestTeodor3 TestEntity
 --report_level=detailed
 --log_level=all
 --color_output=yes
 )

add_custom_target(check ${CMAKE_COMMAND} -E env CTEST_OUTPUT_ON_FAILURE=1 BOOST_TEST_LOG_LEVEL=all
        ${CMAKE_CTEST_COMMAND} -C $<CONFIG> --verbose
        WORKING_DIRECTORY ${CMAKE_BINARY_DIR})