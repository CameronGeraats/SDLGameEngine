#include <time.h>
#include <stdlib.h>
#include "Shooter.h"
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
#include "Scene1.h"
#include "SceneMenu.h"
#include "PlayerControls.h"
#include "Rigidbody.h"
#include "BoxCollider.h"
#include "Enemy.h"
#include "ObstacleAvoidance.h"
#include "BehaviourTree.h"
#include "EnemyBlackboard.h"
#include "CanSeePlayer.h"
#include "AimAndShoot.h"
#include "Patrol.h"
#include "ShouldInvestigate.h"
#include "Investigate.h"

TTF_Font* Shooter::textFont = TTF_OpenFont("Assets/AdobeGothicStd-Bold", 28);
std::string Shooter::fontFile = "Assets/arial.ttf";
SDL_Color Shooter::textColour = { 255, 0, 0 };

Shooter::Shooter()
{
}


Shooter::~Shooter()
{
}

void Shooter::Awake()
{
	Camera::x = 0;
	Camera::y = 0;
	Camera::width = 1280;
	Camera::height = 720;
	Time::timeScale = 1;
}

void Shooter::BulletPrefab(GameObject* go)
{
	go->name = "bullet";
	go->AddComponent(new SpriteRenderer("Assets/beams.png", new Rect(15, 300, 50, 90)));
	go->AddComponent(new Bullet());
	//go->transform->SetRelativeScale(Vector2(0.1f, 0.1f));
	Rigidbody* rb = new Rigidbody();
	rb->SetBodyType(Rigidbody::dynamicBody);
	go->AddComponent(rb);
	rb->SetBullet(true);

	BoxCollider* col = new BoxCollider();
	go->AddComponent(col);
	col->SetDimension(Vector2(10, 10));
	col->SetTrigger(true);
	//col->SetCategory(physics->Layer_1);
	//col->SetCollisionMask(~physics->Layer_1);
}

void Shooter::EnemyBulletPrefab(GameObject* go)
{
	go->name = "bullet";
	go->AddComponent(new SpriteRenderer("Assets/beams.png", new Rect(15, 300, 50, 90)));
	go->AddComponent(new Bullet());
	//go->transform->SetRelativeScale(Vector2(0.1f, 0.1f));
	Rigidbody* rb = new Rigidbody();
	rb->SetBodyType(Rigidbody::dynamicBody);
	go->AddComponent(rb);
	rb->SetBullet(true);

	/*BoxCollider* col = new BoxCollider();
	go->AddComponent(col);
	col->SetDimension(Vector2(10, 10));
	col->SetTrigger(true);
	//col->SetCategory(physics->Layer_1);
	//col->SetCollisionMask(~physics->Layer_1);*/
}

void Shooter::LaserPrefab(GameObject* go)
{
	go->name = "laser";
	//SpriteRenderer* sprRen = new SpriteRenderer("Assets/beams.png", new Rect(245, 90, 40, 80));
	SpriteRenderer* sprRen = new SpriteRenderer("Assets/beams.png", new Rect(210, 320, 45, 95));
	//sprRen->flipY = true;
	//sprRen->SetLayer(0);
	go->AddComponent(sprRen);
	Bullet* b = new Bullet();
	b->speed *= 0;
	go->AddComponent(b);
	go->transform->SetRelativeScale(Vector2(1.0f, 9.0f));
	Rigidbody* rb = new Rigidbody();
	rb->SetBodyType(Rigidbody::dynamicBody);
	go->AddComponent(rb);
	rb->SetBullet(true);

	BoxCollider* col = new BoxCollider();
	go->AddComponent(col);

	col->SetDimension(Vector2(20, 1350));
	col->SetTrigger(true);
}

void Shooter::WallPrefab(GameObject* go)
{
	SpriteRenderer* wallRenderer = new SpriteRenderer(new Sprite("Assets/stones_wall.png"));
	go->AddComponent(wallRenderer);
	go->transform->SetRelativeScale(Vector2(0.3f, 0.3f));
	Rigidbody* rb = new Rigidbody();
	rb->SetBodyType(Rigidbody::staticBody);
	go->AddComponent(rb);
	//BoxCollider* col = new BoxCollider();
	//go->AddComponent(col);
	//col->SetCategory(physics->Layer_2);
	//col->SetDimension(Vector2(300, 60));
}

