#pragma once

#include <Ziben/Scene/Scene.hpp>
#include <Ziben/Graphics/Shader.hpp>

#include "Torus.hpp"

class DiffuseScene : public Ziben::Scene {
public:
    DiffuseScene();

    void OnUpdate(float dt) override;
    void OnRender() const override;
    void OnImGuiRender() override;

private:
    glm::mat4      m_Model{};
    glm::mat4      m_View{};
    glm::mat4      m_Projection{};
    Torus          m_Torus;
    Ziben::Shader* m_Shader;
    glm::vec4      m_LightPosition;
    glm::vec3      m_Kd;
    glm::vec3      m_Ld;
    glm::vec3      m_Angles;

}; // class DiffuseScene