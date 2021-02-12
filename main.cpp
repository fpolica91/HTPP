#include <iostream>
#include "htpp.hpp"

void Root(Request* req) {
    req->Respond(200, "<b style=\"font-size: 50px\">Hello World!</b>");
}

void Post(Request* req) {
    std::cout << req->Body << "\n";

    req->Respond(200, "");
}

int main() {
  Server server = Server();

  server.SetCGIDir("/cgi", "dir");

  server.Get("/", Root);

  server.Post("/post", Post);

  server.Start(8080);

  while (server.Running);
}