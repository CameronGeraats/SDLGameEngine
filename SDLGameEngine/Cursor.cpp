#include "Cursor.h"
#include "GameObject.h"
#include "Transform.h"
#include "Time.h"
#include "Input.h"
#include "Game.h"


Cursor::Cursor()
{
}


Cursor::~Cursor()
{
}

void Cursor::Update()
{
	gameObject->transform->SetAbsolutePosition(Input::GetMousePosition());
}
