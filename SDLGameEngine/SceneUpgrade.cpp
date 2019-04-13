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
#include <iomanip>
using namespace std;

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
	moneyAmount->AddComponent(moneyAmtText); updateStats[0] = moneyAmtText; 

	GameObject* healthBG = Instantiate("healthBG", 425, 75, 0); // 300, 200 //tit->transform->SetAbsoluteScale(Vector2(1.0f, 1.0f));
	Sprite* healthBGSprite = new Sprite("Assets/UI/baseButton.png");	//Sprite* bgSprite = new Sprite("Assets/bg.png");
	SpriteRenderer* healthBGRenderer = new SpriteRenderer(healthBGSprite);
	healthBG->AddComponent(healthBGRenderer);
	healthBG->transform->SetAbsoluteScale(Vector2(0.6f, 0.5f));

	GameObject* healthImg = Instantiate("healthImg", 350, 75, 0); // 300, 200 //tit->transform->SetAbsoluteScale(Vector2(1.0f, 1.0f));
	Rect* hpFrameRect = new Rect(0, 0, 64, 64);
	Sprite* healthImgSprite = new Sprite("Assets/UI/heartstrip6.png", hpFrameRect);	//Sprite* bgSprite = new Sprite("Assets/bg.png");
	SpriteRenderer* healthImgRenderer = new SpriteRenderer(healthImgSprite);
	healthImg->AddComponent(healthImgRenderer);
	healthImg->transform->SetAbsoluteScale(Vector2(0.8f, 0.8f));

	GameObject* healthAmount = Instantiate("healthAmount", 450, 75, 0);
	int health = dynamic_cast<Shooter*>(game)->playerStats->GetHealth();
	TextRenderer* healthAmtText = new TextRenderer(Shooter::fontFile, 34, std::to_string(health));
	healthAmount->AddComponent(healthAmtText); updateStats[1] = healthAmtText;

	GameObject* continueB = Instantiate("continueB", 1350, 825, 0); // 300, 200 //tit->transform->SetAbsoluteScale(Vector2(1.0f, 1.0f));
	Sprite* continueBSprite = new Sprite("Assets/UI/baseButton.png");	//Sprite* bgSprite = new Sprite("Assets/bg.png");
	SpriteRenderer* continueBRenderer = new SpriteRenderer(continueBSprite);
	continueB->AddComponent(continueBRenderer);
	continueB->transform->SetAbsoluteScale(Vector2(1.0f, 0.5f));
	TextRenderer* continueBText = new TextRenderer(Shooter::fontFile, 34, "CONTINUE");
	continueB->AddComponent(continueBText);
	Button* continueBut = new Button(SDL_Rect{ 1350 - continueBRenderer->GetWidth()/2,825 - continueBRenderer->GetHeight()/2,
			continueBRenderer->GetWidth(),continueBRenderer->GetHeight()}, Button::CONTINUE);
	moneyImg->AddComponent(continueBut); //continueB->AddComponent(continueBut); 

	/////////////////////////////////

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

	///////////////////////////////

	float a, b, c;
	dynamic_cast<Shooter*>(game)->playerStats->GetUpgradeStats(a, b, c);

	GameObject* buyDamage = Instantiate("buyDamage", 300, 285, 0);
	Rect* frameRect4 = new Rect(0, 0, 256, 64);
	Sprite* buyDamageSprite = new Sprite("Assets/buttons.png", frameRect4);
	SpriteRenderer* buyDamageRenderer = new SpriteRenderer(buyDamageSprite);
	buyDamage->AddComponent(buyDamageRenderer);
	TextRenderer* buttonText1 = new TextRenderer(Shooter::fontFile, 22, "BUY DAMAGE [50]");
	buyDamage->AddComponent(buttonText1);
	Button* buyDamageBut = new Button(SDL_Rect{ 320 - frameRect4->w/2,285 - frameRect4->h/2,frameRect4->w,frameRect4->h }, Button::BUY_DAMAGE);
	buyDamage->AddComponent(buyDamageBut);
	GameObject* currentDmg = Instantiate("currentDamage", 475, 285, 0);
	TextRenderer* upgradeStatText1 = new TextRenderer(Shooter::fontFile, 32, std::to_string(a));
	currentDmg->AddComponent(upgradeStatText1); updateStats[2] = upgradeStatText1;

	GameObject* buySpeed = Instantiate("buySpeed", 300, 360, 0);
	Rect* frameRect5 = new Rect(0, 0, 256, 64);
	Sprite* buySpeedSprite = new Sprite("Assets/buttons.png", frameRect5);
	SpriteRenderer* buySpeedRenderer = new SpriteRenderer(buySpeedSprite);
	buySpeed->AddComponent(buySpeedRenderer);
	TextRenderer* buttonText2 = new TextRenderer(Shooter::fontFile, 22, "BUY SPEED [50]");
	buySpeed->AddComponent(buttonText2);
	Button* buySpeedBut = new Button(SDL_Rect{ 320 - frameRect5->w / 2,360 - frameRect5->h / 2,frameRect5->w,frameRect5->h }, Button::BUY_SPEED);
	buySpeed->AddComponent(buySpeedBut);
	GameObject* currentSpd = Instantiate("currentSpeed", 475, 360, 0);
	TextRenderer* upgradeStatText2 = new TextRenderer(Shooter::fontFile, 32, std::to_string(b));
	currentSpd->AddComponent(upgradeStatText2); updateStats[3] = upgradeStatText2;

	GameObject* buyFire = Instantiate("buyFire", 300, 435, 0);
	Rect* frameRect6 = new Rect(0, 0, 256, 64);
	Sprite* buyFireSprite = new Sprite("Assets/buttons.png", frameRect6);
	SpriteRenderer* buyFireRenderer = new SpriteRenderer(buyFireSprite);
	buyFire->AddComponent(buyFireRenderer);
	TextRenderer* buttonText3 = new TextRenderer(Shooter::fontFile, 22, "BUY FIRESPEED [50]");
	buyFire->AddComponent(buttonText3);
	Button* buyFireBut = new Button(SDL_Rect{ 320 - frameRect6->w / 2,435 - frameRect6->h / 2,frameRect6->w,frameRect6->h }, Button::BUY_FIRESPEED);
	buyFire->AddComponent(buyFireBut);
	GameObject* currentFre = Instantiate("currentFire", 475, 435, 0);
	TextRenderer* upgradeStatText3 = new TextRenderer(Shooter::fontFile, 32, std::to_string(c));
	currentFre->AddComponent(upgradeStatText3); updateStats[4] = upgradeStatText3;

	GameObject* buyHeal = Instantiate("buyHeal", 1260, 285, 0);
	Rect* frameRect7 = new Rect(0, 0, 256, 64);
	Sprite* buyHealSprite = new Sprite("Assets/buttons.png", frameRect7);
	SpriteRenderer* buyHealRenderer = new SpriteRenderer(buyHealSprite);
	buyHeal->AddComponent(buyHealRenderer);
	TextRenderer* buttonText4 = new TextRenderer(Shooter::fontFile, 22, "BUY HEALING [100]");
	buyHeal->AddComponent(buttonText4);
	Button* buyHealBut = new Button(SDL_Rect{ 1260 - frameRect7->w / 2,285 - frameRect7->h / 2,frameRect7->w,frameRect7->h }, Button::HEAL_PLAYER);
	buyHeal->AddComponent(buyHealBut);
}

void SceneUpgrade::Update()
{
	float a, b, c;
	dynamic_cast<Shooter*>(game)->playerStats->GetUpgradeStats(a, b, c);
	
	char health[10]; sprintf_s(health, "%3d", dynamic_cast<Shooter*>(game)->playerStats->GetHealth()); string hpStr = health;
	char money[10]; sprintf_s(money, "%3d", dynamic_cast<Shooter*>(game)->playerStats->GetMoney()); string moneyStr = money;
	char buffer1[10]; sprintf_s(buffer1, "%4.2f", a); string aStr = buffer1;
	char buffer2[10]; sprintf_s(buffer2, "%4.2f", b); string bStr = buffer2;
	char buffer3[10]; sprintf_s(buffer3, "%4.2f", c); string cStr = buffer3;
	
	updateStats[0]->SetText(moneyStr);
	updateStats[1]->SetText(hpStr);
	updateStats[2]->SetText(aStr);
	updateStats[3]->SetText(bStr);
	updateStats[4]->SetText(cStr);
}
