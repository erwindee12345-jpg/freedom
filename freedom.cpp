#include <iostream>

struct Session {
    char user[16];
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
    logout(session);

    audit(session);
    return 0;
}