#pragma once

class GraphicResource
{
public:
	GraphicResource();
	~GraphicResource();

	static void									SetupAllDevice(ID3D11DeviceContext2* context);
	static void									DeviceLostAll();

	bool operator ==(const GraphicResource& other) const
	{
		if (typeid(this) == typeid(other))
			return true;
		return false;
	}

protected:
	virtual void								SetupDevice(ID3D11DeviceContext2* context) = 0;
	virtual void								DeviceLost() = 0;
	ID3D11DeviceContext2*						deviceContex;

private:
	static std::unordered_set<GraphicResource*>		resources;
};

