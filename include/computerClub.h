// Copyright 2024 Volodin Evgeniy
#ifndef COMPUTERCLUB_H
#define COMPUTERCLUB_H

#include "times.h"
#include <algorithm>
#include <map>
#include <queue>
#include <string>
#include <vector>

class Client {
  std::string name_;
  bool sit_;
  int table_id_;

public:
  Client() : sit_(false), table_id_(-1) {}
  explicit Client(std::string name, bool sit = false, const int table_id = -1)
      : name_(std::move(name)), sit_(sit), table_id_(table_id) {}

  std::string getName() const { return name_; }
  int getTableId() const { return table_id_; }
  bool isSit() const { return sit_; }

  void setSit(bool sit) { sit_ = sit; }
  void setTable(const int table_id) { table_id_ = table_id; }

  bool operator==(const Client &client) const { return name_ == client.name_; }
};

class Table {
  int id_;
  Client *client_;
  Time usedTime;
  Time startUsedTime;
  int cost_hour_;
  int profit = 0;

public:
  Table() : id_(-1), client_(nullptr), cost_hour_(0) {}
  explicit Table(const int id, const int cost_hour, Client *client = nullptr)
      : id_(id), client_(client), cost_hour_(cost_hour) {}

  int getId() const { return id_; }
  int getProfit() const { return profit; }
  Time getUsedTime() const { return usedTime; }
  bool isBusy() const { return client_ != nullptr; }

  void deleteClient();
  void addClient(Client *client);
};

class Club {
  std::vector<Table> tables;
  std::map<std::string, Client> clients;
  std::queue<Client> wait_clients;
  int num_tables_;
  int cost_hour_;
  Time time_open_;
  Time time_close_;

public:
  explicit Club(int num_tables, int cost_hour, const Time &time_open,
                const Time &time_close);

  void addClient(const std::string &clientName);
  void deleteClient(const std::string &clientName);
  void addClientToQueue(const std::string &clientName);
  void putClient(const std::string &clientName, const int &table_id);
  void close();

  Time getTimeOpen() { return time_open_; }
  Time getTimeClose() { return time_close_; }
};
#endif // COMPUTERCLUB_H
