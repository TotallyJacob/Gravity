#include "Camera.h"

Camera::Camera() {
}

void Camera::setMovementVector(glm::vec3 vector) {
	//forward / back
	position += vector.x * viewDirection;
	//Strafe
	glm::vec3 strafeDirection = glm::cross(viewDirection, upVector);
	position += vector.z * strafeDirection;
	//Up/Down
	position += vector.y * upVector;
}
void Camera::setRotation(glm::vec2 mouseDelta) {
	viewDirection = glm::mat3(glm::rotate(-mouseDelta.x, upVector)) * viewDirection;
	glm::vec3 toRotateAround = glm::cross(viewDirection, upVector);
	viewDirection = glm::mat3(glm::rotate(mouseDelta.y, toRotateAround)) * viewDirection;
}
void Camera::setLocation(glm::vec3 location) {
	position.x = location.x;
	position.y = location.y;
	position.z = location.z;
}