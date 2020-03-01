#include "PMat3.h"

namespace Polygon
{
	namespace Math
	{
		PMat3::PMat3() noexcept
		{
			m_Data[0] = 1;
			m_Data[1] = 0;
			m_Data[2] = 0;
			m_Data[3] = 0;
			m_Data[4] = 1;
			m_Data[5] = 0;
			m_Data[6] = 0;
			m_Data[7] = 0;
			m_Data[8] = 1;
		}


		PMat3::PMat3(const PMat3& other) noexcept
		{
			m_Data[0] = other.m_Data[0];
			m_Data[1] = other.m_Data[1];
			m_Data[2] = other.m_Data[2];
			m_Data[3] = other.m_Data[3];
			m_Data[4] = other.m_Data[4];
			m_Data[5] = other.m_Data[5];
			m_Data[6] = other.m_Data[6];
			m_Data[7] = other.m_Data[7];
			m_Data[8] = other.m_Data[8];
		}

		PMat3::PMat3(PMat3&& other) noexcept:
			m_Data(std::move(other.m_Data))
		{

		}

		PMat3::PMat3(real_t r0, real_t r1, real_t r2, real_t r3, real_t r4, real_t r5, real_t r6, real_t r7, real_t r8) noexcept
		{
			m_Data[0] = r0;
			m_Data[1] = r1;
			m_Data[2] = r2;
			m_Data[3] = r3;
			m_Data[4] = r4;
			m_Data[5] = r5;
			m_Data[6] = r6;
			m_Data[7] = r7;
			m_Data[8] = r8;
		}
		
		real_t& PMat3::At(unsigned int i, unsigned int j)
		{
			// TODO: Assertion!
			return m_Data.at(i * 3 + j);
		}

		PMat3& PMat3::operator=(const PMat3& other)
		{
			m_Data[0] = other.m_Data[0];
			m_Data[1] = other.m_Data[1];
			m_Data[2] = other.m_Data[2];
			m_Data[3] = other.m_Data[3];
			m_Data[4] = other.m_Data[4];
			m_Data[5] = other.m_Data[5];
			m_Data[6] = other.m_Data[6];
			m_Data[7] = other.m_Data[7];
			m_Data[8] = other.m_Data[8];

			return *this;
		}

		bool PMat3::operator==(const PMat3& other) const
		{
			return m_Data == other.m_Data;
		}

		PMat3 PMat3::operator+(const PMat3& other) const
		{
			return PMat3(
				m_Data[0] + other.m_Data[0],
				m_Data[1] + other.m_Data[1],
				m_Data[2] + other.m_Data[2],
				m_Data[3] + other.m_Data[3],
				m_Data[4] + other.m_Data[4],
				m_Data[5] + other.m_Data[5],
				m_Data[6] + other.m_Data[6],
				m_Data[7] + other.m_Data[7],
				m_Data[8] + other.m_Data[8]
			);
		}

		PMat3 PMat3::operator-(const PMat3& other) const
		{
			return PMat3(
				m_Data[0] - other.m_Data[0],
				m_Data[1] - other.m_Data[1],
				m_Data[2] - other.m_Data[2],
				m_Data[3] - other.m_Data[3],
				m_Data[4] - other.m_Data[4],
				m_Data[5] - other.m_Data[5],
				m_Data[6] - other.m_Data[6],
				m_Data[7] - other.m_Data[7],
				m_Data[8] - other.m_Data[8]
			);
		}

