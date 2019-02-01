#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Score
{
public:
    int total() const
    {
        return win_ * 2 + draw;
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
        return lose_;
    }
    
    void add(const char c)
    {
        switch (c) {
            case 'W':
            ++win_;
            break;
            case 'D':
            ++draw_;
            case 'L':
            ++lose_;
            break;
            default:
            ;
        }
    }
private:
    int win_;
    int draw_;
    int lose_;
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
