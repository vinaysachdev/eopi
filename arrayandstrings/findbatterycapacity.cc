#include <iostream>
#include <vector>
#include <algorithm>

#define typedef int HeightType;

template <typename HeightType>
HeightType find_battery_capacity(const std::vector<HeightType> & vecHT) {
    HeightType minHeight = std::numeric_limits<int>::max();
    HeightType capacity = 0;

    for(auto height : vecHT) {
        capacity = max(capacity, height - minHeight);
        minHeight = min(minHeight, height);
    }
    return capacity;
}
