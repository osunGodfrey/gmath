# CXX = Clang++
# CXXFLAGS = -std=c++17 -Wall -Wextra -Iinclude

# tests/vec3test0: tests/vec3test0.cpp include/gmath/vec3.hpp
# 	$(CXX) $(CXXFLAGS) $< -o $@
CXX = clang++
CXXFLAGS = -std=c++17 -Wall -Wextra -Iinclude

tests/vec3test0: tests/vec3test0.cpp include/gmath/vec3.hpp
	$(CXX) $(CXXFLAGS) $< -o $@

clean:
	rm -f tests/vec3test0

.PHONY: clean