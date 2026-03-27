#include "tdpch.h"
#include "Routes.h"

namespace Todo {

RouteManager::RouteManager(const Ref<Webserver> &server)
{
  server->HandleRoute("/", HandleRoot);
}

RouteManager::~RouteManager() {

}

std::string RouteManager::HandleRoot(const RequestMethod &method, const std::string &jsonData) {
  return "HTTP/1.1 200 OK";
}

}
