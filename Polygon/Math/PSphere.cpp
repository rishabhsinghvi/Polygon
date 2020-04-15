#include "PSphere.h"

#include "PAABB.h"

#include<utility>
#include<cmath>

namespace PolygonEngine
{
	namespace Math
	{
		PSphere::PSphere(const PVector3& center, PReal radius):
			m_Center(center), m_Radius(radius)
		{
		}

		PSphere::PSphere(PReal radius):
			m_Center(0.0, 0.0, 0.0), m_Radius(radius)
		{
		}

		PSphere::PSphere(PReal cX, PReal cY, PReal cZ, PReal radius):
			m_Center(cX, cY, cZ), m_Radius(radius)
		{
		}

		PSphere::PSphere(const PSphere& other):
			m_Center(other.m_Center), m_Radius(other.m_Radius)
		{
		}

		PSphere::PSphere(PSphere&& other):
			m_Center(std::move(other.m_Center)), m_Radius(other.m_Radius)
		{
		}

		PSphere& PSphere::operator=(const PSphere& other) noexcept
		{
			m_Center = other.m_Center;
			m_Radius = other.m_Radius;

			return *this;
		}

		bool PSphere::Contains(const PVector3& point)
		{
			auto distanceSq = (m_Center.x - point.x) * (m_Center.x - point.x) +
				(m_Center.y - point.y) * (m_Center.y - point.y)
				+ (m_Center.z - point.z) * (m_Center.z - point.z);

			return distanceSq < (m_Radius * m_Radius);
		}

		bool PSphere::Intersects(const PSphere& sphere)
		{
			auto distance = ::sqrt((m_Center.x - sphere.m_Center.x) * (m_Center.x - sphere.m_Center.x) +
				(m_Center.y - sphere.m_Center.y) * (m_Center.y - sphere.m_Center.y)
				+ (m_Center.z - sphere.m_Center.z) * (m_Center.z - sphere.m_Center.z));

			return distance < (m_Radius + sphere.m_Radius);
		}

		bool PSphere::Intersects(const PAABB& aabb)
		{
			return aabb.Intersects(*this);
		}

		














	}
}