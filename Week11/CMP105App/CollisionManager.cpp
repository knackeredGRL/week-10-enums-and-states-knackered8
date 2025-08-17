#include "CollisionManager.h"
#include "Player.h"
#include "Bullet.h"
#include "Enemy.h"
#include "BulletManager.h"
#include "EnemyManager.h"

CollisionManager::CollisionManager()
{
}

void CollisionManager::BulletEnemyCollision(BulletManager* bulletMan, EnemyManager* enemyMan)
{
	std::vector<Bullet*> bulletVector = bulletMan->GetActivePool();
	std::vector<Enemy*> enemyVector = enemyMan->GetActivePool();

	for (int i = 0; i < bulletVector.size(); i++)
	{
		for (int j = 0; j < enemyVector.size(); j++)
		{
			if (bulletVector[i]->getCollisionBox().intersects(enemyVector[j]->getCollisionBox()))
			{
				bulletVector[i]->setAlive(false);
				enemyVector[j]->setAlive(false);
			}
		}
	}

	



}

void CollisionManager::PlayerEnemyCollision(Player* player, Enemy* enemy)
{



}
