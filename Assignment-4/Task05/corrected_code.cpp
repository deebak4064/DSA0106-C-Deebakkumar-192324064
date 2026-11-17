#include <iostream>

class RawSocket {
public:
    void openPort(int port) {
        std::cout << "Port " << port << " opened." << std::endl;
    }
    void closePort() {
        std::cout << "Port closed." << std::endl;
    }
};

class SecureChannel : private RawSocket {
public:
    using RawSocket::closePort;   // Approach A: re-expose one base member

    void establishEncryptedTunnel(int port) {
        openPort(port);
        std::cout << "Tunnel encrypted with TLS 1.3" << std::endl;
    }
};

int main() {
    SecureChannel channel;
    channel.establishEncryptedTunnel(443);

    channel.closePort();          // now public in SecureChannel

    // Upcasting stays illegal: the base remains private by design
    // RawSocket *socketPtr = &channel;
    return 0;
}
