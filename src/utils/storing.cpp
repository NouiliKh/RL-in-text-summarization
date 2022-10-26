//
// Created by khalil Nouili on 26.10.22.
//

#include <vector>
#include <fstream>

void save_data(std::vector<std::vector<std::string>> data_to_save, std::string filepath){
    std::ofstream out(filepath);
    for (auto& row : data_to_save) {
        for (auto col : row)
            out << col <<',';
        out << '\n';
    }
}
