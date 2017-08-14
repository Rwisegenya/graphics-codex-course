#include "Surfel.h"

Surfel::Surfel(const glm::vec3& _faceNormal, const glm::vec3& _rayDirection, const glm::vec3 _position){
    geometricNormal = _faceNormal;
    shadingNormal = _faceNormal; // TODO, this should be calculated, for example from a bump map
    position = _position;
//  We'll allow all of our triangles to be �two sided� for now, so that we see consistent results from the front and back of the triangle. When you detect a hit on the triangle, if the dot product of the ray direction and the counter-clockwise normal is positive, then the ray actually struck the triangle from behind.
    if(glm::dot(_faceNormal, _rayDirection) >= 0){
        backface = true;
    }
    color = glm::vec3(1.f,1.f,1.f); //for now, all the surfaces are white. TODO, pass the color when initializing the Surfel

}

glm::vec3 Surfel::emittedRadiance(glm::vec3 wo) const {
    return glm::vec3(0.f,0.f,0.f); //material is not emissive
};

glm::vec3 Surfel::finiteScatteringDensity(const glm::vec3& w_i, const glm::vec3& w_o) const {
    //easy for now. TODO, implement different reflections
    return lambertianReflectivity();
}

glm::vec3 Surfel::getColor() const{
    return glm::vec3(1.0,1.0,1.0);
}

// From http://graphicscodex.com/projects/rays/
// "The simplest material parameter is to set the G3D::UniversalSurfel::lambertianReflectivity to the color that you want the object to appear."
glm::vec3 Surfel::lambertianReflectivity() const {
    return color;
}
