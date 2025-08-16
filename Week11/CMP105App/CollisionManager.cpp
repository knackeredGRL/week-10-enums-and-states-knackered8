#include "CollisionManager.h"
#include "Player.h"
#include "Bullet.h"
#include "Enemy.h"

CollisionManager::CollisionManager()
{
}

void CollisionManager::BulletEnemyCollision(Bullet* bullet, Enemy* enemy)
{
	if (bullet->getCollisionBox().intersects(enemy->getCollisionBox()))
	{

	}



}

void CollisionManager::PlayerEnemyCollision(Player* player, Enemy* enemy)
{



}
