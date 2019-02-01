#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Score
{
public:
    int total() const
    {
        return total_;
    }
    
    int win() const
    {
        return win_;
    }
    
    int draw() const
    {
        return draw_;
    }
    
    int lose() const
    {
        return total_ - win_ * 2 - draw_;
    }
    
    void add(const char c)
    {
        switch (c) {
            case 'W':
            ++win_;
            total_ += 2;
            break;
            case 'D':
            ++draw_;
            ++total_;
            break;
            default:
            ;
        }
    }
private:
    int total_;
    int win_;
    int draw_;
};

namespace std
{
    inline std::ostream& operator<<(std::ostream& os, const Score& s)
    {
        os << s.total() << ' ' << s.win() << ' ' << s.draw() << ' ' << s.lose();
        return os;
    }
}

int main(void){
    std::size_t length;
    std::cin >> length;
    std::vector<Score> scores(length);
    for (auto& v : scores) {
        for (auto i {length}; i; --i) {
            char c;
            std::cin >> c;
            v.add(c);
        }
    }

    const auto max_score {max_element(scores.begin(), scores.end(), [](const auto& lhs, const auto& rhs){
        return lhs.total() < rhs.total();
    })};
    cout << max_score - scores.begin() + 1 << ' ' << *max_score;
    return 0;
}
