#include "../../include/window_parser.hpp"
#include <iostream>
#include <cassert>

void TestEmptyDocument() {
    WindowParser parser;
    std::string empty_doc = "";
    auto result = parser.ExtractSlidingWindows(empty_doc, 5);
    
    // Validation: Empty document must return zero windows
    assert(result.empty());
    std::cout << "[PASS] TestEmptyDocument: Handled zero-length string correctly.\n";
}

void TestInvalidWindowBounds() {
    WindowParser parser;
    std::string doc = "DeterministicLogic";
    
    // Validation: Window size 0 or > 255 must fail immediately
    auto result_zero = parser.ExtractSlidingWindows(doc, 0);
    auto result_huge = parser.ExtractSlidingWindows(doc, 256);
    
    assert(result_zero.empty());
    assert(result_huge.empty());
    std::cout << "[PASS] TestInvalidWindowBounds: Out-of-bounds sizes blocked perfectly.\n";
}

void TestExactSlidingSlices() {
    WindowParser parser;
    std::string doc = "ABCDE"; // Length 5
    size_t window_size = 3;    // Bounded window
    
    // Expected windows: "ABC", "BCD", "CDE" -> Total = 5 - 3 + 1 = 3 windows
    auto result = parser.ExtractSlidingWindows(doc, window_size);
    
    assert(result.size() == 3);
    assert(result[0] == "ABC");
    assert(result[1] == "BCD");
    assert(result[2] == "CDE");
    std::cout << "[PASS] TestExactSlidingSlices: Contiguous window generation verified.\n";
}

int main() {
    std::cout << "Executing SLAM Core Validation Suite...\n";
    std::cout << "------------------------------------------\n";
    
    TestEmptyDocument();
    TestInvalidWindowBounds();
    TestExactSlidingSlices();
    
    std::cout << "------------------------------------------\n";
    std::cout << "All core system validation tests passed successfully!\n";
    return 0;
}
