add_library(
	complex STATIC
	"complex/complex.cpp"
	"complex/complex.hpp"
)
target_include_directories(
	complex PUBLIC
	"complex"
)
