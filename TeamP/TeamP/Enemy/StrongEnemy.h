#pragma once

class StrongEnemy : public Enemy
{
public:
    StrongEnemy() {}
    ~StrongEnemy() {}

    void Fire() override;
};