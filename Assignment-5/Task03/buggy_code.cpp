#include <iostream>
#include <exception>
#include <string>

class DatabaseError : public std::exception {
protected:
    std::string errorDetails;
public:
    DatabaseError(std::string msg) : errorDetails(msg) {}
    const char* what() const noexcept override {
        return errorDetails.c_str();
    }
};

class TimeoutError : public DatabaseError {
public:
    int timeoutMs;
    TimeoutError(std::string msg, int ms)
        : DatabaseError(msg), timeoutMs(ms) {}
};

void executeQuery() {
    throw TimeoutError("Query timed out connecting to shard 3", 5000);
}

void intermediateAuditor() {
    try {
        executeQuery();
    }
    catch (const DatabaseError &e) {
        std::cout << "[AUDIT LOG]: Intercepted DB error." << std::endl;

        // Line 32: Slicing rethrow bug!
        throw e; // Throws a copy of static type DatabaseError!
    }
}

int main() {
    try {
        intermediateAuditor();
    }
    catch (const TimeoutError &te) {
        std::cout << "Client caught TimeoutError! Duration: " << te.timeoutMs << " ms" << std::endl;
    }
    catch (const DatabaseError &de) {
        std::cout << "Client caught generic DatabaseError: " << de.what() << std::endl;
    }
    return 0;
}
