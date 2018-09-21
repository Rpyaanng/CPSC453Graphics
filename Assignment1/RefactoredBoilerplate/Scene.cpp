/*
* Scene.cpp
*
*  Created on: Sep 10, 2018
*  Author: John Hall
*/

#include "Scene.h"

#include <iostream>
#include "RenderingEngine.h"

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

//**Must include glad and GLFW in this order or it breaks**
#include "glad/glad.h"
#include <GLFW/glfw3.h>

Scene::Scene(RenderingEngine* renderer) : renderer(renderer)
{
	changeToTriangleScene();
}

Scene::~Scene() {

}

void Scene::displayScene() {
	renderer->RenderScene(objects);
}

void Scene::changeToTriangleScene()
{
	sceneType = "TRIANGLE_SCENE";
	objects.clear();
	//Create a single triangle
	//Additional triangles can be created by pushing groups of three more vertices into the verts vector
	Geometry square0;
	square0.verts.push_back(glm::vec3(-1.0f, -1.0f, 1.0f));
	square0.verts.push_back(glm::vec3(-1.0f, 1.0f, 1.0f));
	square0.verts.push_back(glm::vec3(1.0f, -1.0f, 1.0f));
	square0.verts.push_back(glm::vec3(1.0f, 1.0f, 1.0f));

	//Colors are stored per vertex in the order of the vertices
	square0.colors.push_back(glm::vec3(1.0f, 0.0f, 0.0f));
	square0.colors.push_back(glm::vec3(1.0f, 0.0f, 0.0f));
	square0.colors.push_back(glm::vec3(1.0f, 0.0f, 0.0f));
	square0.colors.push_back(glm::vec3(1.0f, 0.0f, 0.0f));
	

	square0.drawMode = GL_LINES;

	//Construct vao and vbos for the triangle
	RenderingEngine::assignBuffers(square0);

	//Send the triangle data to the GPU
	//Must be done every time the triangle is modified in any way, ex. verts, colors, normals, uvs, etc.
	RenderingEngine::setBufferData(square0);

	//Add the triangle to the scene objects
	objects.push_back(square0);

	//Create a single triangle
	//Additional triangles can be created by pushing groups of three more vertices into the verts vector
	Geometry square1;

	square1.verts.push_back(glm::vec3(0.0f, -1.0f, 1.0f));
	square1.verts.push_back(glm::vec3(1.0f, 0.0f, 1.0f));
	square1.verts.push_back(glm::vec3(0.0f, 1.0f, 1.0f));
	square1.verts.push_back(glm::vec3(-1.0f, 0.0f, 1.0f));


	//Colors are stored per vertex in the order of the vertices
	square1.colors.push_back(glm::vec3(1.0f, 0.0f, 0.0f));
	square1.colors.push_back(glm::vec3(1.0f, 0.0f, 0.0f));
	square1.colors.push_back(glm::vec3(1.0f, 0.0f, 0.0f));
	square1.colors.push_back(glm::vec3(1.0f, 0.0f, 0.0f));

	square1.drawMode = GL_LINE_LOOP;

	//Construct vao and vbos for the triangle
	RenderingEngine::assignBuffers(square1);

	//Send the triangle data to the GPU
	//Must be done every time the triangle is modified in any way, ex. verts, colors, normals, uvs, etc.
	RenderingEngine::setBufferData(square1);

	//Add the triangle to the scene objects
	objects.push_back(square1);
}

void Scene::changeToCircleScene()
{
	sceneType = "CIRCLE_SCENE";


	objects.clear();

	//Create a single triangle
	//Additional triangles can be created by pushing groups of three more vertices into the verts vector
	Geometry circle;
	int numSegments = 100;
	float du = 2 * 3.14f / numSegments;
	for (float u = 0; u < 2 * 3.14f; u += du)
	{
		//vertex at this value of u
		circle.verts.push_back(glm::vec3(1 * cos(u), 1 * sin(u), 1.0));
		//color at this value of u
		circle.colors.push_back(glm::vec3(1.0f, 0.0f, 0.0f));
	}

	circle.drawMode = GL_LINES;

	//Construct vao and vbos for the triangle
	RenderingEngine::assignBuffers(circle);

	//Send the triangle data to the GPU
	//Must be done every time the triangle is modified in any way, ex. verts, colors, normals, uvs, etc.
	RenderingEngine::setBufferData(circle);

	//Add the triangle to the scene objects
	objects.push_back(circle);
}

