#include <iostream>
#include <iomanip>
#include <string>
#include <stdexcept>
#include <cstdint>
using namespace std;

class ResourceGuard {
private:
    string resourceName;
    int handle;
public:
    ResourceGuard(const string &name) : resourceName(name), handle(3) {
        cout << "[ACQUIRE] handle " << handle << " opened for " << resourceName << endl;
    }
    ~ResourceGuard() {
        cout << "[RELEASE] handle " << handle << " closed for " << resourceName << endl;
    }
};

class CRCValidationException {
private:
    uint32_t expected, calculated;
public:
    CRCValidationException(uint32_t e, uint32_t c) : expected(e), calculated(c) {}
    uint32_t GetExpected() const { return expected; }
    uint32_t GetCalculated() const { return calculated; }
};

uint32_t ComputeCRC32(const string &data) {
    uint32_t crc = 0xFFFFFFFF;
    for (unsigned char byte : data) {
        crc ^= byte;
        for (int k = 0; k < 8; ++k)
            crc = (crc >> 1) ^ (0xEDB88320 & (0 - (crc & 1)));
    }
    return ~crc;
}

void IngestDataStream(const string &fileName) {
    if (fileName.empty()) throw invalid_argument("empty file name");
    ResourceGuard guard(fileName);            // RAII: local automatic object
    const string dataBlocks = "TELEMETRY:ALT=10450;SPD=812;HDG=274";
    const uint32_t expectedCRC = 0x1C291CA3;  // checksum stored in file header
    cout << "Reading " << dataBlocks.size() << " bytes of data blocks..." << endl;
    uint32_t calculatedCRC = ComputeCRC32(dataBlocks);
    cout << "CRC computed: 0x" << hex << uppercase << calculatedCRC << dec << endl;
    if (calculatedCRC != expectedCRC) {
        cout << "CRC mismatch -> throwing CRCValidationException" << endl;
        throw CRCValidationException(expectedCRC, calculatedCRC);
    }
    cout << "Data accepted." << endl;          // skipped when an exception is thrown
}

void RunIngestion(const string &fileName) {
    cout << "== IngestDataStream(\"" << fileName << "\") ==" << endl;
    try {
        IngestDataStream(fileName);
    }
    catch (const CRCValidationException &e) {
        cout << "[CATCH] CRC error: expected 0x" << hex << uppercase << e.GetExpected()
             << ", calculated 0x" << e.GetCalculated() << dec << endl;
    }
    catch (...) {
        cout << "[CATCH-ALL] unexpected failure; pipeline halted safely" << endl;
    }
}

int main() {
    RunIngestion("telemetry_0423.bin");
    RunIngestion("");
    return 0;
}
