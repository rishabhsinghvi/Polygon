#ifndef POLYGON_MAT4_H
#define POLYGON_MAT4_H

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

		class POLYGON_ENGINE_API PMat4
		{

		private:
			static constexpr size_t SIZE = 16;

			//std::array<PReal, SIZE> m_Data;
			PStaticArray<PReal, SIZE> m_Data;

			PMat4(const std::array<PReal, 16>& arr) noexcept;

		public:

			// Default constructor constructs an identity matrix 
			explicit PMat4() noexcept;

			PMat4(const PMat4& other) noexcept;

			explicit PMat4(PMat4&& other) noexcept;


			~PMat4() = default;

			explicit PMat4(PReal r0, PReal r1, PReal r2, PReal r3, PReal r4, PReal r5, PReal r6, PReal r7, PReal r8,
				PReal r9, PReal r10, PReal r11, PReal r12, PReal r13, PReal r14, PReal r15) noexcept;

			PReal& At(unsigned int i, unsigned int j);

			PMat4& operator=(const PMat4& other);

			bool operator==(const PMat4& other) const;

			PMat4 operator+(const PMat4& other) const;
			PMat4 operator-(const PMat4& other) const;
			PMat4 operator*(const PMat4& other) const;

			PMat4& operator+=(const PMat4& other);
			PMat4& operator-=(const PMat4& other);
			PMat4& operator*=(const PMat4& other);

			PMat4 operator*(PReal scalar) const;
			PMat4 operator/(PReal scalar) const;

			PMat4& operator*=(PReal scalar);
			PMat4& operator/=(PReal scalar);

			const PReal* Data() const;

			PReal GetDeterminant() const;
			PMat4 GetTranspose() const;
			PMat4 GetMinor() const;
			PMat4 GetCofactorsMatrix() const;
			PMat4 GetInverse() const;

#ifdef _DEBUG
			friend std::ostream& operator<<(std::ostream& os, const PMat4& mat)
			{
				os << mat.m_Data[0] << " " << mat.m_Data[4] << " " << mat.m_Data[8] << " " << mat.m_Data[12] << '\n';
				os << mat.m_Data[1] << " " << mat.m_Data[5] << " " << mat.m_Data[9] << " " << mat.m_Data[13] << '\n';
				os << mat.m_Data[2] << " " << mat.m_Data[6] << " " << mat.m_Data[10] << " " << mat.m_Data[14] << '\n';
				os << mat.m_Data[3] << " " << mat.m_Data[7] << " " << mat.m_Data[11] << " " << mat.m_Data[15] << '\n';
				return os;
			}
#endif


		};
	}
}

#endif