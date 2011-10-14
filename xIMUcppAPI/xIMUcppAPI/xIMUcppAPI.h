/*
Copyright (C) 2011 Harinadha Reddy Chintalapalli

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 3 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.
You should have received a copy of the GNU General Public License
along with this program.  If not, see <http://www.gnu.org/licenses/>.

Date   : October 13th 2011
Verision: 1.0

 */
using namespace System;
using namespace x_IMU_API;

namespace xIMUwrapper
{
	public ref class xIMU
	{
		xIMU(void)
		{
			xIMUobject = gcnew xIMUserial();
			xIMUobject->QuaternionDataReceived += gcnew xIMUserial::onQuaternionDataReceived(this, &xIMUwrapper::xIMU::QuatDataReceived);
			xIMUobject->RawInertialAndMagneticDataReceived += gcnew xIMUserial::onRawInertialAndMagneticDataReceived(this, &xIMUwrapper::xIMU::RawInerialAndMagneticDataReceived);
			xIMUobject->CalInertialAndMagneticDataReceived += gcnew xIMUserial::onCalInertialAndMagneticDataReceived(this, &xIMUwrapper::xIMU::CalibInerialAndMagneticDataReceived);


		}
	public:
		xIMUserial^ xIMUobject;
		static xIMU^ xIMU_Instance = gcnew xIMU();
		void QuatDataReceived(Object^ sender, QuaternionData^ e);
		void RawInerialAndMagneticDataReceived(Object^ sender, RawInertialAndMagneticData^ e);
		void CalibInerialAndMagneticDataReceived(Object^ sender, CalInertialAndMagneticData^ e);



	};
}
