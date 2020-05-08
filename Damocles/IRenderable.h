#pragma once
#include "pch.h"

using namespace DirectX::SimpleMath;

interface IRenderable
{
	virtual void Render(Matrix const& parentTransform, Matrix const& view, Matrix const& proj) = 0;
};
