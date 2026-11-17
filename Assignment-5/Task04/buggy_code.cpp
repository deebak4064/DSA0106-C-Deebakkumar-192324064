#include <iostream>

class NetworkPacket {
public:
    virtual ~NetworkPacket() {}

    // Pure Virtual Functions
    virtual void serialize() = 0;
    virtual int getPacketSize() = 0;
};

// Subclass fails to override getPacketSize()
class VideoPacket : public NetworkPacket {
private:
    int frameID;

public:
    VideoPacket(int id) : frameID(id) {}

    void serialize() override {
        std::cout << "Serializing H.264 Video Frame: " << frameID << std::endl;
    }
    // Missing getPacketSize() override!
};

int main() {
    // Line 25: Attempting to instantiate VideoPacket!
    VideoPacket packet(1042);
    packet.serialize();
    return 0;
}
