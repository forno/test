#include <bits/stdc++.h>
using namespace std;

template<typename T>
T get_value(std::istream& is);

// 以下に、24時間表記の時計構造体 Clock を定義する
struct Clock {
// Clock構造体のメンバ変数を書く
  int hour;//    時間を表す (0~23の値をとる)
  int minute;//  分を表す   (0~59の値をとる)
  int second;//  秒を表す   (0~59の値をとる)

// メンバ関数 set の定義を書く
//   関数名: set
//   引数: int h, int m, int s (それぞれ時、分、秒を表す)
//   返り値: なし
//   関数の説明:
//     時・分・秒を表す3つの引数を受け取り、
//     それぞれ、メンバ変数 hour, minute, second に代入する
  void set(int h, int m, int s)
  {
    hour = h;
    minute = m;
    second = s;
  }

// メンバ関数 to_str の定義を書く
//   関数名: to_str
//   引数: なし
//   返り値: string型
//   関数の仕様:
//     メンバ変数が表す時刻の文字列を返す
//     時刻の文字列は次のフォーマット
//     "HH:MM:SS"
//     HH、MM、SSはそれぞれ時間、分、秒を2桁で表した文字列
  string to_str()
  {
    string s {};
    s += (hour / 10 ? "" : "0");
    s += to_string(hour);
    s += ':';
    s += (minute / 10 ? "" : "0");
    s += to_string(minute);
    s += ':';
    s += (second / 10 ? "" : "0");
    s += to_string(second);
    return s;
  }

// メンバ関数 shift の定義を書く
//   関数名: shift
//   引数: int diff_second
//   返り値: なし
//   関数の仕様:
//     diff_second 秒だけメンバ変数が表す時刻を変更する(ただし、日付やうるう秒は考えない)
//     diff_second の値が負の場合、時刻を戻す
//     diff_second の値が正の場合、時刻を進める
//     diff_second の値は -86400 ~ 86400 の範囲を取とりうる
  void shift(int diff_second)
  {
    second += diff_second;
    minute += second / 60 + (second < 0 ? -1 : 0);
    hour += minute / 60 + (minute < 0 ? -1 : 0);
    hour %= 24;
    if (hour < 0)
      hour = 24 + hour;
    minute %= 60;
    if (minute < 0)
      minute = 60 + minute;
    second %= 60;
    if (second < 0)
      second = 60 + second;
  }

  void shift2(int diff_second)
  {
    int diff_hour = diff_second / 3600;
    diff_second %= 3600;
    int diff_minute = diff_second / 60;
    diff_second %= 60;

    second += diff_second;
    if (second >= 60) {
      // 分へ繰り上げ
      minute += 1;
      second -= 60;
    } else if (second < 0) {
      // 分から繰り下げ
      minute -= 1;
      second += 60;
    }

    minute += diff_minute;
    if (minute >= 60) {
      // 時へ繰り上げ
      hour += 1;
      minute -= 60;
    } else if (minute < 0) {
      // 時から繰り下げ
      hour -= 1;
      minute += 60;
    }

    hour += diff_hour;
    if (hour >= 24) {
      hour -= 24;
    } else if (hour < 0) {
      hour += 24;
    }
  }
};

// -------------------
// ここから先は変更しない
// -------------------

int main() {
  // Clock構造体のオブジェクトを宣言
  Clock clock, clock2;
  default_random_engine engine {random_device{}()};
  uniform_int_distribution<> hour_dist{0, 23}, min_sec_dist{0, 59}, diff_dist{-86400, 86400};
  int hour {};
  int minute {};
  int second {};
  int diff_second {};
  do {
    // 入力を受け取る
    hour = hour_dist(engine);
    minute = min_sec_dist(engine);
    second = min_sec_dist(engine);
    diff_second = diff_dist(engine);

    // set関数を呼び出して時刻を設定する
    clock.set(hour, minute, second);
    clock2.set(hour, minute, second);

    // 時計を進める(戻す)
    clock.shift(diff_second);
    clock2.shift2(diff_second);
  } while(clock.to_str() == clock2.to_str());

  cout << "hour:" << hour << " minute:" << minute << " second:" << second << '\n'
       << "diff_second:" << diff_second << '\n'
       << "clock: " << clock.to_str() << '\n'
       << "clock2: " << clock2.to_str() << '\n';
}

template<typename T>
inline T get_value(std::istream& is)
{
  T v;
  is >> v;
  return v;
}
