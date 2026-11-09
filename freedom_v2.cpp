#include <iostream>
#include <memory>

struct Session {
    std::string user;
    int requests;   
};

static void logout(std::unique_ptr<Session> session) {
    std::cout << "logging out " << session->user << "\n";
}

static void audit(const Session *session) {
    std::cout << "audit: " << session->user << " made " << session->requests << " requests\n";
}

int main() {

    auto session = std::make_unique<Session>(Session{"alice", 3});
    audit(session.get());
    logout(std::move(session));

    return 0;
}