void Shooter::EnemyPrefab(GameObject* go)
{
	go->name = "enemy";
	GameObject* graphic = Instantiate("enemy_graphic", 0, 0, 90);
	graphic->AddComponent(new SpriteRenderer("Assets/tanks_3.png", new Rect(350, 250, 225, 150)));
	graphic->transform->SetParentRelative(go->transform);
	graphic->transform->SetAbsoluteScale(Vector2(0.3f, 0.3f));

	//GameObject* tgt = Instantiate("Target", Camera::x + rand() % Camera::width, Camera::y + rand() % Camera::height);
	GameObject* tgt = Instantiate("Target", Camera::x + Camera::width/2, Camera::y + Camera::height/2);
	//go->transform->SetRelativeScale(Vector2(0.1f, 0.1f));

	Arrive* arrive = new Arrive(go);
	arrive->target = tgt->transform;;
	arrive->maxAccelaraction = 1;
	arrive->slowRadius = 30;
	arrive->targetRadius = 10;
	arrive->steering.weight = 0.5f;
	go->AddComponent(arrive);

	ObstacleAvoidance* obstacleAvoidance = new ObstacleAvoidance();
	obstacleAvoidance->avoidLayer = physics->Layer_2;
	obstacleAvoidance->steering.weight = 1;
	obstacleAvoidance->lookAhead = 100; // More aggressive, direct enemies
	obstacleAvoidance->maxAccelaraction = 1;
	go->AddComponent(obstacleAvoidance);

	/*ObstacleAvoidance* obstacleAvoidance2 = new ObstacleAvoidance();
	obstacleAvoidance2->avoidLayer = physics->Layer_3;
	obstacleAvoidance2->steering.weight = 1;
	obstacleAvoidance2->maxAccelaraction = 1;
	go->AddComponent(obstacleAvoidance2);*/

	SteeringAgent* agent = new SteeringAgent(go);
	agent->steerings.push_back(arrive);
	agent->steerings.push_back(obstacleAvoidance);
	//agent->steerings.push_back(obstacleAvoidance2);
	agent->maxSpeed = 120; //200 default
	//agent->velocity.y = -100;
	go->AddComponent(agent);
	arrive->agent = agent;
	obstacleAvoidance->agent = agent;
	//obstacleAvoidance2->agent = agent;

	UpdateVectorTarget* updateTarget = new UpdateVectorTarget(go);
	updateTarget->target = &tgt->transform->GetAbsolutePosition();
	updateTarget->maxTime = 6;
	go->AddComponent(updateTarget);

	updateTarget->targetObject = tgt;

	//go->transform->SetRelativeScale(Vector2(0.2f, 0.2f));
	Rigidbody* rb = new Rigidbody();
	rb->SetBodyType(Rigidbody::dynamicBody);
	go->AddComponent(rb);

	BoxCollider* col = new BoxCollider();
	go->AddComponent(col);

	col->SetDimension(Vector2(50, 50));
	col->SetCategory(physics->Layer_3);
	col->SetCollisionMask(~physics->Layer_3);

	// Trigger
	/*BoxCollider* col2 = new BoxCollider();
	go->AddComponent(col2);

	col2->SetDimension(Vector2(200, 200));
	col2->SetCategory(physics->Layer_3);
	col2->SetCollisionMask(~physics->Layer_3);
	col2->SetTrigger(true);*/

	go->AddComponent(new Enemy());

	EnemyBlackboard* blackBoard = new EnemyBlackboard();
	blackBoard->enemy = go->GetComponent<Enemy>();

	BehaviourTree* tree = new BehaviourTree();
	tree->blackboard = blackBoard;
	go->AddComponent(tree);
	tree->Create()->
		AddChild(new BTSelector())->
			AddChild(new BTSequence())->
				AddChild(new CanSeePlayer())->
				AddChild(new AimAndShoot())->
			End()->
			AddChild(new BTSequence())->
				AddChild(new ShouldInvestigate())->
				AddChild(new Investigate())->
			End()->
			AddChild(new Patrol());
}

void Shooter::Setup()
{
	AddPrefab("EnemyBullet", std::bind(&Shooter::EnemyBulletPrefab, this, std::placeholders::_1));
	AddPrefab("Bullet", std::bind(&Shooter::BulletPrefab, this, std::placeholders::_1));
	AddPrefab("Laser", std::bind(&Shooter::LaserPrefab, this, std::placeholders::_1));
	AddPrefab("Enemy", std::bind(&Shooter::EnemyPrefab, this, std::placeholders::_1));
	AddPrefab("Wall", std::bind(&Shooter::WallPrefab, this, std::placeholders::_1));
	srand(unsigned(time(NULL)));

	//SetScene(new Scene1());
	SetScene(new SceneMenu());
}

void Shooter::Update()
{ // Checks if scene requested a scene swap, and swaps to new scene if so.
	// Doing it inside a scene function would probably be bad as the SetScene will
	// delete the scene that is in scope.

	Game::Update();
	if (switchSceneTo != nullptr)
	{
		std::cout << "Shooter - switching scene" << std::endl;
		SetScene(switchSceneTo);
		switchSceneTo = nullptr;
	}

	//
}
