#include "Haxxor/Renderer/Camera.h"
#include <glm/gtc/matrix_transform.hpp>

namespace Haxxor
{
    Camera::Camera(glm::mat4 projection)
        : m_ProjectionMatrix(projection), m_ViewMatrix(1.0f), m_Position(0.0f)
    {
        m_ViewProjectionMatrix = m_ProjectionMatrix * m_ViewMatrix;
    }

    void Camera::RecalculateViewMatrix()
    {
        glm::mat4 transform = glm::translate(glm::mat4(1.0f), m_Position) * 
        glm::rotate(glm::mat4(1.0f), glm::radians(m_Rotation), glm::vec3(0, 0, 1));
        m_ViewMatrix = glm::inverse(transform);
        m_ViewProjectionMatrix = m_ProjectionMatrix * m_ViewMatrix;
    }

    Ref<Camera> Camera::Ortho(float left, float right, float bottom, float top)
    {
        glm::mat4 proj = glm::ortho(left, right, bottom, top, -1.0f, 1.0f);
        return MakeRef<Camera>(proj);
    }
}