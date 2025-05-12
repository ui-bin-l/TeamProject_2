#pragma once

class EliteEnemy : public Enemy
{
public:
    EliteEnemy() = default;
    ~EliteEnemy() = default;

    void Fire() override;
};