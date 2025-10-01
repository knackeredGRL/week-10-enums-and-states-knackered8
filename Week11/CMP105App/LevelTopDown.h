#pragma once
#include "Framework/BaseLevel.h"
#include "Framework/Input.h"
#include "Framework/AudioManager.h"
#include "Framework/GameState.h"

class PlayerTopDown;

class NPC;

class TextBox;



class LevelTopDown : public BaseLevel
{
	public:
		LevelTopDown(sf::RenderWindow* hwnd, Input* in, GameState* gs, AudioManager* aud, sf::RenderTexture* renderTexture);
		~LevelTopDown();

		void handleInput(float dt) override;
		void update(float dt) override;
		void render();
		void renderPause();
		void onBegin();
		void onEnd();

	private:
		PlayerTopDown* m_player;
		NPC* m_npc;
		TextBox* m_txtBox;



};

