add_executable(
	chapter-1
	"chapter_1/chapter_1.cpp"
)

add_executable(
	chapter-2
	"chapter_2/chapter_2.cpp"
)

add_subdirectory("chapter_3")
add_executable(
	chapter-3
	"chapter_3/chapter_3.cpp"
)
target_link_libraries(
	chapter-3
	vector
	vector_module
)

add_subdirectory("chapter_4")
add_executable(
	chapter-4
	"chapter_4/chapter_4.cpp"
)
target_link_libraries(
	chapter-4
	complex
	vector
)

add_executable(
	cmake-default 
	"cmake_default/cmake.cpp" 
	"cmake_default/cmake.hpp"
)