		PMat3 PMat3::operator*(const PMat3& other) const
		{
			return PMat3(
				m_Data[0] * other.m_Data[0] +  m_Data[3] * other.m_Data[1] + m_Data[6] * other.m_Data[2],
				m_Data[1] * other.m_Data[0] + m_Data[4] * other.m_Data[1] + m_Data[7] * other.m_Data[2],
				m_Data[2] * other.m_Data[0] + m_Data[5] * other.m_Data[1] + m_Data[8] * other.m_Data[2],


				m_Data[0] * other.m_Data[3] + m_Data[3] * other.m_Data[4] + m_Data[6] * other.m_Data[5],
				m_Data[1] * other.m_Data[3] + m_Data[4] * other.m_Data[4] + m_Data[7] * other.m_Data[5],
				m_Data[2] * other.m_Data[3] + m_Data[5] * other.m_Data[4] + m_Data[8] * other.m_Data[5],

				m_Data[0] * other.m_Data[6] + m_Data[3] * other.m_Data[7] + m_Data[6] * other.m_Data[8],
				m_Data[1] * other.m_Data[6] + m_Data[4] * other.m_Data[7] + m_Data[7] * other.m_Data[8],
				m_Data[2] * other.m_Data[6] + m_Data[5] * other.m_Data[7] + m_Data[8] * other.m_Data[8]
			);
		}

		PMat3& PMat3::operator+=(const PMat3& other)
		{
			m_Data[0] += other.m_Data[0];
			m_Data[1] += other.m_Data[1];
			m_Data[2] += other.m_Data[2];
			m_Data[3] += other.m_Data[3];
			m_Data[4] += other.m_Data[4];
			m_Data[5] += other.m_Data[5];
			m_Data[6] += other.m_Data[6];
			m_Data[7] += other.m_Data[7];
			m_Data[8] += other.m_Data[8];

			return *this;
		}

		PMat3& PMat3::operator-=(const PMat3& other)
		{
			m_Data[0] -= other.m_Data[0];
			m_Data[1] -= other.m_Data[1];
			m_Data[2] -= other.m_Data[2];
			m_Data[3] -= other.m_Data[3];
			m_Data[4] -= other.m_Data[4];
			m_Data[5] -= other.m_Data[5];
			m_Data[6] -= other.m_Data[6];
			m_Data[7] -= other.m_Data[7];
			m_Data[8] -= other.m_Data[8];

			return *this;
		}

		PMat3& PMat3::operator*=(const PMat3& other)
		{
			auto r0 = m_Data[0] * other.m_Data[0] + m_Data[3] * other.m_Data[1] + m_Data[6] * other.m_Data[2];
			auto r1 = m_Data[1] * other.m_Data[0] + m_Data[4] * other.m_Data[1] + m_Data[7] * other.m_Data[2];
			auto r2 = m_Data[2] * other.m_Data[0] + m_Data[5] * other.m_Data[1] + m_Data[8] * other.m_Data[2];


			auto r3 = m_Data[0] * other.m_Data[3] + m_Data[3] * other.m_Data[4] + m_Data[6] * other.m_Data[5];
			auto r4 = m_Data[1] * other.m_Data[3] + m_Data[4] * other.m_Data[4] + m_Data[7] * other.m_Data[5];
			auto r5 = m_Data[2] * other.m_Data[3] + m_Data[5] * other.m_Data[4] + m_Data[8] * other.m_Data[5];

			auto r6 = m_Data[0] * other.m_Data[6] + m_Data[3] * other.m_Data[7] + m_Data[6] * other.m_Data[8];
			auto r7 = m_Data[1] * other.m_Data[6] + m_Data[4] * other.m_Data[7] + m_Data[7] * other.m_Data[8];
			auto r8 = m_Data[2] * other.m_Data[6] + m_Data[5] * other.m_Data[7] + m_Data[8] * other.m_Data[8];

			m_Data[0] = r0;
			m_Data[1] = r1;
			m_Data[2] = r2;
			m_Data[3] = r3;
			m_Data[4] = r4;
			m_Data[5] = r5;
			m_Data[6] = r6;
			m_Data[7] = r7;
			m_Data[8] = r8;

			return *this;
		}

		PMat3 PMat3::operator*(real_t scalar) const
		{
			return PMat3(
				m_Data[0] * scalar,
				m_Data[1] * scalar,
				m_Data[2] * scalar,
				
				m_Data[3] * scalar,
				m_Data[4] * scalar,
				m_Data[5] * scalar,

				m_Data[6] * scalar,
				m_Data[7] * scalar,
				m_Data[8] * scalar

			);
		}

