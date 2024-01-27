#pragma once

#include <iostream>

#define print(x) std::cout << x << std::endl

template <typename Iter, typename Func>
void iter(Iter *addr, size_t len, Func func) {
	for (size_t i = 0; i < len; i++) {
		func(&addr[i]);
	}
}