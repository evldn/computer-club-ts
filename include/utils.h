// Copyright 2024 Volodin Evgeniy
#ifndef UTILS_H
#define UTILS_H
#include "computerClub.h"
#include "times.h"
#include <string>

bool isPositiveDigit(const std::string &var);

bool isValidName(const std::string &str);

void readInputData(std::istream &in, int &num_tables, Time &time_open,
                   Time &time_close, int &cost_hour);

void readEvents(std::istringstream &event, Time &current_time, int &id,
                std::string &name, int &table_id);

void processTheEvent(Club &club, const Time &current_time, const int &id,
                     const std::string &name, const int &table_id);

#endif // UTILS_H
