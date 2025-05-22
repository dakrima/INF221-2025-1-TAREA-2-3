#ifndef PD_SEQUENCE_DIFFERENCE_H
#define PD_SEQUENCE_DIFFERENCE_H

#include <string>
#include <vector>
#include <utility>

namespace pd {
    std::vector<std::pair<std::string, std::string>>
    sequenceDifference(const std::string& s, const std::string& t);
}

#endif
