// Copyright 2024 Volodin Evgeniy
#include "times.h"
#include "exceptions.h"
#include <iomanip>

Time::Time(const std::string &time) {
  if (time.length() != 5 || time[2] != ':') {
    throw ClubException("time-format: \"XX:XX\"");
  }
  if (!std::isdigit(time[0]) || !std::isdigit(time[1]) ||
      !std::isdigit(time[3]) || !std::isdigit(time[4])) {
    throw ClubException("time must be digit");
  }
  const int h = std::stoi(time.substr(0, 2));
  const int m = std::stoi(time.substr(3, 2));

  if (h < 0 || h > 23 || m < 0 || m > 59) {
    throw ClubException(
        "time-borders: 0 <= hours <= 23 and 0 <= minutes <= 59");
  }
  hours = h;
  minutes = m;
}

Time::Time(const int &minutes_) {
  hours = minutes_ / 60;
  minutes = minutes_ % 60;
}

bool Time::operator<(const Time &time) const {
  if (hours < time.hours) {
    return true;
  }
  if (hours == time.hours && minutes < time.minutes) {
    return true;
  }
  return false;
}

bool Time::operator>(const Time &time) const { return !operator<(time); }

Time &Time::operator=(const Time &time) {
  if (this == &time) {
    return *this;
  }
  hours = time.hours;
  minutes = time.minutes;
  return *this;
}

Time Time::operator+(const Time &time) const {
  const int min_1 = hours * 60 + minutes;
  const int min_2 = time.hours * 60 + time.minutes;
  return Time(min_1 + min_2);
}

Time Time::operator-(const Time &time) const {
  const int min_1 = hours * 60 + minutes;
  const int min_2 = time.hours * 60 + time.minutes;
  return Time(min_1 - min_2);
}

std::istream &operator>>(std::istream &in, Time &time) {
  std::string time_str;
  in >> time_str;
  if (time_str.length() != 5 || time_str[2] != ':') {
    throw ClubException("time-format: \"XX:XX\"");
  }
  if (!std::isdigit(time_str[0]) || !std::isdigit(time_str[1]) ||
      !std::isdigit(time_str[3]) || !std::isdigit(time_str[4])) {
    throw ClubException("time must be digit");
  }
  const int hours = std::stoi(time_str.substr(0, 2));
  const int minutes = std::stoi(time_str.substr(3, 2));

  if (time.hours < 0 || time.hours > 23 || time.minutes < 0 ||
      time.minutes > 59) {
    throw ClubException("time-format: 0 <= hours <= 23 and 0 <= minutes <= 59");
  }

  time.hours = hours;
  time.minutes = minutes;
  return in;
}

std::ostream &operator<<(std::ostream &out, const Time &time) {
  out << std::setw(2) << std::setfill('0') << time.hours << ":" << std::setw(2)
      << std::setfill('0') << time.minutes;
  return out;
}