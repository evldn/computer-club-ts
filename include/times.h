// Copyright 2024 Volodin Evgeniy
#ifndef TIME_H
#define TIME_H
#include <istream>
#include <string>

class Time {
  int hours;
  int minutes;

public:
  Time() : hours(0), minutes(0) {}
  explicit Time(const std::string &time);
  explicit Time(const int &minutes_);

  int getHours() const { return hours; }
  int getMinutes() const { return minutes; }

  bool operator<(const Time &time) const;
  bool operator>(const Time &time) const;

  Time &operator=(const Time &time);

  Time operator+(const Time &time) const;
  Time operator-(const Time &time) const;

  friend std::istream &operator>>(std::istream &in, Time &time);
  friend std::ostream &operator<<(std::ostream &out, const Time &time);
};

inline Time current_time{};

#endif // TIME_H
