#include "SceneUpgrade.h"
#include "PlayerControls.h"
#include "MenuControls.h"
#include "Bullet.h"
#include "GameObject.h"
#include "SteeringAgent.h"
#include "Seek.h"
#include "Flee.h"
#include "Arrive.h"
#include "Align.h"
#include "Pursue.h"
#include "UpdateVectorTarget.h"
#include "MoveInCircle.h"
#include "Time.h"
#include "PathFollowing.h"
#include "Shoot.h"
#include "CameraFollow.h"
#include "SpriteRenderer.h"
//#include "TextSprite.h"
#include "TextRenderer.h"
#include "Renderer.h"
#include "Camera.h"
#include "Game.h"
#include "Rigidbody.h"
#include "Button.h"
#include "Shooter.h"
#include <string>
#include <iostream>

SceneUpgrade::SceneUpgrade()
{
	SDL_ShowCursor(SDL_ENABLE);
}

SceneUpgrade::SceneUpgrade(Game* g)
{
	Shooter* temp = dynamic_cast<Shooter*>(g);
	game = g;
	temp->playerStats = new PlayerStats();
	SDL_ShowCursor(SDL_ENABLE);
}

SceneUpgrade::~SceneUpgrade()
{
}

void SceneUpgrade::Setup()
{
	Scene::Setup();

	GameObject* bg = Instantiate("bg", 760, 420, 0); // 300, 200
	bg->transform->SetAbsoluteScale(Vector2(1.5f, 1.5f));
	Sprite* bgSprite = new Sprite("Assets/UI/UpgradeBG.png"); //Sprite* bgSprite = new Sprite("Assets/LevelMap/airfield.png");	//Sprite* bgSprite = new Sprite("Assets/bg.png");
	SpriteRenderer* bgRenderer = new SpriteRenderer(bgSprite);
	bg->AddComponent(bgRenderer);	//bg->AddComponent(new MenuControls());

	GameObject* tit = Instantiate("title", 800, 75, 0); // 300, 200 //tit->transform->SetAbsoluteScale(Vector2(1.0f, 1.0f));
	Sprite* titSprite = new Sprite("Assets/UI/baseButton.png");	//Sprite* bgSprite = new Sprite("Assets/bg.png");
	SpriteRenderer* titRenderer = new SpriteRenderer(titSprite);
	tit->AddComponent(titRenderer);
	tit->transform->SetAbsoluteScale(Vector2(1.0f, 0.5f));
	TextRenderer* titText = new TextRenderer(Shooter::fontFile, 34, "BLACK MARKET");
	tit->AddComponent(titText);

	GameObject* moneyBG = Instantiate("moneyBG", 150, 75, 0); // 300, 200 //tit->transform->SetAbsoluteScale(Vector2(1.0f, 1.0f));
	Sprite* moneyBGSprite = new Sprite("Assets/UI/baseButton.png");	//Sprite* bgSprite = new Sprite("Assets/bg.png");
	SpriteRenderer* moneyBGRenderer = new SpriteRenderer(moneyBGSprite);
	moneyBG->AddComponent(moneyBGRenderer);
	moneyBG->transform->SetAbsoluteScale(Vector2(0.6f, 0.5f));

	GameObject* moneyImg = Instantiate("moneyImg", 75, 75, 0); // 300, 200 //tit->transform->SetAbsoluteScale(Vector2(1.0f, 1.0f));
	Sprite* moneyImgSprite = new Sprite("Assets/UI/coin.png");	//Sprite* bgSprite = new Sprite("Assets/bg.png");
	SpriteRenderer* moneyImgRenderer = new SpriteRenderer(moneyImgSprite);
	moneyImg->AddComponent(moneyImgRenderer);

	GameObject* moneyAmount = Instantiate("moneyAmount", 175, 75, 0); 
	int money = dynamic_cast<Shooter*>(game)->playerStats->GetMoney();
	TextRenderer* moneyAmtText = new TextRenderer(Shooter::fontFile, 34, std::to_string(money));
	moneyAmount->AddComponent(moneyAmtText);

	GameObject* healthBG = Instantiate("healthBG", 425, 75, 0); // 300, 200 //tit->transform->SetAbsoluteScale(Vector2(1.0f, 1.0f));
	Sprite* healthBGSprite = new Sprite("Assets/UI/baseButton.png");	//Sprite* bgSprite = new Sprite("Assets/bg.png");
	SpriteRenderer* healthBGRenderer = new SpriteRenderer(healthBGSprite);
	healthBG->AddComponent(healthBGRenderer);
	healthBG->transform->SetAbsoluteScale(Vector2(0.6f, 0.5f));






	GameObject* gunsTitle = Instantiate("gunsTitle", 320, 185, 0);
	Rect* frameRect1 = new Rect(0, 0, 230, 110);
	Sprite* gunsTitleSprite = new Sprite("Assets/UI/guns.png", frameRect1);
	SpriteRenderer* gunsTitleRenderer = new SpriteRenderer(gunsTitleSprite);
	gunsTitle->AddComponent(gunsTitleRenderer);

	GameObject* armourTitle = Instantiate("armourTitle", 800, 185, 0);
	Rect* frameRect2 = new Rect(0, 0, 230, 110);
	Sprite* armourTitleSprite = new Sprite("Assets/UI/armour.png", frameRect2);
	SpriteRenderer* armourTitleRenderer = new SpriteRenderer(armourTitleSprite);
	armourTitle->AddComponent(armourTitleRenderer);

	GameObject* itemsTitle = Instantiate("itemsTitle", 1280, 185, 0);
	Rect* frameRect3 = new Rect(0, 0, 230, 110);
	Sprite* itemsTitleSprite = new Sprite("Assets/UI/items.png", frameRect3);
	SpriteRenderer* itemsTitleRenderer = new SpriteRenderer(itemsTitleSprite);
	itemsTitle->AddComponent(itemsTitleRenderer);

	GameObject* buyDamage = Instantiate("buyDamage", 300, 285, 0);
	Rect* frameRect4 = new Rect(0, 0, 256, 64);
	Sprite* buyDamageSprite = new Sprite("Assets/buttons.png", frameRect4);
	SpriteRenderer* buyDamageRenderer = new SpriteRenderer(buyDamageSprite);
	buyDamage->AddComponent(buyDamageRenderer);
	TextRenderer* buttonText1 = new TextRenderer(Shooter::fontFile, 32, "BUY DAMAGE");
	buyDamage->AddComponent(buttonText1);
	Button* buyDamageBut = new Button(SDL_Rect{ 320,285,frameRect4->w,frameRect4->h }, Button::START_GAME);
	buyDamage->AddComponent(buyDamageBut);

}
