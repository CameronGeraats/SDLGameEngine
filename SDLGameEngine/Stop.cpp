#include "Stop.h"
#include "SteeringAgent.h"
#include "Game.h"


Stop::Stop()
{
}

Stop::Stop(GameObject * go) : SteeringBehaviour(go)
{
}


Stop::~Stop()
{
}

void Stop::Update()
{
	/*Vector2 direction = target->GetAbsolutePosition() - gameObject->transform->GetAbsolutePosition();
	float distance = direction.Length();

	// Check if we are there
	if (distance < targetRadius)
	{
		return;
	}

	float targetSpeed = 0;
	// If we are outside the slowRadius, go to maxSpeed
	if (distance > slowRadius)
	{
		targetSpeed = agent->maxSpeed;
	}
	// Otherwise calculate scaled speed
	else
	{
		targetSpeed = agent->maxSpeed * distance / slowRadius;
	}

	// The target velocity combines speed and direction
	Vector2 targetVelocity = direction;
	targetVelocity.Normalize();
	targetVelocity *= targetSpeed;

	// Accelaration tries to get to this target velocity
	steering.linear = targetVelocity - agent->rb->GetVelocity();
	steering.linear /= timeToTarget;

	// Check if accelaration is too fast
	if (steering.linear.Length() > maxAccelaraction)
	{
		steering.linear.Normalize();
		steering.linear *= maxAccelaraction;
	}*/

	agent->velocity = 0;
	//if (agent->velocity.Length() > 0)
		//steering.linear = -agent->velocity;
	//else
	steering.linear = 0;
	// Output steering
	steering.angular = 0;
	SteeringBehaviour::Update();

}
