#include <iostream>
#include <tuple>

template <typename T1, typename T2>
void printPair(const std::pair<T1, T2>& p) {
    auto [first, second] = p; // 使用结构化绑定解包 pair
    std::cout << "Pair: (" << first << ", " << second << ")" << std::endl;
}

int main() {
    std::pair<int, std::string> myPair = {1, "Apple"};
    printPair(myPair);

    return 0;
}