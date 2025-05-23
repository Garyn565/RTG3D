#include "FpsCamera.h"
#include "stringHelp.h"


FpsCamera::FpsCamera()
{
	m_type = "FPS";
	m_pos = glm::vec3(0.0f, 0.0f, 0.0f);
	m_lookAt = glm::vec3(0.0f, 0.0f, -1.0f);
	m_fov = 45.0f;
	m_near = 0.1f;
	m_far = 100.0f;
	m_worldUp = glm::vec3(0.0f, 1.0f, 0.0f);



}

FpsCamera::~FpsCamera()
{

}



void FpsCamera::Tick(float _dt)
{
	Camera::Tick(_dt);
	
}

void FpsCamera::rotateCamera(float _dTheta, float _dPhi)
{
	m_dx += _dTheta;
	m_dy += _dPhi;
}

void FpsCamera::MoveCamera(vec3 direction)
{
	m_pos += m_front * direction; // Move forward/backward
	m_pos += m_right * direction; // Move left/right
}

void FpsCamera::Load(std::ifstream& _file)
{
  
        StringHelp::String(_file, "NAME", m_name);
        StringHelp::Float3(_file, "POS", m_pos.x, m_pos.y, m_pos.z);
        StringHelp::Float3(_file, "LOOKAT", m_lookAt.x, m_lookAt.y, m_lookAt.z);
        StringHelp::Float(_file, "FOV", m_fov);
        StringHelp::Float(_file, "NEAR", m_near);
        StringHelp::Float(_file, "FAR", m_far);
    
}
