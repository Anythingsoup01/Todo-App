#include "tdpch.h"
#include "Application.h"

#include <sqlite3.h>

#include <Spider/Webserver/Webserver.h>
#include "Application/Routes/Routes.h"
#include "Application/Database/DatabaseManager.h"

namespace Todo {

Application::Application()
  : m_Server(CreateRef<Spider::Webserver>(8080)) {

  DatabaseManager::GetMutable().AddDatabase("credentials.db");

  RouteManager manager(m_Server);

}

Application::~Application() {

}

void Application::Run() {
  m_Server->Run();
}

}

int main(void) {

  Todo::Application app;
  app.Run();

  return 0;
}
