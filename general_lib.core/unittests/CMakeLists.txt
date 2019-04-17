
set (UNITTEST_TARGET runUnitTests)

# Include the gtest library. gtest_SOURCE_DIR is available due to
# 'project(gtest)' above.
#include_directories (${gtest_SOURCE_DIR}/include ${gtest_SOURCE_DIR})
  
 set (UNITTESTS_SOURCE_DIR 
	${CMAKE_CURRENT_SOURCE_DIR}/src
 )
 
# Collect application sources
set (UNITTESTS_SOURCE
	${UNITTESTS_SOURCE_DIR}/main.cpp
	${UNITTESTS_SOURCE_DIR}/common_unittests.cpp
	${UNITTESTS_SOURCE_DIR}/test_configuration.cpp
)


set (UNITTESTS_INCLUDE_DIR 
	${CMAKE_CURRENT_SOURCE_DIR}/include
 )
 
 
set (UNITTESTS_HEADERS
	${UNITTESTS_INCLUDE_DIR}/base_fixture.h
	${UNITTESTS_INCLUDE_DIR}/test_configuration.h
	${UNITTESTS_INCLUDE_DIR}/common_fixture.h
	${JSON_INCLUDE_DIRS}/json.hpp
)

add_executable(${UNITTEST_TARGET} 
	${UNITTESTS_SOURCE}
	${UNITTESTS_HEADERS}
)

target_include_directories (${UNITTEST_TARGET} 
	PRIVATE
		${gtest_SOURCE_DIR}/include
		${JSON_INCLUDE_DIRS}
	PUBLIC
		${UNITTESTS_INCLUDE_DIR}
)

# Standard linking to gtest stuff.
target_link_libraries (${UNITTEST_TARGET}  
		${LIBRARY_NAME}
		gtest 
		gtest_main
)

add_dependencies (${UNITTEST_TARGET}  
		${LIBRARY_NAME}
)

set_target_properties(${UNITTEST_TARGET} PROPERTIES FOLDER ${CMAKE_PROJECT_NAME}/${LIBRARY_NAME}/unittests)



# copy one file to output direcory using cmake copy
add_custom_command (TARGET ${UNITTEST_TARGET} POST_BUILD
	COMMAND ${CMAKE_COMMAND} -E copy_if_different
	"${CMAKE_CURRENT_SOURCE_DIR}/data/example.json"
	$<TARGET_FILE_DIR:${UNITTEST_TARGET}>
)
