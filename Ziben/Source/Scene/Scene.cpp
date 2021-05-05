#include "Scene.hpp"

#include "Entity.hpp"
#include "Component.hpp"

#include "Ziben/Renderer/Renderer2D.hpp"

namespace Ziben {

    Scene::Scene(std::string name)
        : m_Name(std::move(name)) {}

    void Scene::OnRender() {
        const Camera*    primaryCamera          = nullptr;
        const glm::mat4* primaryCameraTransform = nullptr;

        {
            auto view = m_Registry.view<TransformComponent, CameraComponent>();

            for (const auto& entity : view) {
                const auto& [transform, camera] = view.get<TransformComponent, CameraComponent>(entity);

                if (camera.IsPrimary()) {
                    primaryCamera          = &camera.GetCamera();
                    primaryCameraTransform = &transform.GetTransform();

                    break;
                }
            }
        }

        if (primaryCamera) {
            Renderer2D::BeginScene(*primaryCamera, *primaryCameraTransform);

            auto view = m_Registry.view<TransformComponent, SpriteRendererComponent>();

            for (const auto& entity : view) {
                const auto& [transform, sprite] = view.get<TransformComponent, SpriteRendererComponent>(entity);

                Renderer2D::DrawQuad((const glm::mat4&)transform, (const glm::vec4&)sprite);
            }

            Renderer2D::EndScene();
        }
    }

    Entity Scene::CreateEntity(const std::string& tag) {
        Entity entity(m_Registry.create(), this);

        entity.PushComponent<TagComponent>(tag);
        entity.PushComponent<TransformComponent>();

        return entity;
    }

} // namespace Ziben