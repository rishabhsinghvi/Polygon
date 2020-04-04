#ifndef POLYGON_MAT3_H
#define POLYGON_MAT3_H

#include "Core/Core.h"
#include "PMath.h"
#include "Core/PTypes.h"

#include<array>
#ifdef _DEBUG
#include<iostream>
#endif

namespace PolygonEngine
{
	namespace Math
	{
		/*
		*Matrices are stored in column-major order; to keep it consistent with OpenGL
		*/

		class POLYGON_ENGINE_API PMat3
		{

		private:
			static constexpr size_t SIZE = 9;
			PStaticArray<PReal, SIZE> m_Data;
			//std::array<PReal, 9> m_Data;

		public:

			// Default constructor constructs an identity matrix 
			explicit PMat3() noexcept;

			PMat3(const PMat3& other) noexcept;

			explicit PMat3(PMat3&& other) noexcept;

			~PMat3() = default;

			explicit PMat3(PReal r0, PReal r1, PReal r2, PReal r3, PReal r4, PReal r5, PReal r6, PReal r7, PReal r8) noexcept;

			PReal& At(unsigned int i, unsigned int j);

			PMat3& operator=(const PMat3& other);

			bool operator==(const PMat3& other) const;

			PMat3 operator+(const PMat3& other) const;
			PMat3 operator-(const PMat3& other) const;
			PMat3 operator*(const PMat3& other) const;
			
			PMat3& operator+=(const PMat3& other);
			PMat3& operator-=(const PMat3& other);
			PMat3& operator*=(const PMat3& other);

			PMat3 operator*(PReal scalar) const;
			PMat3 operator/(PReal scalar) const;

			PMat3& operator*=(PReal scalar);
			PMat3& operator/=(PReal scalar);

			const PReal* Data() const;

			PReal GetDeterminant() const;
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