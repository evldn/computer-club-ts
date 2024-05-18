// Copyright 2024 Volodin Evgeniy
#ifndef EXCEPTIONS_H
#define EXCEPTIONS_H

#include <exception>
#include <string>
#include <utility>

class ClubException : public std::exception {
  std::string message;

public:
  explicit ClubException(std::string msg) : message(std::move(msg)) {}

  const char *what() const noexcept override { return message.c_str(); }
};

#endif // EXCEPTIONS_H
