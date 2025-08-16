#include "CollisionManager.h"
#include "Player.h"
#include "Bullet.h"
#include "Enemy.h"
#include "BulletManager.h"

CollisionManager::CollisionManager()
{
}

void CollisionManager::BulletEnemyCollision(BulletManager* bulletMan, Enemy* enemy)
{
	std::vector<Bullet*> bulletVector = bulletMan->GetActivePool();


	for(int i =0; i < bulletVector.size(); i++)

	if (bulletVector[i]->getCollisionBox().intersects(enemy->getCollisionBox()))
	{
		bulletVector[i]->setAlive(false);
	}



}

void CollisionManager::PlayerEnemyCollision(Player* player, Enemy* enemy)
{



}
