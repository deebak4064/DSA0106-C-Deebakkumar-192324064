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

// Line 13: Private inheritance used
class SecureChannel : private RawSocket {
public:
    void establishEncryptedTunnel(int port) {
        openPort(port); // Legal inside derived class
        std::cout << "Tunnel encrypted with TLS 1.3" << std::endl;
    }
};

int main() {
    SecureChannel channel;
    channel.establishEncryptedTunnel(443);

    // Line 24: Calling base method from outside
    channel.closePort(); // Compilation Error!

    // Line 27: Upcasting with private inheritance
    RawSocket *socketPtr = &channel; // Compilation Error!

    return 0;
}
