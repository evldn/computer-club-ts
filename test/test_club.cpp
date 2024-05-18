#include "times.h"
#include "computerClub.h"
#include <sstream>
#include <iostream>
#include <fstream>
#include <iomanip>
#include "exceptions.h"
#include "utils.h"
#include <gtest.h>

TEST(ComputerClub, test_1)
{
    std::ifstream in("test1.txt");
    ASSERT_FALSE(!in.is_open());

    int num_tables;
    Time time_open;
    Time time_close;
    int cost_hour;
    current_time = time_open;

    ASSERT_NO_THROW(readInputData(in, num_tables, time_open, time_close, cost_hour));

    ASSERT_EQ(num_tables, 3);
    ASSERT_EQ(time_open.getHours(), 9);
    ASSERT_EQ(time_open.getMinutes(), 0);
    ASSERT_EQ(time_close.getHours(), 19);
    ASSERT_EQ(time_close.getMinutes(), 0);
    ASSERT_EQ(cost_hour, 10);

    Club club(num_tables, cost_hour, time_open, time_close);

    std::string line;
    while (getline(in, line)) {
        if (line.empty()) continue;

        std::istringstream event(line);

        int id;
        std::string name;
        int table_id;

        ASSERT_NO_THROW(readEvents(event, current_time, id, name, table_id));

        ASSERT_NO_THROW(processTheEvent(club, current_time, id, name, table_id));
    }
    in.close();
}

TEST(ComputerClub, test_2)
{
    std::ifstream in("test2.txt");
    ASSERT_FALSE(!in.is_open());

    int num_tables;
    Time time_open;
    Time time_close;
    int cost_hour;
    current_time = time_open;

    ASSERT_NO_THROW(readInputData(in, num_tables, time_open, time_close, cost_hour));

    ASSERT_EQ(num_tables, 4);
    ASSERT_EQ(time_open.getHours(), 8);
    ASSERT_EQ(time_open.getMinutes(), 0);
    ASSERT_EQ(time_close.getHours(), 18);
    ASSERT_EQ(time_close.getMinutes(), 0);
    ASSERT_EQ(cost_hour, 5);

    Club club(num_tables, cost_hour, time_open, time_close);

    std::string line;
    while (getline(in, line)) {
        if (line.empty()) continue;

        std::istringstream event(line);

        int id;
        std::string name;
        int table_id;

        ASSERT_NO_THROW(readEvents(event, current_time, id, name, table_id));

        ASSERT_NO_THROW(processTheEvent(club, current_time, id, name, table_id));
    }
    in.close();
}

TEST(ComputerClub, test_3)
{
    std::ifstream in("test3.txt");
    ASSERT_FALSE(!in.is_open());

    int num_tables;
    Time time_open;
    Time time_close;
    int cost_hour;
    current_time = time_open;

    ASSERT_NO_THROW(readInputData(in, num_tables, time_open, time_close, cost_hour));

    ASSERT_EQ(num_tables, 5);
    ASSERT_EQ(time_open.getHours(), 10);
    ASSERT_EQ(time_open.getMinutes(), 0);
    ASSERT_EQ(time_close.getHours(), 22);
    ASSERT_EQ(time_close.getMinutes(), 0);
    ASSERT_EQ(cost_hour, 8);

    Club club(num_tables, cost_hour, time_open, time_close);

    std::string line;
    while (getline(in, line)) {
        if (line.empty()) continue;

        std::istringstream event(line);

        int id;
        std::string name;
        int table_id;

        ASSERT_NO_THROW(readEvents(event, current_time, id, name, table_id));

        ASSERT_NO_THROW(processTheEvent(club, current_time, id, name, table_id));
    }
    in.close();
}

TEST(ComputerClub, test_4)
{
    std::ifstream in("test4.txt");
    ASSERT_FALSE(!in.is_open());

    int num_tables;
    Time time_open;
    Time time_close;
    int cost_hour;
    current_time = time_open;

    ASSERT_NO_THROW(readInputData(in, num_tables, time_open, time_close, cost_hour));

    ASSERT_EQ(num_tables, 6);
    ASSERT_EQ(time_open.getHours(), 9);
    ASSERT_EQ(time_open.getMinutes(), 0);
    ASSERT_EQ(time_close.getHours(), 17);
    ASSERT_EQ(time_close.getMinutes(), 0);
    ASSERT_EQ(cost_hour, 3);

    Club club(num_tables, cost_hour, time_open, time_close);

    std::string line;
    while (getline(in, line)) {
        if (line.empty()) continue;

        std::istringstream event(line);

        int id;
        std::string name;
        int table_id;

        ASSERT_NO_THROW(readEvents(event, current_time, id, name, table_id));

        ASSERT_NO_THROW(processTheEvent(club, current_time, id, name, table_id));
    }
    in.close();
}