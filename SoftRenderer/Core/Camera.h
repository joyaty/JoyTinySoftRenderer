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
        /**
         * @brief 默认构造
         *
         */
        Camera() = default;

        /**
         * @brief 包括相机初始位置和观察位置的构造函数
         *
         * @param cameraType
         * @param position
         * @param lookPosition
         */
        Camera(EnumCameraType cameraType, const Vec3f& position, const Vec3f& lookPosition);

        /**
         * @brief 包含相机观察信息和视锥信息的构造函数
         *
         * @param cameraType
         * @param position
         * @param lookPosition
         * @param near
         * @param far
         * @param viewportParam
         */
        Camera(EnumCameraType cameraType, const Vec3f& position, const Vec3f& lookPosition, float near, float far, float viewportParam);

    public:
        /**
         * @brief 设置相机的放置位置
         *
         * @param position
         */
        void SetPosition(const Vec3f& position)
        {
            m_Position = position;
            UpdateViewMatrix();
        }

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

        /**
         * @brief 获取观察矩阵
         *
         * @return const Mat4x4f&
         */
        const Mat4x4f& GetViewMatrix() const { return m_ViewMatrix; }

        /**
         * @brief 设置近平面
         *
         * @param nearPlane
         */
        void SetNearPlane(float nearPlane)
        {
            m_NearPlane = nearPlane;
            UpdateProjectionMatrix();
        }

        /**
         * @brief 设置远平面
         *
         * @param farPlane
         */
        void SetFarPlane(float farPlane)
        {
            m_FarPlane = farPlane;
            UpdateProjectionMatrix();
        }

        /**
         * @brief 设置透视相机的FOV
         *
         * @param fov
         */
        void SetFov(float fov)
        {
            m_UnionParam.fov = fov;
            UpdateProjectionMatrix();
        }

        /**
         * @brief 设置正交相机的对接尺寸
         *
         * @param size
         */
        void SetSize(float size)
        {
            m_UnionParam.size = size;
            UpdateProjectionMatrix();
        }

        /**
         * @brief 获取投影矩阵
         *
         * @return const Mat4x4f&
         */
        const Mat4x4f& GetProjMatrix() const { return m_ProjectionMatrix; }

    private:
        /**
         * @brief 更新相机的观察变换矩阵
         *
         */
        void UpdateViewMatrix();

        /**
         * @brief 更新相机的投影变换矩阵
         *
         */
        void UpdateProjectionMatrix();

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

        union
        {
            /**
             * @brief Fov角度(透视相机专属)
             *
             */
            float fov;

            /**
             * @brief 宽高比(正交相机专属)
             *
             */
            float size;
        } m_UnionParam;
    };
}   // namespace Joy