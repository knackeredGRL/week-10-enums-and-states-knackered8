#pragma once
class Player;
class Enemy;
class Bullet;
class BulletManager;

class CollisionManager
{
public:
	CollisionManager();

	void BulletEnemyCollision(BulletManager* bulletMan, Enemy* enemy);

	void PlayerEnemyCollision(Player* player, Enemy* enemy);


private:



};

