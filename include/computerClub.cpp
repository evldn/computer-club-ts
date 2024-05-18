// Copyright 2024 Volodin Evgeniy
#include "computerClub.h"
#include "exceptions.h"
#include <iostream>

void Table::deleteClient() {
  if (client_ == nullptr)
    return;
  const Time singleUsedTime = current_time - startUsedTime;
  usedTime = usedTime + singleUsedTime;
  profit += singleUsedTime.getHours() * cost_hour_;
  if (singleUsedTime.getMinutes() > 0) {
    profit += cost_hour_;
  }
  client_ = nullptr;
}

void Table::addClient(Client *client) {
  if (client_ != nullptr)
    return;
  client_ = client;
  startUsedTime = current_time;
}

Club::Club(const int num_tables, const int cost_hour, const Time &time_open,
           const Time &time_close)
    : num_tables_(num_tables), cost_hour_(cost_hour), time_open_(time_open),
      time_close_(time_close) {
  tables.resize(num_tables);
  std::ranges::generate(
      tables.begin(), tables.end(),
      [id = 1, cost_hour]() mutable { return Table(id++, cost_hour); });
}

void Club::addClient(const std::string &clientName) {
  auto it = clients.find(clientName);
  if (it != clients.end()) {
    throw ClubException(" 13 YouShallNotPass");
  }
  clients[clientName] = Client(clientName);
}

void Club::deleteClient(const std::string &clientName) {
  const auto &it = clients.find(clientName);
  if (it != clients.end()) {
    if (it->second.isSit()) {
      const int &table_id = it->second.getTableId();
      tables[table_id - 1].deleteClient();
      if (!wait_clients.empty()) {
        tables[table_id - 1].addClient(
            &clients[wait_clients.front().getName()]);
        clients[wait_clients.front().getName()].setSit(true);
        clients[wait_clients.front().getName()].setTable(table_id);
        std::cout << current_time << " 12 " << wait_clients.front().getName()
                  << " " << table_id << std::endl;
        wait_clients.pop();
      }
    }
    clients.erase(clientName);
  } else {
    throw ClubException(" 13 ClientUnknown");
  }
}

void Club::addClientToQueue(const std::string &clientName) {
  const auto &it =
      std::ranges::find_if(tables.begin(), tables.end(),
                           [](const Table &table) { return !table.isBusy(); });
  if (it != tables.end()) {
    throw ClubException(" 13 ICanWaitNoLonger!");
  }
  if (wait_clients.size() >= num_tables_) {
    clients.erase(clientName);
    std::cout << current_time << " 11 " << clientName << std::endl;
  }
  wait_clients.push(clients[clientName]);
}

void Club::putClient(const std::string &clientName, const int &table_id) {
  const auto &it = clients.find(clientName);
  if (it != clients.end()) {
    if (tables[table_id - 1].isBusy()) {
      throw ClubException(" 13 PlaceIsBusy");
    }
    if (it->second.isSit()) {
      tables[it->second.getTableId() - 1].deleteClient();
    }
    tables[table_id - 1].addClient(&it->second);
    it->second.setTable(table_id);
    it->second.setSit(true);
  } else {
    throw ClubException(" 13 ClientUnknown");
  }
}

void Club::close() {
  while (!wait_clients.empty())
    wait_clients.pop();
  for (auto &[name, info] : clients) {
    std::cout << current_time << " 11 " << name << std::endl;
  }
  clients.clear();
  std::cout << current_time << std::endl;
  for (Table &table : tables) {
    table.deleteClient();
    std::cout << table.getId() << " " << table.getProfit() << " "
              << table.getUsedTime() << std::endl;
  }
}