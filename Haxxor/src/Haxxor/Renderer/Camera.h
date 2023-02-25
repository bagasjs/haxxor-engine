#pragma once

#include "Haxxor/Core/Common.h"
#include <glm/glm.hpp>

namespace Haxxor
{
    class Camera
    {
    public:
        Camera(glm::mat4 projection);
        ~Camera() = default;

        const glm::mat4& GetProjectionMatrix() const { return m_ProjectionMatrix; }
        const glm::mat4& GetViewMatrix() const { return m_ViewMatrix; }
        const glm::mat4& GetViewProjectionMatrix() const { return m_ViewProjectionMatrix; }

        float GetRotation(float rotation) const { return m_Rotation; }
        void SetRotation(float rotation) { m_Rotation = rotation; RecalculateViewMatrix(); }
        glm::vec3 GetPosition() const { return m_Position; }
        void SetPosition(glm::vec3 pos) { m_Position = pos; RecalculateViewMatrix(); }

        static Ref<Camera> Ortho(float left, float right, float bottom, float top);

    private:
        void RecalculateViewMatrix();

    private:
        glm::mat4 m_ProjectionMatrix, m_ViewMatrix, m_ViewProjectionMatrix;
        glm::vec3 m_Position;
        float m_Rotation;
    };
}