#ifndef EXCEPTION_H
#define EXCEPTION_H

#include <string>

using namespace std;

void logErrorAndExit(const std::string& msg, const char* error = nullptr);

#endif //EXCEPTION_H
