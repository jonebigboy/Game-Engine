#include "hzpch.h"
#include "Hazel/LayerStack.h"


namespace Hazel {

	LayerStack::LayerStack()
	{
		m_LayersInsert = m_Layers.begin();
	}

	LayerStack::~LayerStack()
	{
		for (Layer* layer : m_Layers) {
			delete layer;
		}

	}

	void LayerStack::PushLayer(Layer* layer)
	{
		m_LayersInsert = m_Layers.emplace(m_LayersInsert, layer);
		
	}

	void LayerStack::PushOverLayer(Layer* overlayer)
	{
		m_Layers.emplace_back(overlayer);
	}

	void LayerStack::PopLayer(Layer* layer)
	{
		auto it = find(m_Layers.begin(), m_Layers.end(), layer);
		if (it != m_Layers.end()) {
			m_Layers.erase(it);
			m_LayersInsert--;
		}
	}

	void LayerStack::PopOverLayer(Layer* overlayer)
	{
		auto it = find(m_Layers.begin(), m_Layers.end(), overlayer);
		if (it != m_Layers.end()) {
			m_Layers.erase(it);
		}

	}

}