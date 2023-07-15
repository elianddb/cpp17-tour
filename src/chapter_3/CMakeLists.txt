add_library(
	vector STATIC
	"vector/vector.cpp"
	"vector/vector.hpp"
)
target_include_directories(
	vector PUBLIC
	"vector"
)
