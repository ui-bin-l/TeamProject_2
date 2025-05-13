#pragma once

class EliteEnemy : public Enemy
{
public:
    EliteEnemy();
    ~EliteEnemy();

    void Fire() override;
};