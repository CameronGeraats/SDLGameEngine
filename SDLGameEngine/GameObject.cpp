#include "GameObject.h"
#include "Component.h"
#include "Transform.h"
#include "Scene.h"
#include "Rigidbody.h"


GameObject::GameObject()
{
	transform = new Transform(0, 0);
	AddComponent((Component*)transform);
	onAddChild = std::make_shared<EventListener<Transform*>>(std::bind(&GameObject::AddChild, this, std::placeholders::_1));
	transform->OnAddChild.AddListener(onAddChild);
	//OnRemoveRigidbody.AddListener(OnMyRigidbodyRemoved);
}

GameObject::GameObject(const GameObject &gameObject)
{
	transform = new Transform(0, 0);
	AddComponent((Component*)transform);
	onAddChild = std::make_shared<EventListener<Transform*>>(std::bind(&GameObject::AddChild, this, std::placeholders::_1));
	transform->OnAddChild.AddListener(onAddChild);
}

GameObject::GameObject(Game* _game, std::string _name, float x, float y, float angle, float xScale, float yScale)
{
	name = _name;
	transform = new Transform(this, x, y, angle, xScale, yScale);
	AddComponent((Component*)transform);
	game = _game;
	onAddChild = std::make_shared<EventListener<Transform*>>(std::bind(&GameObject::AddChild, this, std::placeholders::_1));
	transform->OnAddChild.AddListener(onAddChild);
}

GameObject::~GameObject()
{
	//if (scene != NULL)
	//{
	//	scene->ReleaseFromScene(this);
	//}
	//for (Component* component : components)
	//{
	//	delete component;
	//	component = NULL;
	//}
	Cleanup();
}

void GameObject::AddComponent(Component* component)
{
	component->gameObject = this;
	component->game = game;
	component->scene = scene;
	components.push_back(component);
	if (awoken)
	{
		component->Awake();
	}
}

void GameObject::Awake()
{
	awoken = true;
	for (Component* component : components)
	{
		component->Awake();
	}
	OnAwake(this);
}

void GameObject::Update()
{
	for (Component* component : components)
	{
		if (component->enabled)
		{
			component->OnUpdate();
		}
	}
}

void GameObject::FixedUpdate()
{
	for (Component* component : components)
	{
		if (component->enabled)
		{
			component->FixedUpdate();
		}
	}
}

void GameObject::Cleanup()
{
	transform->OnAddChild.RemoveListener(onAddChild);

	if (scene != NULL)
	{
		scene->ReleaseFromScene(this);
	}
	for (Component* component : components)
	{
		component->Cleanup();
	}
	for (Component* component : components)
	{
		delete component;
		component = NULL;
	}
}

Rigidbody* GameObject::SearchForNewRigidBody()
{
	Transform* t = transform;
	Rigidbody* rb = nullptr;
	while (t != nullptr)
	{
		rb = t->gameObject->GetComponent<Rigidbody>();
		if (rb != nullptr)
		{
			return rb;
		}
		t = t->parent;
	}
	return nullptr;
}

void GameObject::AddRigidbody(Rigidbody* _rigidbody)
{
	rigidbody = _rigidbody;
	for (Transform* t : transform->children)
	{
		if (t != nullptr && t->gameObject->GetComponent<Rigidbody>() == nullptr)
		{
			t->gameObject->AddRigidbody(_rigidbody);
		}
	}
	OnAddRigidbody(_rigidbody);
}

void GameObject::ResetRigidbody()
{
	AddRigidbody(SearchForNewRigidBody());
}

void GameObject::AddChild(Transform* child)
{
	child->gameObject->ResetRigidbody();
}

