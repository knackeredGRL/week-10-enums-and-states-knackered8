#pragma once
class Player;
class Enemy;
class Bullet;

class CollisionManager
{
public:
	CollisionManager();

	void BulletEnemyCollision(Bullet* bullet, Enemy* enemy);

	void PlayerEnemyCollision(Player* player, Enemy* enemy);


private:



};

