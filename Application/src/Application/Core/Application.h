#pragma once

#include <Spider/Webserver/Webserver.h>


namespace Todo {

class Application {
public:
  Application();
  ~Application();

  void Run();
private:
  Ref<Spider::Webserver> m_Server;
};

}
