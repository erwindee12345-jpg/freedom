#include <iostream>

struct Session {
    std::string user;
    int requests;   
};

static void logout(Session *session) {
    std::cout << "logging out " << session->user << "\n";
    delete session;
}

static void audit(const Session *session) {
    std::cout << "audit: " << session->user << " made " << session->requests << " requests\n";
}

int main() {

    Session *session = new Session{"alice", 3};
    audit(session);
    logout(session);

    session = nullptr;
    return 0;
}