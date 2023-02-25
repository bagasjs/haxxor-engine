#pragma once

#include "Haxxor/Core/Common.h"
#include "Haxxor/Events/Event.h"
#include "Haxxor/Renderer/Renderer.h"

namespace Haxxor
{
    class Layer
    {
    public:
        virtual ~Layer() = default;
        virtual void OnAttach() {}
        virtual void OnDetach() {}
        virtual void OnUpdate() {}
        virtual void OnEvent(Event& event) {}
    };

    class LayerStack
    {
	public:
		LayerStack() = default;
		~LayerStack()
        {
            for(Layer* layer : m_Layers)
            {
                layer->OnDetach();
                delete layer;
            }
        }

		void PushLayer(Layer* layer)
        {
            m_Layers.emplace(m_Layers.begin() + m_LayerInsertIndex, layer);
            m_LayerInsertIndex++;
        }

		void PushOverlay(Layer* overlay)
        {
    		m_Layers.emplace_back(overlay);            
        }

		void PopLayer(Layer* layer)
        {
            auto it = std::find(m_Layers.begin(), m_Layers.begin() + m_LayerInsertIndex, layer);
            if (it != m_Layers.begin() + m_LayerInsertIndex)
            {
                layer->OnDetach();
                m_Layers.erase(it);
                m_LayerInsertIndex--;
            }            
        }

		void PopOverlay(Layer* overlay)
        {
            auto it = std::find(m_Layers.begin() + m_LayerInsertIndex, m_Layers.end(), overlay);
            if (it != m_Layers.end())
            {
                overlay->OnDetach();
                m_Layers.erase(it);
            }            
        }

		std::vector<Layer*>::iterator begin() { return m_Layers.begin(); }
		std::vector<Layer*>::iterator end() { return m_Layers.end(); }
		std::vector<Layer*>::reverse_iterator rbegin() { return m_Layers.rbegin(); }
		std::vector<Layer*>::reverse_iterator rend() { return m_Layers.rend(); }

		std::vector<Layer*>::const_iterator begin() const { return m_Layers.begin(); }
		std::vector<Layer*>::const_iterator end()	const { return m_Layers.end(); }
		std::vector<Layer*>::const_reverse_iterator rbegin() const { return m_Layers.rbegin(); }
		std::vector<Layer*>::const_reverse_iterator rend() const { return m_Layers.rend(); }

	private:
		std::vector<Layer*> m_Layers;
		unsigned int m_LayerInsertIndex = 0;        
    };
}