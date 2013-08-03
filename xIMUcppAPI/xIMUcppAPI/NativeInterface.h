
/*
   Created by Harinadha Reddy Chintalapalli ( http://www.harinadha.wordpress.com ) 
   License: LGPL 3.0 ( http://www.gnu.org/licenses/lgpl-3.0.txt )
 
   Date   : October 13th 2011
   Version: 1.0
   Date : August 3rd 2013
   Version: 1.1
*/

#ifdef __cplusplus
extern "C"
{
#endif
	// Callbacks
	typedef void (*GetQuaternionCallback) (float* Quaternion);
	typedef void (*GetRawInertialMagCallback) (signed short int* Gyroscope, signed short int* Accelerometer, signed short int* Magnetometer); 
	typedef void (*GetCalibInertialMagCallback) (float* Gyroscope, float* Accelerometer, float* Magnetometer);

	__declspec(dllexport) void GetQuatFromCSharp(GetQuaternionCallback cb);
	__declspec(dllexport) void GetRawInertialMagFromCSharp(GetRawInertialMagCallback cb);
	__declspec(dllexport) void GetCalibInertialMagFromCSharp(GetCalibInertialMagCallback cb);


    // functions
	__declspec(dllexport) void OpenxIMU(char PortName[]);
	__declspec(dllexport) void ClosexIMU(char PortName[]);
	__declspec(dllexport) void Algorithm_InitializeTare_Command();


#ifdef __cplusplus
}
#endif

