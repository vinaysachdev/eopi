#include <iostream>
#include <vector>
#include <algorithm>

void print(int i) {
    std::cout << i << " ";
}

// this algorithm maintains following invariant during partitioning
// vec[0 : j] less than pivot
// vec[j+1 : k] equal to pivot 
// vec[k+1 : i] greater than pivot
// vec[i+1 : size-1] unclassified
void dutch_flag_partition(std::vector<int>& vec, int indx) {
    if(vec.size() == 0 || indx <0 || indx >= vec.size())
        return;
    int tmp = vec[indx];
    int j = -1, k = -1;
    for(int i = 0; i < vec.size(); ++i) {
        if(vec[i] < tmp) {
            std::swap(vec[++j], vec[i]);
            std::swap(vec[i], vec[++k]);
        }
        else if(vec[i] == tmp) {
            std::swap(vec[++k], vec[i]);
        }
    }
}


int main() {
    std::vector<int> vec = {2,4,9,6,7,3,0,4,5};
    int num;
    std::cout << "Before partition"<<"\n";
    for_each(vec.begin(), vec.end(), print);
    std::cout << "\nEnter the indx you want to partition around: ";
    std::cin >> num;
    dutch_flag_partition(vec, num);
    std::cout << "\nAfter partition"<<"\n";
    for_each(vec.begin(), vec.end(), print);
    std::cout<< "\n";
    
    return 0;
}
