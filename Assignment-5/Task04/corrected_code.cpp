#include <iostream>

class NetworkPacket {
public:
    virtual ~NetworkPacket() {}
    virtual void serialize() = 0;
    virtual int getPacketSize() = 0;
};

class VideoPacket : public NetworkPacket {
private:
    int frameID;

public:
    VideoPacket(int id) : frameID(id) {}

    void serialize() override {
        std::cout << "Serializing H.264 Video Frame: " << frameID << std::endl;
    }

    // Now every pure virtual function is overridden: VideoPacket is concrete
    int getPacketSize() override {
        return 1500; // bytes (one Ethernet MTU)
    }
};

int main() {
    VideoPacket packet(1042);
    packet.serialize();
    std::cout << "Packet size: " << packet.getPacketSize() << " bytes" << std::endl;

    // Used through the abstract interface
    NetworkPacket *p = &packet;
    std::cout << "Via NetworkPacket*: " << p->getPacketSize() << " bytes" << std::endl;
    return 0;
}
