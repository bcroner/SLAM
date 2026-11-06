#ifndef WINDOW_PARSER_HPP
#define WINDOW_PARSER_HPP

#include <vector>
#include <string>

class WindowParser {
public:
    WindowParser() = default;

    // Slices a raw document string into a vector of contiguous sub-strings of size 'w'
    std::vector<std::string> ExtractSlidingWindows(const std::string& document_text, size_t window_size) {
        std::vector<std::string> windows;
        if (document_text.empty() || window_size == 0 || window_size > 255) return windows;
        if (document_text.length() < window_size) return windows;

        // Linear sliding window execution loop: O(n)
        size_t total_windows = document_text.length() - window_size + 1;
        windows.reserve(total_windows);

        for (size_t i = 0; i < total_windows; ++i) {
            windows.push_back(document_text.substr(i, window_size));
        }

        return windows;
    }
};

#endif // WINDOW_PARSER_HPP
