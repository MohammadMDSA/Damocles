#include "pch.h"
#include "GraphicResource.h"

std::unordered_set<GraphicResource*> GraphicResource::resources = std::unordered_set<GraphicResource*>();

GraphicResource::GraphicResource()
{
	GraphicResource::resources.insert(this);
}

GraphicResource::~GraphicResource()
{
	resources.erase(this);
}

void GraphicResource::SetupAllDevice(ID3D11DeviceContext2* context)
{
	for (auto el = resources.begin(); el != resources.end(); el++)
	{
		(*el)->SetupDevice(context);
	}
}

void GraphicResource::DeviceLostAll()
{
	for (auto el = resources.begin(); el != resources.end(); el++)
		(*el)->DeviceLost();
}
