#include "computerClub.h"
#include "exceptions.h"
#include "times.h"
#include "utils.h"
#include <fstream>
#include <iomanip>
#include <iostream>
#include <sstream>

int main(int argc, char *argv[]) {
  // Checking for arguments
  if (argc < 2) {
    std::cout << "Usage: <text_file.txt>" << std::endl;
    return 1;
  }

  // Opening the file for reading
  std::ifstream in(argv[1]);
  if (!in.is_open())
    return 1;

  // Initializing the input data
  int num_tables;
  Time time_open;
  Time time_close;
  int cost_hour;
  current_time = time_open;

  // Reading data from a file
  try {
    readInputData(in, num_tables, time_open, time_close, cost_hour);
  } catch (const ClubException &e) {
    std::cout << e.what() << std::endl;
    return 1;
  }

  // Print the opening time
  std::cout << time_open << std::endl;

  // Create club
  Club club(num_tables, cost_hour, time_open, time_close);

  std::string line;
  // Read each event line by line
  while (getline(in, line)) {
    if (line.empty())
      continue;

    // Output the read event
    std::cout << line << std::endl;

    // Passing the event to the stream and reading its components
    std::istringstream event(line);

    // Initializing the event data
    int id;
    std::string name;
    int table_id;

    try {
      readEvents(event, current_time, id, name, table_id);
    } catch (const ClubException &e) {
      std::cout << e.what() << std::endl;
      return 1;
    }

    // Processing the event
    try {
      processTheEvent(club, current_time, id, name, table_id);
    } catch (const ClubException &e) {
      std::cout << e.what() << std::endl;
      return 1;
    }
  }
  in.close();
  current_time = time_close;
  club.close();
  return 0;
}
