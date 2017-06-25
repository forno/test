#include <iostream>
#include <iomanip>

int main(void){
    double min {100}, max {200};
    int length;
    std::cin >> length;
    for (auto i {length}; i > 0; --i) {
        std::string s;
        std::cin >> s;
        double size;
        std::cin >> size;
        if (s == "le")
            max = std::min(max, size);
        else
            min = std::max(min, size);
    }
    std::cout << std::fixed << std::setprecision(1) << min << ' ' << max;
    return 0;
}

