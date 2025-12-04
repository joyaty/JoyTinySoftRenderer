/**
 * @file Camera.h
 * @author JoyatY
 * @brief 相机类
 * @version 0.1
 * @date 2025-12-04
 *
 * @copyright Copyright (c) 2025
 *
 */

#pragma once

#include "Math/Mat.h"
#include "Math/Vec.h"

namespace Joy
{
    /**
     * @brief 相机类
     *
     */
    class Camera
    {
    public:
        /**
         * @brief 相机类型枚举
         *
         */
        enum class EnumCameraType
        {
            /**
             * @brief 透视相机
             *
             */
            PERSPECTIVE = 0,

            /**
             * @brief 正交相机
             *
             */
            ORTHOGRAPHIC = 1,
        };

    public:
        Camera() = default;
        Camera(EnumCameraType cameraType, const Vec3f& position);

    public:
        /**
         * @brief 设置相机的观察位置
         *
         * @param lookPosition
         */
        void SetLookPosition(const Vec3f& lookPosition)
        {
            m_LookPosition = lookPosition;
            UpdateViewMatrix();
        }

    private:
        /**
         * @brief 更新相机的观察变换矩阵
         *
         */
        void UpdateViewMatrix();

    private:
        /**
         * @brief 相机类型
         *
         */
        EnumCameraType m_CameraType;

        /**
         * @brief 相机位置
         *
         */
        Vec3f m_Position;

        /**
         * @brief 相机的视点
         *
         */
        Vec3f m_LookPosition;

        /**
         * @brief 相机观察变换矩阵
         *
         */
        Mat4x4f m_ViewMatrix;

        /**
         * @brief 相机投影变换矩阵
         *
         */
        Mat4x4f m_ProjectionMatrix;

        /**
         * @brief 近平面
         *
         */
        float m_NearPlane;

        /**
         * @brief 远平面
         *
         */
        float m_FarPlane;

        /**
         * @brief Fov角度(透视相机专属)
         *
         */
        float m_Fov;

        /**
         * @brief 宽高比(正交相机专属)
         *
         */
        float m_Size;
    };
}   // namespace Joy