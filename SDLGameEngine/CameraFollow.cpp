<<<<<<< HEAD
 #include "CameraFollow.h"
=======
#include "CameraFollow.h"
>>>>>>> upstream/ExampleProjects
#include "Camera.h"
#include "GameObject.h"
#include "Transform.h"


CameraFollow::CameraFollow()
{
}


CameraFollow::~CameraFollow()
{
}

void CameraFollow::Update()
{
	Camera::x = (gameObject->transform->GetAbsolutePosition().x) - (Camera::width * 0.5f);
	Camera::y = (gameObject->transform->GetAbsolutePosition().y) - (Camera::height * 0.5f);
<<<<<<< HEAD
=======

>>>>>>> upstream/ExampleProjects
}