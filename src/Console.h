#ifndef CONSOLE_5428_H
#define CONSOLE_5428_H

#include <iostream>
#include "Typedefs_5428.h"

namespace C {

INLINE void Out(char* str) {
	std::cout << "[ELON] " << str << std::endl;
}

INLINE void Err(char* str){
	std::cerr << "[ERROR] " << str << std::endl;
}

}

#endif
