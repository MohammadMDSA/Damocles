#pragma once
#include "pch.h"
#include "StepTimer.h"

interface IActor
{
	virtual void Setup() = 0;
	virtual void Update(DX::StepTimer const& timer) = 0;
};

