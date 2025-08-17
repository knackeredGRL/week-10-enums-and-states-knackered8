#pragma once
class Player;
class Enemy;
class Bullet;
class BulletManager;
class EnemyManager;

class CollisionManager
{
public:
	CollisionManager();

	void BulletEnemyCollision(BulletManager* bulletMan, EnemyManager* enemyMan);

	void PlayerEnemyCollision(Player* player, Enemy* enemy);


private:



};

