#ifndef CAMERA_H
#define CAMERA_H

#include "Addons/glad/glad.h"
#include <GLFW/glfw3.h>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>

/*
    enum to represent directions for movement
*/

enum class CameraDirection {
    FORWARD,
    BACKWARD,
    LEFT,
    RIGHT,
    UP,
    DOWN
};

/*
    camera class to help display from POV of camera
*/

class Camera {
public:
    /*
        camera values
    */


    // camera movement values
    float speed;

    /*
        constructor
    */

    // default and initialize with position
    Camera(glm::vec2 position, float left, float right, float bottom, float top)
            : cameraPos(position),
              left(left),
              right(right),
              bottom(bottom),
              top(top),
              zoom(1.0f)
    {
    }

    /*
        modifiers
    */

    // change camera direction (mouse movement)
//    void updateCameraDirection(double dx, double dy);

    // change camera position in certain direction (keyboard)
//    void updateCameraPos(CameraDirection direction, double dt);

    // change camera zoom (scroll wheel)
    void updateCameraZoom(double dy);

    /*
        accessors
    */

    // get view matrix for camera
    glm::mat4 getViewMatrix();

    glm::mat4 getProjectionMatrix() {
        return glm::ortho(left, right, bottom, top, -1.0f, 1.0f);
    }

    void updatePosition(glm::vec2 position) {
        cameraPos = position;
    }

    // get zoom value for camera
    float getZoom();

private:
    /*
        private modifier
    */
    glm::vec2 cameraPos;
    float left, right, bottom, top;
    float zoom;

    // change camera directional vectors based on movement
    void updateCameraVectors();
};

#endif