#ifndef POLYGON_MAT3_H
#define POLYGON_MAT3_H

#include "Core/Core.h"
#include "PMath.h"

#include<array>
#ifdef _DEBUG
#include<iostream>
#endif

namespace Polygon
{
	namespace Math
	{
		/*
		*Matrices are stored in column-major order; to keep it consistent with OpenGL
		*/

		class POLYGON_ENGINE_API PMat3
		{

		private:
			std::array<real_t, 9> m_Data;

		public:

			// Default constructor constructs an identity matrix 
			explicit PMat3() noexcept;

			PMat3(const PMat3& other) noexcept;

			explicit PMat3(PMat3&& other) noexcept;

			~PMat3() = default;

			explicit PMat3(real_t r0, real_t r1, real_t r2, real_t r3, real_t r4, real_t r5, real_t r6, real_t r7, real_t r8) noexcept;

			real_t& At(unsigned int i, unsigned int j);

			PMat3& operator=(const PMat3& other);

			bool operator==(const PMat3& other) const;

			PMat3 operator+(const PMat3& other) const;
			PMat3 operator-(const PMat3& other) const;
			PMat3 operator*(const PMat3& other) const;
			
			PMat3& operator+=(const PMat3& other);
			PMat3& operator-=(const PMat3& other);
			PMat3& operator*=(const PMat3& other);

			PMat3 operator*(real_t scalar) const;
			PMat3 operator/(real_t scalar) const;

			PMat3& operator*=(real_t scalar);
			PMat3& operator/=(real_t scalar);

			real_t GetDeterminant() const;
			PMat3 GetTranspose() const;
			PMat3 GetMinor() const;
			PMat3 GetCofactorsMatrix() const;
			PMat3 GetInverse() const;

#ifdef _DEBUG
			friend std::ostream& operator<<(std::ostream& os, const PMat3& mat)
			{
				os << mat.m_Data[0] << " " << mat.m_Data[3] << " " << mat.m_Data[6] << '\n';
				os << mat.m_Data[1] << " " << mat.m_Data[4] << " " << mat.m_Data[7] << '\n';
				os << mat.m_Data[2] << " " << mat.m_Data[5] << " " << mat.m_Data[8] << '\n';
				return os;
			}
#endif


		};
	}
}

#endif