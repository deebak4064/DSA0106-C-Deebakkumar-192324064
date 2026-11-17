#include <iostream>

class Entity {
public:
    virtual ~Entity() {}
    virtual void attack() const {
        std::cout << "Entity performs generic scratch." << std::endl;
    }
};

class Dragon : public Entity {
public:
    void attack() const override {
        std::cout << "Dragon breathes scorching fire!" << std::endl;
    }
};

// Pass by const reference: no copy, the object keeps its own vptr
void triggerEncounter(const Entity &e) {
    e.attack();
}

// Pointer version works the same way
void triggerEncounterPtr(const Entity *e) {
    e->attack();
}

int main() {
    Dragon boss;
    Entity minion;

    triggerEncounter(boss);
    triggerEncounterPtr(&boss);
    triggerEncounter(minion);
    return 0;
}
