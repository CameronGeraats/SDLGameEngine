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
	SDL_ShowCursor(SDL_ENABLE);
}
SceneMenu::SceneMenu(Game* g)
{
	game = g;
	SDL_ShowCursor(SDL_ENABLE);
}


SceneMenu::~SceneMenu()
{
}

void SceneMenu::Setup()
{
	Scene::Setup();

	GameObject* bg = Instantiate("bg", 760, 420, 0); // 300, 200
	bg->transform->SetAbsoluteScale(Vector2(1.5f, 1.5f));
	Sprite* bgSprite = new Sprite("Assets/LevelMap/airfield.png");	//Sprite* bgSprite = new Sprite("Assets/bg.png");
	SpriteRenderer* bgRenderer = new SpriteRenderer(bgSprite);
	bg->AddComponent(bgRenderer);
	bg->AddComponent(new MenuControls());

	GameObject* tit = Instantiate("title", 760, 350, 0); // 300, 200
	//tit->transform->SetAbsoluteScale(Vector2(1.0f, 1.0f));
	Sprite* titSprite = new Sprite("Assets/LevelMap/title.png");	//Sprite* bgSprite = new Sprite("Assets/bg.png");
	SpriteRenderer* titRenderer = new SpriteRenderer(titSprite);
	tit->AddComponent(titRenderer);

	// Could add XML file loading to get an array of frame rectangles
	GameObject* playButton = Instantiate("playButton",450,485,0);
	//Rect* tempRect = new Rect(0,0,256,128);
	Rect* frameRect = new Rect(0,0,256,64);
	Sprite* playButtonSprite = new Sprite("Assets/buttons.png", frameRect);
	SpriteRenderer* playBRenderer = new SpriteRenderer(playButtonSprite);
	playButton->AddComponent(playBRenderer);
	TextRenderer* buttonText = new TextRenderer(Shooter::fontFile,28,"START GAME");
	playButton->AddComponent(buttonText);
	Button* playBut = new Button(SDL_Rect{ 450 - frameRect->w/2,485 - frameRect->h/2,frameRect->w,frameRect->h }, Button::START_GAME);
	playButton->AddComponent(playBut);

	// Could add XML file loading to get an array of frame rectangles
	GameObject* instructionsButton = Instantiate("instrButton", 750, 485, 0);
	//Rect* tempRect = new Rect(0,0,256,128);
	Rect* frameRect2 = new Rect(0, 0, 256, 64);
	Sprite* instrButtonSprite = new Sprite("Assets/buttons.png", frameRect2);
	SpriteRenderer* instrBRenderer = new SpriteRenderer(instrButtonSprite);
	instructionsButton->AddComponent(instrBRenderer);
	TextRenderer* buttonText2 = new TextRenderer(Shooter::fontFile, 28, "INSTRUCTIONS");
	instructionsButton->AddComponent(buttonText2);
	Button* instrBut = new Button(SDL_Rect{ 750 - frameRect2->w/2,485- frameRect2->h/2,frameRect2->w,frameRect2->h }, Button::INSTRUCTIONS);
	instructionsButton->AddComponent(instrBut);

	// Could add XML file loading to get an array of frame rectangles
	GameObject* exitButton = Instantiate("exitButton", 1050, 485, 0);
	//Rect* tempRect = new Rect(0,0,256,128);
	Rect* frameRect3 = new Rect(0, 0, 256, 64);
	Sprite* exitButtonSprite = new Sprite("Assets/buttons.png", frameRect3);
	SpriteRenderer* exitBRenderer = new SpriteRenderer(exitButtonSprite);
	exitButton->AddComponent(exitBRenderer);
	TextRenderer* buttonText3 = new TextRenderer(Shooter::fontFile, 28, "EXIT GAME");
	exitButton->AddComponent(buttonText3);
	Button* exitBut = new Button(SDL_Rect{ 1050 - frameRect3->w/2,485- frameRect3->h/2,frameRect3->w,frameRect3->h }, Button::EXIT_GAME);
	exitButton->AddComponent(exitBut);

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

void SceneMenu::Update()
{
}
