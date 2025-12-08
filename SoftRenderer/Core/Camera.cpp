
#include "Core/Camera.h"
#include "Math/Vec.h"

namespace Joy
{
    Camera::Camera(EnumCameraType cameraType, const Vec3f& position, const Vec3f& lookPosition)
        : m_CameraType(cameraType)
        , m_Position(position)
        , m_LookPosition(lookPosition)
        , m_FarPlane(1000.f)
        , m_NearPlane(0.3f)
        , m_UnionParam({cameraType == EnumCameraType::PERSPECTIVE ? 60.f : 5.f})
    {
        UpdateViewMatrix();
        UpdateProjectionMatrix();
    }

    Camera::Camera(EnumCameraType cameraType, const Vec3f& position, const Vec3f& lookPosition, float far, float near, float viewportParam)
        : m_CameraType(cameraType)
        , m_Position(position)
        , m_LookPosition(lookPosition)
        , m_FarPlane(1000.f)
        , m_NearPlane(0.3f)
        , m_UnionParam({viewportParam})
    {
        UpdateViewMatrix();
        UpdateProjectionMatrix();
    }

    void Camera::UpdateViewMatrix()
    {
        // TODO 计算观察矩阵
        Vec3f forward = Normalized(m_LookPosition - m_Position);
    }

    void Camera::UpdateProjectionMatrix()
    {
        // TODO 计算投影矩阵
    }
}   // namespace Joy