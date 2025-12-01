#ifndef CSV_H
#define CSV_H

#include <vector>
#include <string>

struct TableData {
    std::string caption;
    std::vector<std::string> headers;
    std::vector<std::vector<std::string>> body;
};

TableData parseCsvNoHeaders(const std::string& filename);

#endif
