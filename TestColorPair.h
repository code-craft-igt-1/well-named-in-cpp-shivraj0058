#pragma once

#include <sstream>
#include <stdexcept>
#include <cassert>
#include "ColorPair.h"

#define assert_msg(expr, msg) \
    if (!(expr)) { \
        std::cerr << "Assertion failed: " << (msg) << std::endl; \
        std::cerr << "Expected: " << #expr << std::endl; \
        std::cerr << "File: " << __FILE__ << ", Line: " << __LINE__ << std::endl; \
        assert(expr); \
    }

void testNumberToPair(int pairNumber, TelCoColorCoder::MajorColor expectedMajor, TelCoColorCoder::MinorColor expectedMinor);
void testPairToNumber(TelCoColorCoder::MajorColor major, TelCoColorCoder::MinorColor minor, int expectedPairNumber);
void TestPrintReferenceManual();