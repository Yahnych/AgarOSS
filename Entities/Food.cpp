#include "Food.hpp"
#include "../Game/Map.hpp"
#include "../Game/Game.hpp" // configs

Food::Food(const Vector2 &pos, double radius, const Color &color) noexcept :
    Entity(pos, radius, color) {
    type = CellType::FOOD;

    flag = food;
    canEat = cfg::food_canEat;
    avoidSpawningOn = cfg::food_avoidSpawningOn;

    isSpiked = cfg::food_isSpiked;
    isAgitated = cfg::food_isAgitated;
}

void Food::update(unsigned long long tick) noexcept {
    if (!cfg::food_canGrow || _radius >= cfg::food_maxRadius) 
        return;

    // 1 out of 10 chance to grow every minute
    if ((tick % 1500) == 0 && rand(0, 10) == 10)
        setMass(_mass + 1); // setMass might be faster in this case
}
void Food::onDespawned() const noexcept {
    // Vanilla servers spawn new food as soon as one is eaten, so lets do that
    if (map::entities[CellType::FOOD].size() < cfg::food_maxAmount)
        map::spawn<Food>(randomPosition(), cfg::food_baseRadius, randomColor());
}
Food::~Food() {
}