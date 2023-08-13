#include "Hazel.h"


class ExampleLayer : public Hazel::Layer
{
public:
	ExampleLayer()
		:Layer("Example Layer"){}

	void OnUpdate() override
	{
		HZ_INFO("ExampleLayer::update");
	}
	

	void OnEvent(Hazel::Event& e) override
	{
		HZ_TRACE(e.ToString());
	}

};

class SandBox : public Hazel::Application
{
public:
	SandBox() {
		PushLayer(new ExampleLayer());
	}

	~SandBox() {

	}
};

Hazel::Application* Hazel::CreateApplication()
{
	return new SandBox();
}