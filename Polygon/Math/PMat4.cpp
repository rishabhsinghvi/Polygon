#include "PMat4.h"

namespace PolygonEngine
{
	namespace Math
	{
		PMat4::PMat4() noexcept:
			m_Data{1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1}
		{
		}
		PMat4::PMat4(const PMat4& other) noexcept:
			m_Data{ other.m_Data[0], other.m_Data[1], other.m_Data[2], other.m_Data[3],
			other.m_Data[4], other.m_Data[5], other.m_Data[6], other.m_Data[7],
			other.m_Data[8], other.m_Data[9], other.m_Data[10], other.m_Data[11],
			other.m_Data[12], other.m_Data[13], other.m_Data[14], other.m_Data[15] }
		{
		}

		PMat4::PMat4(PMat4&& other) noexcept:
			m_Data(std::move(other.m_Data))
		{
		}

		PMat4::PMat4(PReal r0, PReal r1, PReal r2, PReal r3, PReal r4, PReal r5, PReal r6, PReal r7, PReal r8, PReal r9, PReal r10, PReal r11, PReal r12, PReal r13, PReal r14, PReal r15) noexcept:
			m_Data{ r0, r1, r2, r3, r4, r5, r6, r7, r8, r9, r10, r11, r12, r13, r14, r15}
		{
		}

		PReal& PMat4::At(unsigned int i, unsigned int j)
		{
			return m_Data.at(i * 4 + j);
		}

		PMat4& PMat4::operator=(const PMat4& other)
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
			m_Data[9] = other.m_Data[9];
			m_Data[10] = other.m_Data[10];
			m_Data[11] = other.m_Data[11];

			m_Data[12] = other.m_Data[12];
			m_Data[13] = other.m_Data[13];
			m_Data[14] = other.m_Data[14];
			m_Data[15] = other.m_Data[15];

			return *this;
		}

		bool PMat4::operator==(const PMat4& other) const
		{
			return m_Data == other.m_Data;
		}

		PMat4 PMat4::operator+(const PMat4& other) const
		{
			return PMat4(
				m_Data[0] + other.m_Data[0],
				m_Data[1] + other.m_Data[1],
				m_Data[2] + other.m_Data[2],
				m_Data[3] + other.m_Data[3],

				m_Data[4] + other.m_Data[4],
				m_Data[5] + other.m_Data[5],
				m_Data[6] + other.m_Data[6],
				m_Data[7] + other.m_Data[7],

				m_Data[8] + other.m_Data[8],
				m_Data[9] + other.m_Data[9],
				m_Data[10] + other.m_Data[10],
				m_Data[11] + other.m_Data[11],

				m_Data[12] + other.m_Data[12],
				m_Data[13] + other.m_Data[13],
				m_Data[14] + other.m_Data[14],
				m_Data[15] + other.m_Data[15]
			);
		}

		PMat4 PMat4::operator-(const PMat4& other) const
		{
			return PMat4(m_Data[0] + other.m_Data[0],
				m_Data[1] - other.m_Data[1],
				m_Data[2] - other.m_Data[2],
				m_Data[3] - other.m_Data[3],

				m_Data[4] - other.m_Data[4],
				m_Data[5] - other.m_Data[5],
				m_Data[6] - other.m_Data[6],
				m_Data[7] - other.m_Data[7],

				m_Data[8] - other.m_Data[8],
				m_Data[9] - other.m_Data[9],
				m_Data[10] - other.m_Data[10],
				m_Data[11] - other.m_Data[11],

				m_Data[12] - other.m_Data[12],
				m_Data[13] - other.m_Data[13],
				m_Data[14] - other.m_Data[14],
				m_Data[15] - other.m_Data[15]
			);
		}

