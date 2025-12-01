#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>

using namespace std;

struct TableData {
    string caption;
    vector<string> headers;
    vector<vector<string>> body;
};

vector<string> splitCsvLine(const string& line) {
    vector<string> fields;
    stringstream ss(line);
    string field;

    while (getline(ss, field, ',')) {
        fields.push_back(field);
    }

    return fields;
}

TableData parseCsvNoHeaders(const string& filename) {
    TableData table;
    ifstream file(filename);
    string line;

    if (file.is_open()) {
        while (getline(file, line)) {
            table.body.push_back(splitCsvLine(line));
        }
        file.close();
    } else {
        cerr << "Unable to open file: " << filename << endl;
    }

    return table;
}

TableData parseCsvWithHeaders(const string& filename) {
    TableData table = parseCsvNoHeaders(filename);

    if (!table.body.empty()) {
        table.headers = table.body.front();
        table.body.erase(table.body.begin());
    }

    return table;
}
