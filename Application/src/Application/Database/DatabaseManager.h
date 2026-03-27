#pragma once

#include <sqlite3.h>

namespace Todo {

class Database {
public:
  Database(const std::filesystem::path &path);
  ~Database();

  Database(const Database &) = delete;
  Database &operator=(const Database &) = delete;

  Database(Database&& other) noexcept : m_Handle(other.GetHandle()) {
    other.ClearHandle();
  }

private:
  sqlite3 *GetHandle() { return m_Handle; }
  void ClearHandle() { m_Handle = nullptr; }

private:
  sqlite3 *m_Handle;
};


class DatabaseManager {
public:
  DatabaseManager();
  ~DatabaseManager();
  void AddDatabase(const std::filesystem::path &path);

  static DatabaseManager &GetMutable();
private:
  std::vector<Database> m_DatabaseList;
};

}
