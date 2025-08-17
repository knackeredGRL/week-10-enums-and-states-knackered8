#pragma once
class Player;
class Enemy;
class Bullet;
class BulletManager;
class EnemyManager;
#include "GameManager.h"
#include "Framework/AudioManager.h"

class CollisionManager
{
public:
	CollisionManager();

	void BulletEnemyCollision(BulletManager* bulletMan, EnemyManager* enemyMan);

	void PlayerEnemyCollision(Player* player, EnemyManager* enemyMan);


private:
	AudioManager* m_audioManager;


};

