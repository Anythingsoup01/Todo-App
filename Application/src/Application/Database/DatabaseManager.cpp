#include "tdpch.h"
#include "DatabaseManager.h"

namespace Todo {

// ////////////////////////////////
// DATABASE ///////////////////////
// ////////////////////////////////

Database::Database(const std::filesystem::path &path) {
  if (sqlite3_open(path.c_str(), &m_Handle) != SQLITE_OK) {
    throw std::runtime_error("Could not open " + path.string());
  }
}

Database::~Database() {
  if (!m_Handle) {
    sqlite3_close(m_Handle);
  }
}

// ////////////////////////////////
// DATABASE MANAGER ///////////////
// ////////////////////////////////

DatabaseManager::DatabaseManager() {

}

DatabaseManager::~DatabaseManager() {

}

void DatabaseManager::AddDatabase(const std::filesystem::path &path) {
  m_DatabaseList.emplace_back(path);
}

DatabaseManager &DatabaseManager::GetMutable() {
  static DatabaseManager s_Instance;
  return s_Instance;
}

}