		PMat4 PMat4::operator*(const PMat4& other) const
		{
			return PMat4(
				m_Data[0] * other.m_Data[0] + m_Data[4] * other.m_Data[1] + m_Data[8] * other.m_Data[2] + m_Data[12] * other.m_Data[3],
				m_Data[1] * other.m_Data[0] + m_Data[5] * other.m_Data[1] + m_Data[9] * other.m_Data[2] + m_Data[13] * other.m_Data[3],
				m_Data[2] * other.m_Data[0] + m_Data[6] * other.m_Data[1] + m_Data[10] * other.m_Data[2] + m_Data[14] * other.m_Data[3],
				m_Data[3] * other.m_Data[0] + m_Data[7] * other.m_Data[1] + m_Data[11] * other.m_Data[2] + m_Data[15] * other.m_Data[3],

				m_Data[0] * other.m_Data[4] + m_Data[4] * other.m_Data[5] + m_Data[8] * other.m_Data[6] + m_Data[12] * other.m_Data[7],
				m_Data[1] * other.m_Data[4] + m_Data[5] * other.m_Data[5] + m_Data[9] * other.m_Data[6] + m_Data[13] * other.m_Data[7],
				m_Data[2] * other.m_Data[4] + m_Data[6] * other.m_Data[5] + m_Data[10] * other.m_Data[6] + m_Data[14] * other.m_Data[7],
				m_Data[3] * other.m_Data[4] + m_Data[7] * other.m_Data[5] + m_Data[11] * other.m_Data[6] + m_Data[15] * other.m_Data[7],

				m_Data[0] * other.m_Data[8] + m_Data[4] * other.m_Data[9] + m_Data[8] * other.m_Data[10] + m_Data[12] * other.m_Data[11],
				m_Data[1] * other.m_Data[8] + m_Data[5] * other.m_Data[9] + m_Data[9] * other.m_Data[10] + m_Data[13] * other.m_Data[11],
				m_Data[2] * other.m_Data[8] + m_Data[6] * other.m_Data[9] + m_Data[10] * other.m_Data[10] + m_Data[14] * other.m_Data[11],
				m_Data[3] * other.m_Data[8] + m_Data[7] * other.m_Data[9] + m_Data[11] * other.m_Data[10] + m_Data[15] * other.m_Data[11],

				m_Data[0] * other.m_Data[12] + m_Data[4] * other.m_Data[13] + m_Data[8] * other.m_Data[14] + m_Data[12] * other.m_Data[15],
				m_Data[1] * other.m_Data[12] + m_Data[5] * other.m_Data[13] + m_Data[9] * other.m_Data[14] + m_Data[13] * other.m_Data[15],
				m_Data[2] * other.m_Data[12] + m_Data[6] * other.m_Data[13] + m_Data[10] * other.m_Data[14] + m_Data[14] * other.m_Data[15],
				m_Data[3] * other.m_Data[12] + m_Data[7] * other.m_Data[13] + m_Data[11] * other.m_Data[14] + m_Data[15] * other.m_Data[15]
			);
		}


		PMat4& PMat4::operator+=(const PMat4& other)
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
			m_Data[9] += other.m_Data[9];
			m_Data[10] += other.m_Data[10];
			m_Data[11] += other.m_Data[11];
			m_Data[12] += other.m_Data[12];
			m_Data[13] += other.m_Data[13];
			m_Data[14] += other.m_Data[14];
			m_Data[15] += other.m_Data[15];

