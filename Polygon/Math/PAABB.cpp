#include "PAABB.h"
#include "Core/PAssertion.h"

#include "PSphere.h"

#include<algorithm>

namespace PolygonEngine
{
	namespace Math
	{
		PAABB::PAABB(const PVector3& min, const PVector3& max):
			m_Min(min), m_Max(max)
		{
		}

		PAABB::PAABB(const PAABB& other):
			m_Min(other.m_Min), m_Max(other.m_Max)
		{
		}

		PAABB::PAABB(PAABB&& other):
			m_Min(std::move(other.m_Min)), m_Max(std::move(other.m_Max))
		{
		}

		PAABB& PAABB::operator=(const PAABB& other)
		{
			m_Min = other.m_Min;
			m_Max = other.m_Max;

			return *this;
		}

		PVector3 PAABB::Center() const
		{
			return (m_Min + m_Max) * static_cast<PReal>(0.5);
		}

		bool PAABB::Contains(const PVector3& point) const
		{
			return m_Min.x <= point.x && m_Max.x >= point.x && 
				m_Min.y <= point.y && m_Max.y >= point.y
				&& m_Min.z <= point.z && m_Max.z >= point.z;
		}

		bool PAABB::Contains(const PAABB& aabb) const
		{
			return m_Min.x <= aabb.m_Min.x && m_Max.x >= aabb.m_Max.x &&
				m_Min.y <= aabb.m_Min.y && m_Max.y >= aabb.m_Max.y &&
				m_Min.z <= aabb.m_Min.z && m_Max.z >= aabb.m_Max.z;
		}

		bool PAABB::Contains(const PSphere& sphere) const
		{
			return false;
		}

		bool PAABB::Contains(const PLineSegment& line) const
		{
			return false;
		}


		bool PAABB::Contains(const PTriangle& triangle) const
		{
			return false;
		}

		bool PAABB::Intersects(const PAABB& aabb) const
		{
			return (m_Min.x <= aabb.m_Max.x && m_Max.x >= aabb.m_Min.x)
				&& (m_Min.y <= aabb.m_Max.y && m_Max.y >= aabb.m_Min.y)
				&& (m_Min.z <= aabb.m_Max.z && m_Max.z >= aabb.m_Min.z);
		}

		bool PAABB::Intersects(const PSphere& sphere) const
		{
			auto x = std::max(m_Min.x, std::min(sphere.m_Center.x, m_Max.x));
			auto y = std::max(m_Min.y, std::min(sphere.m_Center.y, m_Max.y));
			auto z = std::max(m_Min.z, std::min(sphere.m_Center.z, m_Max.z));

			auto distanceSq = (sphere.m_Center.x - x) * (sphere.m_Center.x - x) +
				(sphere.m_Center.y - y) * (sphere.m_Center.y - y)
				+ (sphere.m_Center.z - z) * (sphere.m_Center.z - z);

			return distanceSq < (sphere.m_Radius * sphere.m_Radius);
		}

		bool PAABB::Intersects(const PLineSegment& line) const
		{
			return false;
		}
		bool PAABB::Intersects(const PPolygon& polygon) const
		{
			return false;
		}
		bool PAABB::Intersects(const PCapsule& capsule) const
		{
			return false;
		}
		bool PAABB::Intersects(const PTriangle& triangle) const
		{
			return false;
		}
	}
}