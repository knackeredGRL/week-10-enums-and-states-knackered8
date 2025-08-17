#include "CollisionManager.h"
#include "Player.h"
#include "Bullet.h"
#include "Enemy.h"
#include "BulletManager.h"
#include "EnemyManager.h"

CollisionManager::CollisionManager()
{
	m_audioManager = new AudioManager();
	m_audioManager->addSound("sfx/party-balloon-pop-323588.ogg", "pop");
	m_audioManager->getSound("pop")->setVolume(50);
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
				GameManager::IncreaseScore(1);
				m_audioManager->playSoundbyName("pop");
			}
		}
	}

	



}

void CollisionManager::PlayerEnemyCollision(Player* player, EnemyManager* enemyMan)
{
	std::vector<Enemy*> enemyVector = enemyMan->GetActivePool();

	for (int i = 0; i < enemyVector.size(); i++)
	{
		if (enemyVector[i]->getCollisionBox().intersects(player->getCollisionBox()))
		{
			
			if (!player->GetInvincible())
			{
				enemyVector[i]->setAlive(false);
				GameManager::TakeDamage(1);
				m_audioManager->playSoundbyName("pop");
			}
		}
	}

}