			return *this;
		}

		PMat4& PMat4::operator-=(const PMat4& other)
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
			m_Data[9] -= other.m_Data[9];
			m_Data[10] -= other.m_Data[10];
			m_Data[11] -= other.m_Data[11];
			m_Data[12] -= other.m_Data[12];
			m_Data[13] -= other.m_Data[13];
			m_Data[14] -= other.m_Data[14];
			m_Data[15] -= other.m_Data[15];

			return *this;
		}

		PMat4& PMat4::operator*=(const PMat4& other)
		{
			// TODO: insert return statement here
			auto r0 = m_Data[0] * other.m_Data[0] + m_Data[4] * other.m_Data[1] + m_Data[8] * other.m_Data[2] + m_Data[12] * other.m_Data[3];
			auto r1 = m_Data[1] * other.m_Data[0] + m_Data[5] * other.m_Data[1] + m_Data[9] * other.m_Data[2] + m_Data[13] * other.m_Data[3];
			auto r2 = m_Data[2] * other.m_Data[0] + m_Data[6] * other.m_Data[1] + m_Data[10] * other.m_Data[2] + m_Data[14] * other.m_Data[3];
			auto r3 = m_Data[3] * other.m_Data[0] + m_Data[7] * other.m_Data[1] + m_Data[11] * other.m_Data[2] + m_Data[15] * other.m_Data[3];

			auto r4 = m_Data[0] * other.m_Data[4] + m_Data[4] * other.m_Data[5] + m_Data[8] * other.m_Data[6] + m_Data[12] * other.m_Data[7];
			auto r5 = m_Data[1] * other.m_Data[4] + m_Data[5] * other.m_Data[5] + m_Data[9] * other.m_Data[6] + m_Data[13] * other.m_Data[7];
			auto r6 = m_Data[2] * other.m_Data[4] + m_Data[6] * other.m_Data[5] + m_Data[10] * other.m_Data[6] + m_Data[14] * other.m_Data[7];
			auto r7 = m_Data[3] * other.m_Data[4] + m_Data[7] * other.m_Data[5] + m_Data[11] * other.m_Data[6] + m_Data[15] * other.m_Data[7];

			auto r8 = m_Data[0] * other.m_Data[8] + m_Data[4] * other.m_Data[9] + m_Data[8] * other.m_Data[10] + m_Data[12] * other.m_Data[11];
			auto r9 = m_Data[1] * other.m_Data[8] + m_Data[5] * other.m_Data[9] + m_Data[9] * other.m_Data[10] + m_Data[13] * other.m_Data[11];
			auto r10 = m_Data[2] * other.m_Data[8] + m_Data[6] * other.m_Data[9] + m_Data[10] * other.m_Data[10] + m_Data[14] * other.m_Data[11];
			auto r11 = m_Data[3] * other.m_Data[8] + m_Data[7] * other.m_Data[9] + m_Data[11] * other.m_Data[10] + m_Data[15] * other.m_Data[11];

			auto r12 = m_Data[0] * other.m_Data[12] + m_Data[4] * other.m_Data[13] + m_Data[8] * other.m_Data[14] + m_Data[12] * other.m_Data[15];
			auto r13 = m_Data[1] * other.m_Data[12] + m_Data[5] * other.m_Data[13] + m_Data[9] * other.m_Data[14] + m_Data[13] * other.m_Data[15];
			auto r14 = m_Data[2] * other.m_Data[12] + m_Data[6] * other.m_Data[13] + m_Data[10] * other.m_Data[14] + m_Data[14] * other.m_Data[15];
			auto r15 = m_Data[3] * other.m_Data[12] + m_Data[7] * other.m_Data[13] + m_Data[11] * other.m_Data[14] + m_Data[15] * other.m_Data[15];

			m_Data[0] = r0;
			m_Data[1] = r1;
			m_Data[2] = r2;
			m_Data[3] = r3;

			m_Data[4] = r4;
			m_Data[5] = r5;
			m_Data[6] = r6;
			m_Data[7] = r7;

			m_Data[8] = r8;
			m_Data[9] = r9;
			m_Data[10] = r10;
			m_Data[11] = r11;

			m_Data[12] = r12;
			m_Data[13] = r13;
			m_Data[14] = r14;
			m_Data[15] = r15;

			return *this;
		}

		PMat4 PMat4::operator*(PReal scalar) const
		{
			return PMat4(
			m_Data[0] * scalar,
			m_Data[1] * scalar,
			m_Data[2] * scalar,
			m_Data[3] * scalar,
			m_Data[4] * scalar,
			m_Data[5] * scalar,
			m_Data[6] * scalar,
			m_Data[7] * scalar,
			m_Data[8] * scalar,
			m_Data[9] * scalar,
			m_Data[10] * scalar,
			m_Data[11] * scalar,
			m_Data[12] * scalar, 
			m_Data[13] * scalar,
			m_Data[14] * scalar,
			m_Data[15] * scalar
			);
		}

		PMat4 PMat4::operator/(PReal scalar) const
		{
			if (scalar == 0.0)
				return *this;

			return PMat4(
				m_Data[0] / scalar,
				m_Data[1] / scalar,
				m_Data[2] / scalar,
				m_Data[3] / scalar,
				m_Data[4] / scalar,
				m_Data[5] / scalar,
				m_Data[6] / scalar,
				m_Data[7] / scalar,
				m_Data[8] / scalar,
				m_Data[9] / scalar,
				m_Data[10] / scalar,
				m_Data[11] / scalar,
				m_Data[12] / scalar,
				m_Data[13] / scalar,
				m_Data[14] / scalar,
				m_Data[15] / scalar
			);
		}

		PMat4& PMat4::operator*=(PReal scalar)
		{
			
			return *this;
		}

		PMat4& PMat4::operator/=(PReal scalar)
		{
			
			return *this;
		}

		const PReal* PMat4::Data() const
		{
			return m_Data.data();
		}

		PReal PMat4::GetDeterminant() const
		{
			return m_Data[0] * (m_Data[5] * (m_Data[10] * m_Data[15] - m_Data[14] * m_Data[11]) - m_Data[9] * (m_Data[6] * m_Data[15] - m_Data[14] * m_Data[7]) + m_Data[13] * (m_Data[6] * m_Data[11] - m_Data[10] * m_Data[7]))
				- m_Data[4] * (m_Data[1] * (m_Data[10] * m_Data[15] - m_Data[14] * m_Data[11]) - m_Data[9] * (m_Data[2] * m_Data[15] - m_Data[14] * m_Data[3]) + m_Data[13] * (m_Data[2] * m_Data[11] - m_Data[10] * m_Data[3]))
				+ m_Data[8] * (m_Data[1] * (m_Data[6] * m_Data[15] - m_Data[14] * m_Data[7]) - m_Data[5] * (m_Data[2] * m_Data[15] - m_Data[14] * m_Data[3]) + m_Data[13] * (m_Data[2] * m_Data[7] - m_Data[6] * m_Data[3]))
				- m_Data[12] * (m_Data[1] * (m_Data[6] * m_Data[11] - m_Data[10] * m_Data[7]) - m_Data[5] * (m_Data[2] * m_Data[11] - m_Data[10] * m_Data[3]) + m_Data[9] * (m_Data[2] * m_Data[7] - m_Data[6] * m_Data[3]));
		}

		PMat4 PMat4::GetTranspose() const
		{
			return PMat4(
				m_Data[0],
				m_Data[4],
				m_Data[8],
				m_Data[12],

				m_Data[1],
				m_Data[5],
				m_Data[9],
				m_Data[13],

				m_Data[2],
				m_Data[6],
				m_Data[10],
				m_Data[14],

				m_Data[3],
				m_Data[7],
				m_Data[11],
				m_Data[15]
			);
		}

		PMat4 PMat4::GetMinor() const
		{
			return PMat4(
				m_Data[5] * (m_Data[10] * m_Data[15] - m_Data[14] * m_Data[11]) - m_Data[9] * (m_Data[6] * m_Data[15] - m_Data[14] * m_Data[7]) + m_Data[13] * (m_Data[6] * m_Data[11] - m_Data[10] * m_Data[7]),
				m_Data[4] * (m_Data[10] * m_Data[15] - m_Data[14] * m_Data[11]) - m_Data[8] * (m_Data[6] * m_Data[15] - m_Data[14] * m_Data[7]) + m_Data[12] * (m_Data[6] * m_Data[11] - m_Data[10] * m_Data[7]),
				m_Data[4] * (m_Data[9] * m_Data[15] - m_Data[13] * m_Data[11]) - m_Data[8] * (m_Data[5] * m_Data[15] - m_Data[13] * m_Data[7]) + m_Data[12] * (m_Data[5] * m_Data[11] - m_Data[9] * m_Data[7]),
				m_Data[4] * (m_Data[9] * m_Data[14] - m_Data[13] * m_Data[10]) - m_Data[8] * (m_Data[5] * m_Data[14] - m_Data[13] * m_Data[6]) + m_Data[12] * (m_Data[5] * m_Data[10] - m_Data[9] * m_Data[6]),

				m_Data[1] * (m_Data[10] * m_Data[15] - m_Data[14] * m_Data[11]) - m_Data[9] * (m_Data[2] * m_Data[15] - m_Data[14] * m_Data[3]) + m_Data[13] * (m_Data[2] * m_Data[11] - m_Data[10] * m_Data[3]),
				m_Data[0] * (m_Data[10] * m_Data[15] - m_Data[14] * m_Data[11]) - m_Data[8] * (m_Data[2] * m_Data[15] - m_Data[14] * m_Data[3]) + m_Data[12] * (m_Data[2] * m_Data[11] - m_Data[10] * m_Data[3]),
				m_Data[0] * (m_Data[9] * m_Data[15] - m_Data[13] * m_Data[11]) - m_Data[8] * (m_Data[1] * m_Data[15] - m_Data[13] * m_Data[3]) + m_Data[12] * (m_Data[1] * m_Data[11] - m_Data[9] * m_Data[3]),
				m_Data[0] * (m_Data[9] * m_Data[14] - m_Data[13] * m_Data[10]) - m_Data[8] * (m_Data[1] * m_Data[14] - m_Data[13] * m_Data[2]) + m_Data[12] * (m_Data[1] * m_Data[10] - m_Data[9] * m_Data[2]),

				m_Data[1] * (m_Data[6] * m_Data[15] - m_Data[14] * m_Data[7]) - m_Data[5] * (m_Data[2] * m_Data[15] - m_Data[14] * m_Data[3]) + m_Data[13] * (m_Data[2] * m_Data[7] - m_Data[6] * m_Data[3]),
				m_Data[0] * (m_Data[6] * m_Data[15] - m_Data[14] * m_Data[7]) - m_Data[4] * (m_Data[2] * m_Data[15] - m_Data[14] * m_Data[3]) + m_Data[12] * (m_Data[2] * m_Data[7] - m_Data[6] * m_Data[3]),
				m_Data[0] * (m_Data[5] * m_Data[15] - m_Data[13] * m_Data[7]) - m_Data[4] * (m_Data[1] * m_Data[15] - m_Data[13] * m_Data[3]) + m_Data[12] * (m_Data[1] * m_Data[7] - m_Data[5] * m_Data[3]),
				m_Data[0] * (m_Data[5] * m_Data[14] - m_Data[13] * m_Data[6]) - m_Data[4] * (m_Data[1] * m_Data[14] - m_Data[13] * m_Data[2]) + m_Data[12] * (m_Data[1] * m_Data[6] - m_Data[5] * m_Data[2]),

				m_Data[1] * (m_Data[6] * m_Data[11] - m_Data[10] * m_Data[7]) - m_Data[5] * (m_Data[2] * m_Data[11] - m_Data[10] * m_Data[3]) + m_Data[9] * (m_Data[2] * m_Data[7] - m_Data[6] * m_Data[3]),
				m_Data[0] * (m_Data[6] * m_Data[11] - m_Data[10] * m_Data[7]) - m_Data[4] * (m_Data[2] * m_Data[11] - m_Data[10] * m_Data[3]) + m_Data[8] * (m_Data[2] * m_Data[7] - m_Data[6] * m_Data[3]),
				m_Data[0] * (m_Data[5] * m_Data[11] - m_Data[9] * m_Data[7]) - m_Data[4] * (m_Data[1] * m_Data[11] - m_Data[9] * m_Data[3]) + m_Data[8] * (m_Data[1] * m_Data[7] - m_Data[5] * m_Data[3]),
				m_Data[0] * (m_Data[5] * m_Data[10] - m_Data[9] * m_Data[6]) - m_Data[4] * (m_Data[1] * m_Data[10] - m_Data[9] * m_Data[2]) + m_Data[8] * (m_Data[1] * m_Data[6] - m_Data[5] * m_Data[2])

			);
		}

		PMat4 PMat4::GetCofactorsMatrix() const
		{
			return PMat4(
				m_Data[5] * (m_Data[10] * m_Data[15] - m_Data[14] * m_Data[11]) - m_Data[9] * (m_Data[6] * m_Data[15] - m_Data[14] * m_Data[7]) + m_Data[13] * (m_Data[6] * m_Data[11] - m_Data[10] * m_Data[7]),
				static_cast<PReal>(-1.0)* (m_Data[4] * (m_Data[10] * m_Data[15] - m_Data[14] * m_Data[11]) - m_Data[8] * (m_Data[6] * m_Data[15] - m_Data[14] * m_Data[7]) + m_Data[12] * (m_Data[6] * m_Data[11] - m_Data[10] * m_Data[7])),
				m_Data[4] * (m_Data[9] * m_Data[15] - m_Data[13] * m_Data[11]) - m_Data[8] * (m_Data[5] * m_Data[15] - m_Data[13] * m_Data[7]) + m_Data[12] * (m_Data[5] * m_Data[11] - m_Data[9] * m_Data[7]),
				static_cast<PReal>(-1.0)* (m_Data[4] * (m_Data[9] * m_Data[14] - m_Data[13] * m_Data[10]) - m_Data[8] * (m_Data[5] * m_Data[14] - m_Data[13] * m_Data[6]) + m_Data[12] * (m_Data[5] * m_Data[10] - m_Data[9] * m_Data[6])),

				static_cast<PReal>(-1.0) * (m_Data[1] * (m_Data[10] * m_Data[15] - m_Data[14] * m_Data[11]) - m_Data[9] * (m_Data[2] * m_Data[15] - m_Data[14] * m_Data[3]) + m_Data[13] * (m_Data[2] * m_Data[11] - m_Data[10] * m_Data[3])),
				m_Data[0] * (m_Data[10] * m_Data[15] - m_Data[14] * m_Data[11]) - m_Data[8] * (m_Data[2] * m_Data[15] - m_Data[14] * m_Data[3]) + m_Data[12] * (m_Data[2] * m_Data[11] - m_Data[10] * m_Data[3]),
				static_cast<PReal>(-1.0)* (m_Data[0] * (m_Data[9] * m_Data[15] - m_Data[13] * m_Data[11]) - m_Data[8] * (m_Data[1] * m_Data[15] - m_Data[13] * m_Data[3]) + m_Data[12] * (m_Data[1] * m_Data[11] - m_Data[9] * m_Data[3])),
				m_Data[0] * (m_Data[9] * m_Data[14] - m_Data[13] * m_Data[10]) - m_Data[8] * (m_Data[1] * m_Data[14] - m_Data[13] * m_Data[2]) + m_Data[12] * (m_Data[1] * m_Data[10] - m_Data[9] * m_Data[2]),

				m_Data[1] * (m_Data[6] * m_Data[15] - m_Data[14] * m_Data[7]) - m_Data[5] * (m_Data[2] * m_Data[15] - m_Data[14] * m_Data[3]) + m_Data[13] * (m_Data[2] * m_Data[7] - m_Data[6] * m_Data[3]),
				static_cast<PReal>(-1.0)* (m_Data[0] * (m_Data[6] * m_Data[15] - m_Data[14] * m_Data[7]) - m_Data[4] * (m_Data[2] * m_Data[15] - m_Data[14] * m_Data[3]) + m_Data[12] * (m_Data[2] * m_Data[7] - m_Data[6] * m_Data[3])),
				m_Data[0] * (m_Data[5] * m_Data[15] - m_Data[13] * m_Data[7]) - m_Data[4] * (m_Data[1] * m_Data[15] - m_Data[13] * m_Data[3]) + m_Data[12] * (m_Data[1] * m_Data[7] - m_Data[5] * m_Data[3]),
				static_cast<PReal>(-1.0)* (m_Data[0] * (m_Data[5] * m_Data[14] - m_Data[13] * m_Data[6]) - m_Data[4] * (m_Data[1] * m_Data[14] - m_Data[13] * m_Data[2]) + m_Data[12] * (m_Data[1] * m_Data[6] - m_Data[5] * m_Data[2])),

				static_cast<PReal>(-1.0)* (m_Data[1] * (m_Data[6] * m_Data[11] - m_Data[10] * m_Data[7]) - m_Data[5] * (m_Data[2] * m_Data[11] - m_Data[10] * m_Data[3]) + m_Data[9] * (m_Data[2] * m_Data[7] - m_Data[6] * m_Data[3])),
				m_Data[0] * (m_Data[6] * m_Data[11] - m_Data[10] * m_Data[7]) - m_Data[4] * (m_Data[2] * m_Data[11] - m_Data[10] * m_Data[3]) + m_Data[8] * (m_Data[2] * m_Data[7] - m_Data[6] * m_Data[3]),
				static_cast<PReal>(-1.0)* (m_Data[0] * (m_Data[5] * m_Data[11] - m_Data[9] * m_Data[7]) - m_Data[4] * (m_Data[1] * m_Data[11] - m_Data[9] * m_Data[3]) + m_Data[8] * (m_Data[1] * m_Data[7] - m_Data[5] * m_Data[3])),
				m_Data[0] * (m_Data[5] * m_Data[10] - m_Data[9] * m_Data[6]) - m_Data[4] * (m_Data[1] * m_Data[10] - m_Data[9] * m_Data[2]) + m_Data[8] * (m_Data[1] * m_Data[6] - m_Data[5] * m_Data[2])
			);
		}

		PMat4 PMat4::GetInverse() const
		{
			auto det = GetDeterminant();

			if (det == 0.0)
				return *this;

			auto matrixCofactors = GetCofactorsMatrix().GetTranspose();
			return matrixCofactors / det;
		}
	}
}