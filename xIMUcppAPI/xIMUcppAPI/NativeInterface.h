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
//-------------------------------------------------------------------------
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
//--------------------------------------------------------------------------