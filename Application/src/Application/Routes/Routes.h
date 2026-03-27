#pragma once

#include "Spider/Webserver/Webserver.h"

using namespace Spider;

namespace Todo {

class RouteManager {
public:
  RouteManager(const Ref<Webserver> &server);
  ~RouteManager();

private:
  static std::string HandleRoot(const RequestMethod &method, const std::string &jsonData);
};

}
