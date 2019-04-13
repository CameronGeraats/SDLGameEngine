#include "Scene1.h"
#include "PlayerControls.h"
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
#include "Renderer.h"
#include "Camera.h"
#include "Game.h"
#include "Rigidbody.h"
#include "BoxCollider.h"
#include "Physics.h"
#include "SpawnEnemies.h"
#include "Cursor.h"
#include "Enemy.h"
#include "MenuControls.h"
#include "Shooter.h"
#include "SceneUpgrade.h"

Scene1::Scene1()
{
}

Scene1::Scene1(Game* g)
{
	game = g;
}


Scene1::~Scene1()
{
	SDL_ShowCursor(SDL_ENABLE);
}

void Scene1::Setup()
{
	Scene::Setup();
	game->GetAM()->ClearMusic();
	game->GetAM()->LoadSound("Assets/Audio/bullet.wav");
	game->GetAM()->LoadSound("Assets/Audio/explosion.wav");
	Shooter* temp = dynamic_cast<Shooter*>(game);
	if(!temp->playerStats){
		temp->playerStats = new PlayerStats();
	}	
	/*if(temp->playerStats){
		delete temp->playerStats;
		temp->playerStats = nullptr;
		temp->playerStats = new PlayerStats();
	}
	else
		temp->playerStats = new PlayerStats();*/
	GameObject* bg = Instantiate("bg", Camera::width/2, Camera::height/2, 0);
	Sprite* bgSprite = new Sprite("Assets/LevelMap/plaingrass3.png");//Sprite* bgSprite = new Sprite("Assets/background.png");
	SpriteRenderer* bgRenderer = new SpriteRenderer(bgSprite);
	bg->AddComponent(bgRenderer);
	bg->AddComponent(new MenuControls());

	GameObject* bg1 = Instantiate("bg", Camera::width/2 - 600, Camera::height/2, 0);
	SpriteRenderer* bgRenderer1 = new SpriteRenderer(bgSprite);
	bg1->AddComponent(bgRenderer1);

	GameObject* bg2 = Instantiate("bg", Camera::width/2 + 600, Camera::height/2, 0);
	SpriteRenderer* bgRenderer2 = new SpriteRenderer(bgSprite);
	bg2->AddComponent(bgRenderer2);

	GameObject* bg3 = Instantiate("bg", Camera::width/2, Camera::height/2 + 360, 0);
	SpriteRenderer* bgRenderer3 = new SpriteRenderer(bgSprite);
	bg3->AddComponent(bgRenderer3);

	GameObject* bg4 = Instantiate("bg", Camera::width/2 - 600, Camera::height/2 + 360, 0);
	SpriteRenderer* bgRenderer4 = new SpriteRenderer(bgSprite);
	bg4->AddComponent(bgRenderer4);

	GameObject* bg5 = Instantiate("bg", Camera::width/2 + 600, Camera::height/2 + 360, 0);
	SpriteRenderer* bgRenderer5 = new SpriteRenderer(bgSprite);
	bg5->AddComponent(bgRenderer5);

	GameObject* bg6 = Instantiate("bg", Camera::width/2, Camera::height/2 - 360, 0);
	SpriteRenderer* bgRenderer6 = new SpriteRenderer(bgSprite);
	bg6->AddComponent(bgRenderer6);

	GameObject* bg7 = Instantiate("bg", Camera::width/2 - 600, Camera::height/2 - 360, 0);
	SpriteRenderer* bgRenderer7 = new SpriteRenderer(bgSprite);
	bg7->AddComponent(bgRenderer7);

	GameObject* bg8 = Instantiate("bg", Camera::width/2 + 600, Camera::height/2 - 360, 0);
	SpriteRenderer* bgRenderer8 = new SpriteRenderer(bgSprite);
	bg8->AddComponent(bgRenderer8);

	/*GameObject* wall1 = Instantiate(game->Prefab("Wall"), 200, 200, 90);
	GameObject* wall2 = Instantiate(game->Prefab("Wall"), 500, 400, 0);
	GameObject* wall3 = Instantiate(game->Prefab("Wall"), 0, 0, 0);
	GameObject* wall4 = Instantiate(game->Prefab("Wall"), 700, 200, 45);
	GameObject* wall5 = Instantiate(game->Prefab("Wall"), 400, 100, 10);
	GameObject* wall6 = Instantiate(game->Prefab("Wall"), -50, 550, 45);*/


	GameObject* go = Instantiate("Player", Camera::width/2, Camera::height/2, 0);//	GameObject* go = Instantiate("Player", 300, 200, 0);
	//go->AddComponent(new SpriteRenderer("Assets/Target.png"));
	go->transform->SetRelativeScale(Vector2(0.25f, 0.25f));
	Rigidbody* rb = new Rigidbody();
	rb->SetBodyType(Rigidbody::dynamicBody);
	//rb->SetBodyType(Rigidbody::staticBody);
	go->AddComponent(rb);
	BoxCollider* col = new BoxCollider();
	col->SetCategory(game->physics->Layer_1);
	go->AddComponent(col);

	col->SetDimension(Vector2(80, 80));

	//GameObject* graphic = Instantiate("playerGraphic", 0, 0, 0);
	Sprite* playerSprite;
	if(temp->playerStats->currentWep == PlayerStats::pistol)
		playerSprite = new Sprite("Assets/Player/handgun3.png");	//Sprite* tankSprite = new Sprite("Assets/Tank.png");
	else if (temp->playerStats->currentWep == PlayerStats::rifle)
		playerSprite = new Sprite("Assets/Player/rifle3.png");
	else if (temp->playerStats->currentWep == PlayerStats::shotgun)
		playerSprite = new Sprite("Assets/Player/shotgun3.png");
	else
		playerSprite = new Sprite("Assets/Player/handgun3.png");
	SpriteRenderer* playerRenderer = new SpriteRenderer();
	playerRenderer->SetSprite(playerSprite);

	go->AddComponent(playerRenderer);
	//graphic->AddComponent(playerRenderer);
	//graphic->transform->SetParentRelative(go->transform);

	//BoxCollider* col = new BoxCollider();
	//col->SetCategory(game->physics->Layer_1);
	//graphic->AddComponent(col);
	//col->SetDimension(Vector2(620, 691));

	//go->AddComponent(new PlayerControls());
	/*go->AddComponent(new CameraFollow());
	go->GetComponent<CameraFollow>()->Update();*/
	go->AddComponent(new SpawnEnemies());
	go->AddComponent(new Shoot());
	//graphic->AddComponent(new Shoot());
			
	SDL_ShowCursor(SDL_DISABLE);
// My old cursor stuff
	//GameObject* cursor = Instantiate("Cursor", 0, 0, 0);
	//cursor->AddComponent(new Cursor);
	////GameObject* cursor = Instantiate("Cursor", -300, -200, 0);
	//cursor->transform->SetRelativeScale(Vector2(0.1f, 0.1f));
	////GameObject* targetGraph = Instantiate("TargetGraphic", -Camera::width/2, -Camera::height/2, 90);
	//GameObject* targetGraph = Instantiate("TargetGraphic", -500, -250, 90);
	//Sprite* targetSprite = new Sprite("Assets/Target.png");
	////SpriteRenderer* sprRen = new SpriteRenderer("Assets/Target.png", 0, 1);
	//SpriteRenderer* sprRen = new SpriteRenderer();
	//sprRen->SetLayer(1);
	//sprRen->SetSprite(targetSprite);
	//targetGraph->AddComponent(sprRen);
	//targetGraph->transform->SetParentRelative(cursor->transform);
// Abisheks Cursor
	GameObject* crosshair = Instantiate("Crosshair", 0, 0, 0);
	Sprite* targetSprite = new Sprite("Assets/Target.png");
	SpriteRenderer* targetRenderer = new SpriteRenderer();
	targetRenderer->SetSprite(targetSprite);
	crosshair->AddComponent(targetRenderer);
	crosshair->transform->SetAbsoluteScale(Vector2(0.1f, 0.1f));
	PlayerControls* controls = new PlayerControls(playerRenderer);
	//PlayerControls* controls = new PlayerControls();
	controls->target = crosshair->transform;
	go->AddComponent(controls);

	for (int i = 0; i < 5; i++)
	{
		int x, y, z = rand() % 4;
		if (z == 0) { y = Camera::y - 100; x = Camera::x + rand() % Camera::width; }
		else if (z == 1) { y = Camera::y + rand() % Camera::height; x = Camera::x - 100; }
		else if (z == 2) { y = Camera::y + Camera::height + 100; x = Camera::x + rand() % Camera::width; }
		else if (z == 3) { y = Camera::y + rand() % Camera::height; x = Camera::x + Camera::width + 100; }

		//GameObject* enemy = Instantiate(game->Prefab("Enemy"), Camera::x + rand() % Camera::width, Camera::y + rand() % Camera::height, 0);
		GameObject* enemy = Instantiate(game->Prefab("Enemy1"), x, y, 0);
		enemy->GetComponent<Enemy>()->player = go;//		enemy->GetComponent<Enemy>()->player = graphic;
		//enemy->GetComponent<Rigidbody>()->AddForce(50 * Vector2(rand() % 100 - 50 , rand() % 100 - 50));
	}



}

void Scene1::Update()
{
	time += Time::DeltaTime();
	if (time >= 15)
	{
		dynamic_cast<Shooter*>(game)->switchSceneTo = new SceneUpgrade();
		game->GetAM()->ClearSounds();
		game->GetAM()->ClearMusic();
	}
}
