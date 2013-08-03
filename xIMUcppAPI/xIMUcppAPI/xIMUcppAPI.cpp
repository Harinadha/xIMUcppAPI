
/*
   Created by Harinadha Reddy Chintalapalli ( http://www.harinadha.wordpress.com ) 
   License: LGPL 3.0 ( http://www.gnu.org/licenses/lgpl-3.0.txt )
 
   Date   : October 13th 2011
   Version: 1.0
   Date : August 3rd 2013
   Version: 1.1
*/
 
#include "xIMUcppAPI.h"
#include "NativeInterface.h"
#using <System.Windows.Forms.dll>	   // for MessageBox
using namespace System::Windows::Forms;// for MessageBox
using namespace x_IMU_API;

namespace xIMUwrapper
{

#ifdef __cplusplus
extern "C"
{
#endif
	//======================== Callbacks or Events ========================================
	GetQuaternionCallback QuatCallback;
	GetRawInertialMagCallback RawInertialMagCallback;
	GetCalibInertialMagCallback CalibInertialMagCallback;

	__declspec(dllexport) void GetQuatFromCSharp(GetQuaternionCallback cb)
	{
		QuatCallback = cb;
//		xIMUserial^ ximuSerialobj = xIMU::xIMU_Instance->xIMUobject;
//		ximuSerialobj->Sendwhencalled();
	}
	__declspec(dllexport) void GetRawInertialMagFromCSharp(GetRawInertialMagCallback cb)
	{
		RawInertialMagCallback = cb;
	}
	__declspec(dllexport) void GetCalibInertialMagFromCSharp(GetCalibInertialMagCallback cb)
	{
		CalibInertialMagCallback =cb;
	}
	//-------------------------------------------------------------------------------------
	void xIMU::QuatDataReceived(Object^ sender, QuaternionData^ e)
	{
		float Quaternion[4];
//		array<float>^ angles = e->ConvertToEulerAngles();
		array<float>^ Quat = e->Quaternion;
		Quaternion[0] = Quat[0]; Quaternion[1] = Quat[1]; Quaternion[2] = Quat[2];
		Quaternion[3] = Quat[3]; 
		QuatCallback(Quaternion);
	}
	void xIMU::RawInerialAndMagneticDataReceived(Object^ sender, RawInertialAndMagneticData^ e)
	{
		signed short int Gyro[3],Accel[3],Mag[3];
		Gyro[0] = e->Gyroscope[0]; Gyro[1] = e->Gyroscope[1]; Gyro[2] = e->Gyroscope[2];
		Gyro[0] = e->Accelerometer[0]; Gyro[1] = e->Accelerometer[1]; Gyro[2] = e->Accelerometer[2];
		Gyro[0] = e->Magnetometer[0]; Gyro[1] = e->Magnetometer[1]; Gyro[2] = e->Magnetometer[2];	
		RawInertialMagCallback(Gyro,Accel,Mag);
	}
	void xIMU::CalibInerialAndMagneticDataReceived(Object^ sender, CalInertialAndMagneticData^ e)
	{
		float Gyro[3],Accel[3],Mag[3];
		Gyro[0] = e->Gyroscope[0]; Gyro[1] = e->Gyroscope[1]; Gyro[2] = e->Gyroscope[2];
		Accel[0] = e->Accelerometer[0]; Accel[1] = e->Accelerometer[1]; Accel[2] = e->Accelerometer[2];
		Mag[0] = e->Magnetometer[0]; Mag[1] = e->Magnetometer[1]; Mag[2] = e->Magnetometer[2];	
		CalibInertialMagCallback(Gyro,Accel,Mag);
	}
	//============================  Methods   ==========================================
	__declspec(dllexport) void OpenxIMU(char PortName[])
	{
		xIMU::xIMU_Instance->xIMUobject->PortName = gcnew String(PortName);
		try
		{
			xIMU::xIMU_Instance->xIMUobject->Open();
		}	
		catch (Exception^ ex)
        {
			MessageBox::Show(ex->Message,"Please connect xIMU",MessageBoxButtons::OK,MessageBoxIcon::Error);
        }
	}

	__declspec(dllexport) void ClosexIMU(char PortName[])
	{
		if (gcnew String(PortName) == xIMU::xIMU_Instance->xIMUobject->PortName)
			xIMU::xIMU_Instance->xIMUobject->Close();
	}

	__declspec(dllexport) void Algorithm_InitializeTare_Command()
	{
		x_IMU_API::CommandCodes Command;
		Command = x_IMU_API::CommandCodes::AlgorithmInitialiseThenTare;
		try
		{
			xIMU::xIMU_Instance->xIMUobject->SendCommandPacket(Command);
		}	
		catch (Exception^ ex)
        {
			MessageBox::Show(ex->Message,"Error",MessageBoxButtons::OK,MessageBoxIcon::Error);
        }
	}

#ifdef __cplusplus
}
#endif


}
