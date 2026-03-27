#include "tdpch.h"
#include "Application.h"

#include <sqlite3.h>

#include <Spider/Webserver/Webserver.h>
#include "Application/Routes/Routes.h"

using namespace Todo;

int main(void) {
  Ref<Spider::Webserver> server = CreateRef<Spider::Webserver>(8080);

  RouteManager manager(server);


  server->Run();

  return 0;
}
