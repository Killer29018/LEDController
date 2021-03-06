#include "Settings.hpp"

#include "../Application.hpp"

void Settings::renderImgui()
{
    if (ImGui::Begin("###Settings"))
    {
        ImGui::Text("Settings");

        ImGui::Text("Master Update Speed");
        int fps = Application::updateFPS;
        ImGui::SliderInt("#FPS", &fps, 10, 100);
        Application::updateFPS = fps;

        ImGui::Text("Brightness");
        int brightness = Application::m_Controller.getBrightness();
        ImGui::SliderInt("#Brightness", &brightness, 1, 255);
        Application::m_Controller.setBrightness((uint8_t)brightness);
    }
    ImGui::End();

}
