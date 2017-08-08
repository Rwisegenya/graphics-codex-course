#pragma once
#include "ofMain.h"
#include "Surfel.h"
#include "PinholeCamera.h"
#include "ofxAssimpModelLoader.h"
#include "Ray.h"

// It takes a primary ray, it intersect it with a scene and it return a pointer to a surface element.
// A surface element (“surfel”) [Pfister2000Surfels] contains the intersection position, normal, and material information
// that will be useful for shading.
// If there is no intersection, then the pointer returned will be NULL. A NULL shared_ptr casts to the boolean false value.

class RayCaster {
public:
    // when you will pass a model from assimp,
    // remember this: https://github.com/openframeworks/openFrameworks/issues/2989
    RayCaster(const ofMesh& _mesh, glm::mat4 globalTransfMatrix);
    //iterates overall pixels calling traceRay
    void traceImage(const PinholeCamera& camera, shared_ptr<ofImage>& image) const;
protected:
    shared_ptr<Surfel> findFirstIntersection(const Ray& ray, const ofMesh& mesh) const;
    // 
    ofColor L_i(const Ray& ray) const;
    // Find the first intersection with the scene
    bool rayTriangleIntersect(const glm::vec3& P, const glm::vec3& w, const vector<glm::vec3> v, float baricenter[3], float& t) const;

    glm::vec3 getPointOnTriangle(const Ray& _ray, const glm::vec3& _baryPosition) const;
    ofMesh mesh;
    glm::mat4 globalTransfMatrix;

};
