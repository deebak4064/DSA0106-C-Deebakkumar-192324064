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

// Line 17: Takes polymorphic parameter by value!
void triggerEncounter(Entity e) {
    e.attack(); // Calls Entity::attack(), not Dragon::attack()
}

int main() {
    Dragon boss;

    // Developer expects "Dragon breathes scorching fire!"
    triggerEncounter(boss);

    return 0;
}
