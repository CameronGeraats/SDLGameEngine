#include "SceneInstruct.h"
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


SceneInstruct::SceneInstruct()
{
	SDL_ShowCursor(SDL_ENABLE);
}

SceneInstruct::SceneInstruct(Game * g)
{
	game = g;
	SDL_ShowCursor(SDL_ENABLE);
}


SceneInstruct::~SceneInstruct()
{
}

void SceneInstruct::Setup()
{
	Scene::Setup();

	GameObject* bg = Instantiate("bg", 760, 420, 0); // 300, 200
	bg->transform->SetAbsoluteScale(Vector2(1.2f, 1.2f));
	Sprite* bgSprite = new Sprite("Assets/UI/Instructions.png");	//Sprite* bgSprite = new Sprite("Assets/bg.png");
	SpriteRenderer* bgRenderer = new SpriteRenderer(bgSprite);
	bg->AddComponent(bgRenderer);

	// Could add XML file loading to get an array of frame rectangles
	GameObject* playButton = Instantiate("playButton", 1300, 735, 0);
	//Rect* tempRect = new Rect(0,0,256,128);
	Rect* frameRect = new Rect(0, 0, 256, 64);
	Sprite* playButtonSprite = new Sprite("Assets/buttons.png", frameRect);
	SpriteRenderer* playBRenderer = new SpriteRenderer(playButtonSprite);
	playButton->AddComponent(playBRenderer);
	TextRenderer* buttonText = new TextRenderer(Shooter::fontFile, 28, "MAIN MENU");
	playButton->AddComponent(buttonText);
	Button* playBut = new Button(SDL_Rect{ 1300 - frameRect->w / 2,735 - frameRect->h / 2,frameRect->w,frameRect->h }, Button::MAIN_MENU);
	playButton->AddComponent(playBut);
}

void SceneInstruct::Update()
{
}
