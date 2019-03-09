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

Scene1::Scene1()
{
}


Scene1::~Scene1()
{
	SDL_ShowCursor(SDL_ENABLE);
}

void Scene1::Setup()
{
	Scene::Setup();


	GameObject* bg = Instantiate("bg", 300, 200, 0);
	Sprite* bgSprite = new Sprite("Assets/background.png");
	SpriteRenderer* bgRenderer = new SpriteRenderer(bgSprite);
	bg->AddComponent(bgRenderer);

	GameObject* bg1 = Instantiate("bg", 300 - 700, 200, 0);
	SpriteRenderer* bgRenderer1 = new SpriteRenderer(bgSprite);
	bg1->AddComponent(bgRenderer1);

	GameObject* bg2 = Instantiate("bg", 300 + 700, 200, 0);
	SpriteRenderer* bgRenderer2 = new SpriteRenderer(bgSprite);
	bg2->AddComponent(bgRenderer2);

	GameObject* bg3 = Instantiate("bg", 300, 200 + 600, 0);
	SpriteRenderer* bgRenderer3 = new SpriteRenderer(bgSprite);
	bg3->AddComponent(bgRenderer3);

	GameObject* bg4 = Instantiate("bg", 300, 200 - 600, 0);
	SpriteRenderer* bgRenderer4 = new SpriteRenderer(bgSprite);
	bg4->AddComponent(bgRenderer4);

	//GameObject* wall1 = Instantiate("wall1", 200, 200, 90);
	//SpriteRenderer* wall1Renderer = new SpriteRenderer(new Sprite("Assets/stones_wall.png"));
	//wall1->AddComponent(wall1Renderer);
	//wall1->transform->SetRelativeScale(Vector2(0.3f, 0.3f));
	//Rigidbody* rb1 = new Rigidbody();
	//rb1->SetBodyType(Rigidbody::staticBody);
	//wall1->AddComponent(rb1);
	//BoxCollider* col1 = new BoxCollider();
	//wall1->AddComponent(col1);

	//col1->SetDimension(Vector2(300, 60));

	GameObject* wall1 = Instantiate(game->Prefab("Wall"), 200, 200, 90);
	GameObject* wall2 = Instantiate(game->Prefab("Wall"), 500, 400, 0);
	GameObject* wall3 = Instantiate(game->Prefab("Wall"), 0, 0, 0);
	GameObject* wall4 = Instantiate(game->Prefab("Wall"), 700, 200, 45);
	GameObject* wall5 = Instantiate(game->Prefab("Wall"), 400, 100, 10);
	GameObject* wall6 = Instantiate(game->Prefab("Wall"), -50, 550, 45);


	GameObject* go = Instantiate("Tank", 300, 200, 0);
	go->transform->SetRelativeScale(Vector2(0.1f, 0.1f));
	Rigidbody* rb = new Rigidbody();
	//rb->SetBodyType(Rigidbody::dynamicBody);
	rb->SetBodyType(Rigidbody::staticBody);
	go->AddComponent(rb);
	BoxCollider* col = new BoxCollider();
	col->SetCategory(game->physics->Layer_1);
	go->AddComponent(col);

	col->SetDimension(Vector2(80, 80));

	GameObject* graphic = Instantiate("TankGraphic", 0, 0, 90);
	Sprite* tankSprite = new Sprite("Assets/Tank.png");
	SpriteRenderer* tankRenderer = new SpriteRenderer();
	tankRenderer->SetSprite(tankSprite);
	//tankRenderer->flipY = true;

	graphic->AddComponent(tankRenderer);
	/*graphic->transform->scale.x = 0.1f;
	graphic->transform->scale.y = 0.1f;*/



	graphic->transform->SetParentRelative(go->transform);


	go->AddComponent(new PlayerControls());
	go->AddComponent(new CameraFollow());
	go->GetComponent<CameraFollow>()->Update();
	go->AddComponent(new SpawnEnemies());

	graphic->AddComponent(new Shoot());
			// Trying to replace cursor with Target sprite
	////SDL_ShowCursor(SDL_DISABLE);
	//GameObject* cursor = Instantiate("Cursor", -500, -250, 0);
	//cursor->AddComponent(Input::GetMousePosition());
	////GameObject* cursor = Instantiate("Cursor", -300, -200, 0);
	//cursor->transform->SetRelativeScale(Vector2(0.1f, 0.1f));
	////GameObject* targetGraph = Instantiate("TargetGraphic", -Camera::width/2, -Camera::height/2, 90);
	//GameObject* targetGraph = Instantiate("TargetGraphic", 0, 0, 90);
	//Sprite* targetSprite = new Sprite("Assets/Target.png");
	////SpriteRenderer* sprRen = new SpriteRenderer("Assets/Target.png", 0, 1);
	//SpriteRenderer* sprRen = new SpriteRenderer();	
	////sprRen->SetLayer(1);
	//sprRen->SetSprite(targetSprite);
	//targetGraph->AddComponent(sprRen);
	//targetGraph->transform->SetParentRelative(cursor->transform);
	//cursor->transform->SetParentRelative(Input::GetMousePosition());

	for (int i = 0; i < 5; i++)
	{
		int x, y, z = rand() % 4;
		if (z == 0) { y = Camera::y - 100; x = Camera::x + rand() % Camera::width; }
		else if (z == 1) { y = Camera::y + rand() % Camera::height; x = Camera::x - 100; }
		else if (z == 2) { y = Camera::y + Camera::height + 100; x = Camera::x + rand() % Camera::width; }
		else if (z == 3) { y = Camera::y + rand() % Camera::height; x = Camera::x + Camera::width + 100; }

		//GameObject* enemy = Instantiate(game->Prefab("Enemy"), Camera::x + rand() % Camera::width, Camera::y + rand() % Camera::height, 0);
		GameObject* enemy = Instantiate(game->Prefab("Enemy"), x, y, 0);
		//enemy->GetComponent<Rigidbody>()->AddForce(50 * Vector2(rand() % 100 - 50 , rand() % 100 - 50));
	}



}

//void Scene1::Update()
//{
//	static int count = 0;
//	count++;
//	if (count = 120) {
//		for (int i = 0; i < 100; i++)
//		{
//			int x, y, z = rand() % 4;
//			if (z == 0) { y = Camera::y - 100; x = Camera::x + rand() % Camera::width; }
//			else if (z == 1) { y = Camera::y + rand() % Camera::height; x = Camera::x - 100; }
//			else if (z == 2) { y = Camera::y + Camera::height + 100; x = Camera::x + rand() % Camera::width; }
//			else if (z == 3) { y = Camera::y + rand() % Camera::height; x = Camera::x + Camera::width + 100; }
//
//			//GameObject* enemy = Instantiate(game->Prefab("Enemy"), Camera::x + rand() % Camera::width, Camera::y + rand() % Camera::height, 0);
//			GameObject* enemy = Instantiate(game->Prefab("Enemy"), x, y, 0);
//			//enemy->GetComponent<Rigidbody>()->AddForce(50 * Vector2(rand() % 100 - 50 , rand() % 100 - 50));
//		}
//	}
//}
