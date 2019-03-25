#include "AimAndShoot.h"


AimAndShoot::AimAndShoot()
{
}


AimAndShoot::~AimAndShoot()
{
}

void AimAndShoot::OnStart()
{
	enemy = static_cast<EnemyBlackboard*>(blackboard)->enemy;
	enemy->gameObject->GetComponent<SteeringAgent>()->enabled = false;
}

BTNode::BTState AimAndShoot::Update()
{
	if (enemy == nullptr)
	{
		enemy = static_cast<EnemyBlackboard*>(blackboard)->enemy;
	}
	enemy->gameObject->GetComponent<SteeringAgent>()->enabled = false;

	enemy->gameObject->rigidbody->SetVelocity(Vector2(0, 0));
	if (enemy->detectedPlayer != nullptr)
	{
		Vector2 toVec = enemy->detectedPlayer->transform->GetAbsolutePosition()
			- enemy->gameObject->transform->GetAbsolutePosition();
		enemy->gameObject->transform->SetAbsoluteAngle(atan2(toVec.y, toVec.x) * 180.0f / M_PI + 90.0f);
	}
	return BTState::Running;
}
