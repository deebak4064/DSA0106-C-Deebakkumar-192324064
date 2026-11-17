#include <iostream>

class AudioBuffer {
public:
    int *samples;
    int capacity;

    AudioBuffer(int cap) : capacity(cap) {
        samples = new int[capacity];
        for (int i = 0; i < capacity; ++i) {
            samples[i] = i * 10;
        }
        std::cout << "Buffer allocated at: " << samples << std::endl;
    }

    // Programmer omitted copy constructor!

    ~AudioBuffer() {
        std::cout << "Deallocating buffer at: " << samples << std::endl;
        delete[] samples; // Crash occurs here during execution!
    }
};

void processAudio(AudioBuffer buf) { // Passed by value!
    std::cout << "Processing sample 0: " << buf.samples[0] << std::endl;
}

int main() {
    AudioBuffer track(5);
    processAudio(track);
    std::cout << "Back in main, sample 0: " << track.samples[0] << std::endl;
    return 0;
}
