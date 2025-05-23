#include "CameraFactory.h"
#include "Camera.h"
#include <assert.h>
#include "ArcballCamera.h"
#include "FpsCamera.h"

using std::string;

Camera* CameraFactory::makeNewCam(string _type)
{
	printf("CAM TYPE: %s \n", _type.c_str());
	if (_type == "CAMERA")
	{
		return new Camera();
	}
	if (_type == "ARCBALL")
	{
		return new ArcballCamera();
	}
	if (_type == "FPS")
	{
		return new FpsCamera();
	}
	else
	{
		printf("UNKNOWN CAMERA TYPE!");
		assert(0);
		return nullptr;
	}
}