void Scene::iterationUp()
{
	
	if (sceneType == "TRIANGLE_SCENE")
	{
		sceneType = "TRIANGLE_SCENE1";

		//Create a single triangle
		//Additional triangles can be created by pushing groups of three more vertices into the verts vector
		Geometry square2;

		square2.verts.push_back(glm::vec3(-0.5f, -0.5f, 1.0f));
		square2.verts.push_back(glm::vec3(-0.5f, 0.5f, 1.0f));
		square2.verts.push_back(glm::vec3(0.5f, 0.5f, 1.0f));
		square2.verts.push_back(glm::vec3(0.5f, -0.5f, 1.0f));


		//Colors are stored per vertex in the order of the vertices
		square2.colors.push_back(glm::vec3(1.0f, 0.0f, 0.0f));
		square2.colors.push_back(glm::vec3(1.0f, 0.0f, 0.0f));
		square2.colors.push_back(glm::vec3(1.0f, 0.0f, 0.0f));
		square2.colors.push_back(glm::vec3(1.0f, 0.0f, 0.0f));

		square2.drawMode = GL_LINE_LOOP;

		//Construct vao and vbos for the triangle
		RenderingEngine::assignBuffers(square2);

		//Send the triangle data to the GPU
		//Must be done every time the triangle is modified in any way, ex. verts, colors, normals, uvs, etc.
		RenderingEngine::setBufferData(square2);

		//Add the triangle to the scene objects
		objects.push_back(square2);

		//Create a single triangle
		//Additional triangles can be created by pushing groups of three more vertices into the verts vector
		Geometry square3;

		square3.verts.push_back(glm::vec3(0.0f, -0.5f, 1.0f));
		square3.verts.push_back(glm::vec3(0.5f, 0.0f, 1.0f));
		square3.verts.push_back(glm::vec3(0.0f, 0.5f, 1.0f));
		square3.verts.push_back(glm::vec3(-0.5f, 0.0f, 1.0f));


		//Colors are stored per vertex in the order of the vertices
		square3.colors.push_back(glm::vec3(1.0f, 0.0f, 0.0f));
		square3.colors.push_back(glm::vec3(1.0f, 0.0f, 0.0f));
		square3.colors.push_back(glm::vec3(1.0f, 0.0f, 0.0f));
		square3.colors.push_back(glm::vec3(1.0f, 0.0f, 0.0f));

		square3.drawMode = GL_LINE_LOOP;

		//Construct vao and vbos for the triangle
		RenderingEngine::assignBuffers(square3);

		//Send the triangle data to the GPU
		//Must be done every time the triangle is modified in any way, ex. verts, colors, normals, uvs, etc.
		RenderingEngine::setBufferData(square3);

		//Add the triangle to the scene objects
		objects.push_back(square3);

		
	}
	else if (sceneType == "TRIANGLE_SCENE1")
	{
		sceneType = "TRIANGLE_SCENE2";

		//Create a single triangle
		//Additional triangles can be created by pushing groups of three more vertices into the verts vector
		Geometry square4;

		square4.verts.push_back(glm::vec3(-0.25f, -0.25f, 1.0f));
		square4.verts.push_back(glm::vec3(-0.25f, 0.25f, 1.0f));
		square4.verts.push_back(glm::vec3(0.25f, 0.25f, 1.0f));
		square4.verts.push_back(glm::vec3(0.25f, -0.25f, 1.0f));


		//Colors are stored per vertex in the order of the vertices
		square4.colors.push_back(glm::vec3(1.0f, 0.0f, 0.0f));
		square4.colors.push_back(glm::vec3(1.0f, 0.0f, 0.0f));
		square4.colors.push_back(glm::vec3(1.0f, 0.0f, 0.0f));
		square4.colors.push_back(glm::vec3(1.0f, 0.0f, 0.0f));

		square4.drawMode = GL_LINE_LOOP;

		//Construct vao and vbos for the triangle
		RenderingEngine::assignBuffers(square4);

		//Send the triangle data to the GPU
		//Must be done every time the triangle is modified in any way, ex. verts, colors, normals, uvs, etc.
		RenderingEngine::setBufferData(square4);

		//Add the triangle to the scene objects
		objects.push_back(square4);

		//Create a single triangle
		//Additional triangles can be created by pushing groups of three more vertices into the verts vector
		Geometry square5;

		square5.verts.push_back(glm::vec3(0.0f, -0.25f, 1.0f));
		square5.verts.push_back(glm::vec3(0.25f, 0.0f, 1.0f));
		square5.verts.push_back(glm::vec3(0.0f, 0.25f, 1.0f));
		square5.verts.push_back(glm::vec3(-0.25f, 0.0f, 1.0f));


		//Colors are stored per vertex in the order of the vertices
		square5.colors.push_back(glm::vec3(1.0f, 0.0f, 0.0f));
		square5.colors.push_back(glm::vec3(1.0f, 0.0f, 0.0f));
		square5.colors.push_back(glm::vec3(1.0f, 0.0f, 0.0f));
		square5.colors.push_back(glm::vec3(1.0f, 0.0f, 0.0f));

		square5.drawMode = GL_LINE_LOOP;

		//Construct vao and vbos for the triangle
		RenderingEngine::assignBuffers(square5);

		//Send the triangle data to the GPU
		//Must be done every time the triangle is modified in any way, ex. verts, colors, normals, uvs, etc.
		RenderingEngine::setBufferData(square5);

		//Add the triangle to the scene objects
		objects.push_back(square5);
	}
	else if (sceneType == "TRIANGLE_SCENE2")
	{
		sceneType = "TRIANGLE_SCENE3";

		//Create a single triangle
		//Additional triangles can be created by pushing groups of three more vertices into the verts vector
		Geometry square6;

		square6.verts.push_back(glm::vec3(-0.125f, -0.125f, 1.0f));
		square6.verts.push_back(glm::vec3(-0.125f, 0.125f, 1.0f));
		square6.verts.push_back(glm::vec3(0.125f, 0.125f, 1.0f));
		square6.verts.push_back(glm::vec3(0.125f, -0.125f, 1.0f));


		//Colors are stored per vertex in the order of the vertices
		square6.colors.push_back(glm::vec3(1.0f, 0.0f, 0.0f));
		square6.colors.push_back(glm::vec3(1.0f, 0.0f, 0.0f));
		square6.colors.push_back(glm::vec3(1.0f, 0.0f, 0.0f));
		square6.colors.push_back(glm::vec3(1.0f, 0.0f, 0.0f));

		square6.drawMode = GL_LINE_LOOP;

		//Construct vao and vbos for the triangle
		RenderingEngine::assignBuffers(square6);

		//Send the triangle data to the GPU
		//Must be done every time the triangle is modified in any way, ex. verts, colors, normals, uvs, etc.
		RenderingEngine::setBufferData(square6);

		//Add the triangle to the scene objects
		objects.push_back(square6);

		//Create a single triangle
		//Additional triangles can be created by pushing groups of three more vertices into the verts vector
		Geometry square7;

		square7.verts.push_back(glm::vec3(0.0f, -0.125f, 1.0f));
		square7.verts.push_back(glm::vec3(0.125f, 0.0f, 1.0f));
		square7.verts.push_back(glm::vec3(0.0f, 0.125f, 1.0f));
		square7.verts.push_back(glm::vec3(-0.125f, 0.0f, 1.0f));


		//Colors are stored per vertex in the order of the vertices
		square7.colors.push_back(glm::vec3(1.0f, 0.0f, 0.0f));
		square7.colors.push_back(glm::vec3(1.0f, 0.0f, 0.0f));
		square7.colors.push_back(glm::vec3(1.0f, 0.0f, 0.0f));
		square7.colors.push_back(glm::vec3(1.0f, 0.0f, 0.0f));

		square7.drawMode = GL_LINE_LOOP;

		//Construct vao and vbos for the triangle
		RenderingEngine::assignBuffers(square7);

		//Send the triangle data to the GPU
		//Must be done every time the triangle is modified in any way, ex. verts, colors, normals, uvs, etc.
		RenderingEngine::setBufferData(square7);

		//Add the triangle to the scene objects
		objects.push_back(square7);
		
	}
	else if (sceneType == "TRIANGLE_SCENE3")
	{
		sceneType = "TRIANGLE_SCENE4";

		//Create a single triangle
		//Additional triangles can be created by pushing groups of three more vertices into the verts vector
		Geometry square8;

		square8.verts.push_back(glm::vec3(-0.06025f, -0.06025f, 1.0f));
		square8.verts.push_back(glm::vec3(-0.06025f, 0.06025f, 1.0f));
		square8.verts.push_back(glm::vec3(0.06025f, 0.06025, 1.0f));
		square8.verts.push_back(glm::vec3(0.06025f, -0.06025, 1.0f));


		//Colors are stored per vertex in the order of the vertices
		square8.colors.push_back(glm::vec3(1.0f, 0.0f, 0.0f));
		square8.colors.push_back(glm::vec3(1.0f, 0.0f, 0.0f));
		square8.colors.push_back(glm::vec3(1.0f, 0.0f, 0.0f));
		square8.colors.push_back(glm::vec3(1.0f, 0.0f, 0.0f));

		square8.drawMode = GL_LINE_LOOP;

		//Construct vao and vbos for the triangle
		RenderingEngine::assignBuffers(square8);

		//Send the triangle data to the GPU
		//Must be done every time the triangle is modified in any way, ex. verts, colors, normals, uvs, etc.
		RenderingEngine::setBufferData(square8);

		//Add the triangle to the scene objects
		objects.push_back(square8);

		//Create a single triangle
		//Additional triangles can be created by pushing groups of three more vertices into the verts vector
		Geometry square9;

		square9.verts.push_back(glm::vec3(0.0f, -0.06025f, 1.0f));
		square9.verts.push_back(glm::vec3(0.06025f, 0.0f, 1.0f));
		square9.verts.push_back(glm::vec3(0.0f, 0.06025f, 1.0f));
		square9.verts.push_back(glm::vec3(-0.06025f, 0.0f, 1.0f));


		//Colors are stored per vertex in the order of the vertices
		square9.colors.push_back(glm::vec3(1.0f, 0.0f, 0.0f));
		square9.colors.push_back(glm::vec3(1.0f, 0.0f, 0.0f));
		square9.colors.push_back(glm::vec3(1.0f, 0.0f, 0.0f));
		square9.colors.push_back(glm::vec3(1.0f, 0.0f, 0.0f));

		square9.drawMode = GL_LINE_LOOP;

		//Construct vao and vbos for the triangle
		RenderingEngine::assignBuffers(square9);

		//Send the triangle data to the GPU
		//Must be done every time the triangle is modified in any way, ex. verts, colors, normals, uvs, etc.
		RenderingEngine::setBufferData(square9);

		//Add the triangle to the scene objects
		objects.push_back(square9);

		
	}
	else if (sceneType == "TRIANGLE_SCENE4")
	{
		sceneType = "TRIANGLE_SCENE5";

		//Create a single triangle
		//Additional triangles can be created by pushing groups of three more vertices into the verts vector
		Geometry square10;

		square10.verts.push_back(glm::vec3(-0.030125f, -0.030125f, 1.0f));
		square10.verts.push_back(glm::vec3(-0.030125f, 0.030125f, 1.0f));
		square10.verts.push_back(glm::vec3(0.030125f, 0.030125, 1.0f));
		square10.verts.push_back(glm::vec3(0.030125f, -0.030125, 1.0f));


		//Colors are stored per vertex in the order of the vertices
		square10.colors.push_back(glm::vec3(1.0f, 0.0f, 0.0f));
		square10.colors.push_back(glm::vec3(1.0f, 0.0f, 0.0f));
		square10.colors.push_back(glm::vec3(1.0f, 0.0f, 0.0f));
		square10.colors.push_back(glm::vec3(1.0f, 0.0f, 0.0f));

		square10.drawMode = GL_LINE_LOOP;

		//Construct vao and vbos for the triangle
		RenderingEngine::assignBuffers(square10);

		//Send the triangle data to the GPU
		//Must be done every time the triangle is modified in any way, ex. verts, colors, normals, uvs, etc.
		RenderingEngine::setBufferData(square10);

		//Add the triangle to the scene objects
		objects.push_back(square10);

		//Create a single triangle
		//Additional triangles can be created by pushing groups of three more vertices into the verts vector
		Geometry square11;

		square11.verts.push_back(glm::vec3(0.0f, -0.030125f, 1.0f));
		square11.verts.push_back(glm::vec3(0.030125f, 0.0f, 1.0f));
		square11.verts.push_back(glm::vec3(0.0f, 0.030125f, 1.0f));
		square11.verts.push_back(glm::vec3(-0.030125f, 0.0f, 1.0f));


		//Colors are stored per vertex in the order of the vertices
		square11.colors.push_back(glm::vec3(1.0f, 0.0f, 0.0f));
		square11.colors.push_back(glm::vec3(1.0f, 0.0f, 0.0f));
		square11.colors.push_back(glm::vec3(1.0f, 0.0f, 0.0f));
		square11.colors.push_back(glm::vec3(1.0f, 0.0f, 0.0f));

		square11.drawMode = GL_LINE_LOOP;

		//Construct vao and vbos for the triangle
		RenderingEngine::assignBuffers(square11);

		//Send the triangle data to the GPU
		//Must be done every time the triangle is modified in any way, ex. verts, colors, normals, uvs, etc.
		RenderingEngine::setBufferData(square11);

		//Add the triangle to the scene objects
		objects.push_back(square11);
		
	}
	else if (sceneType == "CIRCLE_SCENE")
	{
		std::cout << "iteration up for circle scene! Implement me!" << std::endl;
	}
}

void Scene::iterationDown()
{
	if (sceneType == "TRIANGLE_SCENE1")
	{

	}
	else if (sceneType == "CIRCLE_SCENE")
	{
		std::cout << "iteration down for circle scene! Implement me!" << std::endl;
	}
}