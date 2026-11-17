#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

class GameObject {
protected:
    string name;
public:
    GameObject(const string &n) : name(n) {}
    virtual ~GameObject() { cout << "  ~GameObject(" << name << ")" << endl; }
    virtual void Update(double deltaTime) = 0;
    virtual void Render() const = 0;
};

class ParticleSystem : public GameObject {
private:
    int particleCount;
    double *coords;               // x0, y0, x1, y1, ...
    double velocity;
public:
    ParticleSystem(const string &n, int count, double v)
        : GameObject(n), particleCount(count), velocity(v) {
        coords = new double[particleCount * 2];
        for (int i = 0; i < particleCount * 2; ++i) coords[i] = 0.0;
        cout << "ParticleSystem " << name << ": allocated " << particleCount * 2
             << " coordinates on heap" << endl;
    }
    ~ParticleSystem() override {
        cout << "  ~ParticleSystem(" << name << "): releasing particle array" << endl;
        delete[] coords;
    }
    void Update(double deltaTime) override {
        for (int i = 0; i < particleCount; ++i) {
            coords[2 * i]     += velocity * deltaTime * (i + 1);
            coords[2 * i + 1] += velocity * deltaTime;
        }
    }
    void Render() const override {
        cout << "Render " << name << ": " << particleCount << " particles, p0 = ("
             << coords[0] << ", " << coords[1] << ")" << endl;
    }
};

class PlayerSprite : public GameObject {
private:
    double x;
public:
    PlayerSprite(const string &n) : GameObject(n), x(0.0) {}
    ~PlayerSprite() override { cout << "  ~PlayerSprite(" << name << ")" << endl; }
    void Update(double deltaTime) override { x += 5.0 * deltaTime; }
    void Render() const override { cout << "Render " << name << ": x = " << x << endl; }
};

int main() {
    const int N = 2;
    GameObject *sceneEntities[N];
    sceneEntities[0] = new ParticleSystem("Smoke", 500, 2.0);
    sceneEntities[1] = new PlayerSprite("Hero");
    cout << fixed << setprecision(2);

    cout << "-- Simulation step (dt = 0.016) --" << endl;
    for (int i = 0; i < N; ++i) {
        sceneEntities[i]->Update(0.016);
        sceneEntities[i]->Render();
    }

    cout << "-- Cleanup --" << endl;
    for (int i = 0; i < N; ++i) {
        delete sceneEntities[i];          // virtual destructor
        sceneEntities[i] = nullptr;
    }
    return 0;
}
