#include "Camera.h"



class FpsCamera : public Camera
{
public:
    FpsCamera();

    void Tick(float _dt) ;
    void rotateCamera(float _dTheta, float _dPhi); // yaw, pitch
    void Load(std::ifstream& _file);
    void MoveCamera(vec3 direction);
private:

    float m_yaw;
    float m_pitch;
    float m_aspectRatio;

    glm::vec3 m_front = glm::vec3(0.0f, 0.0f, -1.0f);
    glm::vec3 m_right = glm::vec3(1.0f, 0.0f, 0.0f);
    glm::vec3 m_up = glm::vec3(0.0f, 1.0f, 0.0f);
    glm::vec3 m_worldUp = glm::vec3(0.0f, 1.0f, 0.0f);
};