		PMat3 PMat3::operator/(real_t scalar) const
		{
			if (scalar == 0.0)
				return *this;

			return PMat3(
				m_Data[0] / scalar,
				m_Data[1] / scalar,
				m_Data[2] / scalar,

				m_Data[3] / scalar,
				m_Data[4] / scalar,
				m_Data[5] / scalar,

				m_Data[6] / scalar,
				m_Data[7] / scalar,
				m_Data[8] / scalar
			);
		}

		PMat3& PMat3::operator*=(real_t scalar)
		{
			m_Data[0] *= scalar;
			m_Data[1] *= scalar;
			m_Data[2] *= scalar;

			m_Data[3] *= scalar;
			m_Data[4] *= scalar;
			m_Data[5] *= scalar;

			m_Data[6] *= scalar;
			m_Data[7] *= scalar;
			m_Data[8] *= scalar;

			return *this;
		}

		PMat3& PMat3::operator/=(real_t scalar)
		{
			if (scalar == 0.0)
				return *this;

			m_Data[0] /= scalar;
			m_Data[1] /= scalar;
			m_Data[2] /= scalar;

			m_Data[3] /= scalar;
			m_Data[4] /= scalar;
			m_Data[5] /= scalar;

			m_Data[6] /= scalar;
			m_Data[7] /= scalar;
			m_Data[8] /= scalar;

			return *this;
		}

		real_t PMat3::GetDeterminant() const
		{
			return m_Data[0] * (m_Data[4] * m_Data[8] - m_Data[5] * m_Data[7]) - m_Data[3] * (m_Data[8] * m_Data[1] - m_Data[2] * m_Data[7]) + m_Data[6] * (m_Data[5] * m_Data[1] - m_Data[2] * m_Data[4]);
		}

		PMat3 PMat3::GetTranspose() const
		{
			return PMat3(
				m_Data[0],
				m_Data[3],
				m_Data[6],

				m_Data[1],
				m_Data[4],
				m_Data[7],
				
				m_Data[2],
				m_Data[5],
				m_Data[8]
			);
		}

		PMat3 PMat3::GetMinor() const
		{
			return PMat3(
				m_Data[8] * m_Data[4] - m_Data[5] * m_Data[7],
				m_Data[8] * m_Data[3] - m_Data[5] * m_Data[6],
				m_Data[7] * m_Data[3] - m_Data[4] * m_Data[6],

				m_Data[8] * m_Data[1] - m_Data[2] * m_Data[7],
				m_Data[8] * m_Data[0] - m_Data[2] * m_Data[6],
				m_Data[7] * m_Data[0] - m_Data[1] * m_Data[6],

				m_Data[5] * m_Data[1] - m_Data[2] * m_Data[4],
				m_Data[5] * m_Data[0] - m_Data[2] * m_Data[3],
				m_Data[4] * m_Data[0] - m_Data[1] * m_Data[3]
			);
		}

		PMat3 PMat3::GetCofactorsMatrix() const
		{
			return PMat3(
				m_Data[8] * m_Data[4] - m_Data[5] * m_Data[7],
				static_cast<real_t>(-1.0) * (m_Data[8] * m_Data[3] - m_Data[5] * m_Data[6]),
				m_Data[7] * m_Data[3] - m_Data[4] * m_Data[6],

				static_cast<real_t>(-1.0)* (m_Data[8] * m_Data[1] - m_Data[2] * m_Data[7]),
				m_Data[8] * m_Data[0] - m_Data[2] * m_Data[6],
				static_cast<real_t>(-1.0)* (m_Data[7] * m_Data[0] - m_Data[1] * m_Data[6]),

				m_Data[5] * m_Data[1] - m_Data[2] * m_Data[4],
				static_cast<real_t>(-1.0)* (m_Data[5] * m_Data[0] - m_Data[2] * m_Data[3]),
				m_Data[4] * m_Data[0] - m_Data[1] * m_Data[3]
			);
		}

		PMat3 PMat3::GetInverse() const
		{
			auto det = GetDeterminant();
			if (det == 0.0)
				return *this;

			auto matrixCofactors = GetCofactorsMatrix().GetTranspose();

			return matrixCofactors / det;

		}

	}
}