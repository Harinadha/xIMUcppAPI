
/*
   Created by Harinadha Reddy Chintalapalli ( http://www.harinadha.wordpress.com ) 
   License: LGPL 3.0 ( http://www.gnu.org/licenses/lgpl-3.0.txt )
 
   Date   : October 13th 2011
   Version: 1.0
   Date : August 3rd 2013
   Version: 1.1
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
