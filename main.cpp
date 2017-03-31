#include <iostream>
#include <utility>

using battle_pair = std::pair<int, int>;
using time_pair = std::pair<int, int>;

int main(void){
    battle_pair first_block;
    std::cin >> first_block.first >> first_block.second;
    if (first_block.second < first_block.first) std::swap(first_block.first, first_block.second);
    battle_pair second_block;
    std::cin >> second_block.first >> second_block.second;
    if (second_block.second < second_block.first) std::swap(second_block.first, second_block.second);

    battle_pair final_block;
    time_pair first_block_time;
    std::cin >> first_block_time.first >> first_block_time.second;
    final_block.first = first_block_time.first < first_block_time.second ? first_block.first : first_block.second;
    time_pair second_block_time;
    std::cin >> second_block_time.first >> second_block_time.second;
    std::cout << second_block_time.first << second_block_time.second;
    final_block.second = second_block_time.first < second_block_time.second ? second_block.first : second_block.second;
    if (final_block.second < final_block.first) std::swap(final_block.first, final_block.second);

    time_pair final_block_time;
    std::cin >> final_block_time.first >> final_block_time.second;
    std::cout << (final_block_time.first < final_block_time.second ? final_block.first : final_block.second) << '\n' <<
                 (final_block_time.first < final_block_time.second ? final_block.second : final_block.first) << '\n';
    return 0;
}

