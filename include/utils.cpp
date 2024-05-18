// Copyright 2024 Volodin Evgeniy
#include "utils.h"
#include "exceptions.h"
#include <algorithm>
#include <iostream>
#include <istream>
#include <sstream>

bool isPositiveDigit(const std::string &var) {
  for (const auto &d : var) {
    if (!std::isdigit(d)) {
      return false;
    }
  }
  if (std::stoi(var) < 0)
    return false;
  return true;
}

bool isValidName(const std::string &str) {
  return std::ranges::all_of(str.begin(), str.end(), [](const char c) {
    return std::isalnum(static_cast<unsigned char>(c)) || c == '_' || c == '-';
  });
}

void readInputData(std::istream &in, int &num_tables, Time &time_open,
                   Time &time_close, int &cost_hour) {
  std::string line;
  // Read the number of tables
  getline(in, line);
  if (!isPositiveDigit(line)) {
    throw ClubException(line + "\n" +
                        "Input error \"num_tables\": the number must be an "
                        "integer and positive!");
  }
  num_tables = std::stoi(line);

  // Read the times
  getline(in, line);
  std::istringstream iss(line);
  try {
    iss >> time_open >> time_close;
  } catch (const ClubException &e) {
    throw ClubException(line + "\n" + "Input error time: " + e.what());
  }

  // Read the cost of an hour
  getline(in, line);
  if (!isPositiveDigit(line)) {
    throw ClubException(line + "\n" +
                        "Input error \"cost_hour\": the number must be an "
                        "integer and positive!");
  }
  cost_hour = std::stoi(line);
}

void readEvents(std::istringstream &event, Time &current_time, int &id,
                std::string &name, int &table_id) {
  // Read the time
  try {
    Time time;
    event >> time;
    if (current_time > time) {
      throw ClubException("Error time: time must go on consistently!");
    }
    current_time = time;
  } catch (const ClubException &e) {
    throw ClubException("Input error time: " + std::string(e.what()));
  }

  // Read the id
  std::string id_str;
  event >> id_str;
  if (!isPositiveDigit(id_str)) {
    throw ClubException("Input error id: must be digit!");
  }
  id = std::stoi(id_str);

  // Read the name
  event >> name;
  if (!isValidName(name)) {
    throw ClubException("Input error name: invalid name!");
  }

  // Read the table_id
  event >> table_id;
}

void processTheEvent(Club &club, const Time &current_time, const int &id,
                     const std::string &name, const int &table_id) {
  switch (id) {
  // The client has arrived
  case 1: {
    if (current_time > club.getTimeOpen() &&
        current_time < club.getTimeClose()) {
      try {
        club.addClient(name);
      } catch (const ClubException &e) {
        std::cout << current_time << e.what() << std::endl;
      }
    } else {
      std::cout << current_time << " 13 "
                << "NotOpenYet" << std::endl;
    }
    break;
  }

  // The client wants to sit at the table
  case 2: {
    try {
      club.putClient(name, table_id);
    } catch (const ClubException &e) {
      std::cout << current_time << e.what() << std::endl;
    }
    break;
  }

  // The client is waiting
  case 3: {
    try {
      club.addClientToQueue(name);
    } catch (const ClubException &e) {
      std::cout << current_time << e.what() << std::endl;
    }
    break;
  }

  // The client has left
  case 4: {
    try {
      club.deleteClient(name);
    } catch (const ClubException &e) {
      std::cout << current_time << e.what() << std::endl;
    }
    break;
  }

  // The case when the id is entered incorrectly
  default: {
    throw ClubException("Input error id: unknown id!");
  }
  }
}