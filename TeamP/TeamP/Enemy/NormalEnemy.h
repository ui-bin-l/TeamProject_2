#pragma once

class NormalEnemy : public Enemy
{
public:
    NormalEnemy();
    ~NormalEnemy();

    void Fire() override;
};