#include "SceneMenu.h"
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


SceneMenu::SceneMenu()
{
}


SceneMenu::~SceneMenu()
{
}

void SceneMenu::Setup()
{
	Scene::Setup();

	GameObject* bg = Instantiate("bg", 300, 200, 0);
	Sprite* bgSprite = new Sprite("Assets/bg.png");
	SpriteRenderer* bgRenderer = new SpriteRenderer(bgSprite);
	bg->AddComponent(bgRenderer);
	bg->AddComponent(new MenuControls());

	// Could add XML file loading to get an array of frame rectangles
	GameObject* playButton = Instantiate("playButton",300,200,0);
	//Rect* tempRect = new Rect(0,0,256,128);
	Rect* frameRect = new Rect(0,0,256,64);
	Sprite* playButtonSprite = new Sprite("Assets/buttons.png", frameRect);
	SpriteRenderer* playBRenderer = new SpriteRenderer(playButtonSprite);
	playButton->AddComponent(playBRenderer);
	TextRenderer* buttonText = new TextRenderer(Shooter::fontFile,28,"PLAY");
	
	playButton->AddComponent(buttonText);

	//TextSprite* playButtonTextSprite = new TextSprite("PLAY",game);
	//SpriteRenderer* playBTRenderer = new SpriteRenderer(playButtonTextSprite, playButtonTextSprite->GetTexture());
	//playButton->AddComponent(playBTRenderer);
	//playButton->AddComponent(playBRenderer);
	Button* playBut = new Button(SDL_Rect{ 300,200,frameRect->w,frameRect->h });
	playButton->AddComponent(playBut);

	/*
	GameObject* go = Instantiate("Tank", 300, 200, 0);
	go->AddComponent(new SpriteRenderer("Assets/Target.png"));
	go->transform->SetRelativeScale(Vector2(0.1f, 0.1f));

	GameObject* graphic = Instantiate("TankGraphic", 0, 0, 90);
	Sprite* tankSprite = new Sprite("Assets/Tank.png");
	SpriteRenderer* tankRenderer = new SpriteRenderer();
	tankRenderer->SetSprite(tankSprite);
	//tankRenderer->flipY = true;

	graphic->AddComponent(tankRenderer);
	//graphic->transform->scale.x = 0.1f;
	//graphic->transform->scale.y = 0.1f;

	graphic->transform->SetParentRelative(go->transform);

	go->AddComponent(new PlayerControls());
	go->AddComponent(new CameraFollow());

	graphic->AddComponent(new Shoot());

	for (int i = 0; i < 10; i++)
	{
		GameObject* enemy = Instantiate(game->Prefab("Enemy"), Camera::x + rand() % Camera::width, Camera::y + rand() % Camera::height, 0);
		enemy->GetComponent<Rigidbody>()->AddForce(500 * Vector2(rand() % 100 - 50, rand() % 100 - 50));
	}
	*/


}

//void SceneMenu::Update()
//{
//}
