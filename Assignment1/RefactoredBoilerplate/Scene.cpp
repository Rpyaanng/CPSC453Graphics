/*
* Scene.cpp
*
*  Created on: Sep 10, 2018
*  Author: John Hall
*/

#include "Scene.h"

#include <iostream>
using namespace std;
#include "RenderingEngine.h"

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

//**Must include glad and GLFW in this order or it breaks**
#include "glad/glad.h"
#include <GLFW/glfw3.h>

Scene::Scene(RenderingEngine* renderer) : renderer(renderer)
{
	changeToP1Level1();
}

Scene::~Scene() {

}

void Scene::displayScene() {
	renderer->RenderScene(objects);
}

void Scene::changeToP1Level1()
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

void Scene::changeToP1Level2()
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

void Scene::changeToP1Level3()
{
	sceneType = "TRIANGLE_SCENE2";

	//Create a single triangle
	//Additional triangles can be created by pushing groups of three more vertices into the verts vector
	Geometry square2;

	square2.verts.push_back(glm::vec3(-0.25f, -0.25f, 1.0f));
	square2.verts.push_back(glm::vec3(-0.25f, 0.25f, 1.0f));
	square2.verts.push_back(glm::vec3(0.25f, 0.25f, 1.0f));
	square2.verts.push_back(glm::vec3(0.25f, -0.25f, 1.0f));


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

	square3.verts.push_back(glm::vec3(0.0f, -0.25f, 1.0f));
	square3.verts.push_back(glm::vec3(0.25f, 0.0f, 1.0f));
	square3.verts.push_back(glm::vec3(0.0f, 0.25f, 1.0f));
	square3.verts.push_back(glm::vec3(-0.25f, 0.0f, 1.0f));


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

void Scene::changetoP1Level4()
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

void Scene::changetoP1Level5()
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

void Scene::changetoP1Level6()
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

void Scene::changeToCircleScene(int iter)
{
	switch (iter) {
		case 1: sceneType = "CIRCLE_SCENE";
			break;
		case 2: sceneType = "CIRCLE_SCENE1";
			break;
		case 3: sceneType = "CIRCLE_SCENE2";
			break;
		case 4: sceneType = "CIRCLE_SCENE3";
			break;
	}

	objects.clear();

	//Create a single triangle
	//Additional triangles can be created by pushing groups of three more vertices into the verts vector
	Geometry circle;
	int numSegments = 100;
	float du = 2 * 3.14f / numSegments;
	for (float u = 0; u < (((iter-1)*2) + 6) * 3.14f; u += du)
	{
		//vertex at this value of u
		circle.verts.push_back(glm::vec3((1 * cos(u)*u)*(0.02),(1 * sin(u)*u)*(0.02) , 1.0));
		//color at this value of u
		circle.colors.push_back(glm::vec3(1.0f-(0.05f*u), 0.0f, 0.0f));
	}

	circle.drawMode = GL_LINE_STRIP;

	//Construct vao and vbos for the triangle
	RenderingEngine::assignBuffers(circle);

	//Send the triangle data to the GPU
	//Must be done every time the triangle is modified in any way, ex. verts, colors, normals, uvs, etc.
	RenderingEngine::setBufferData(circle);

	//Add the triangle to the scene objects
	objects.push_back(circle);
}

void Scene::makeMengerSquare(float x, float y, int iter, int iter1)
{
	if (iter1 == 1) {
		objects.clear();
	}
	if (iter > 1) {

		makeMengerSquare(x, y, iter - 1, iter1 + 1);
		makeMengerSquare(x + 2 / pow(3, iter1), y, iter - 1, iter1 + 1);
		makeMengerSquare(x + 2 * (2 / pow(3, iter1)), y, iter - 1, iter1 + 1);

		makeMengerSquare(x, y - 2 / pow(3, iter1), iter - 1, iter1 + 1);
		// blank space
		makeMengerSquare(x + 2 * (2 / pow(3, iter1)), y - 2 / pow(3, iter1), iter - 1, iter1 + 1);

		makeMengerSquare(x, y - 2 * (2 / pow(3, iter1)), iter - 1, iter1 + 1);
		makeMengerSquare(x + 2 / pow(3, iter1), y - 2 * (2 / pow(3, iter1)), iter - 1, iter1 + 1);
		makeMengerSquare(x + 2 * (2 / pow(3, iter1)), y - 2 * (2 / pow(3, iter1)), iter - 1, iter1 + 1);
	}
	else if (iter == 0) {
		sceneType = "MENGER_SCENE";
		objects.clear();
		//Create a single triangle
		//Additional triangles can be created by pushing groups of three more vertices into the verts vector
		Geometry square0;
		square0.verts.push_back(glm::vec3(-1.0f, -1.0f, 1.0f));
		square0.verts.push_back(glm::vec3(-1.0f, 1.0f, 1.0f));
		square0.verts.push_back(glm::vec3(1.0f, -1.0f, 1.0f));
		square0.verts.push_back(glm::vec3(1.0f, 1.0f, 1.0f));

		//Colors are stored per vertex in the order of the vertices
		square0.colors.push_back(glm::vec3(0.3f, 0.3f, 0.3f));
		square0.colors.push_back(glm::vec3(0.3f, 0.3f, 0.3f));
		square0.colors.push_back(glm::vec3(0.3f, 0.3f, 0.3f));
		square0.colors.push_back(glm::vec3(0.3f, 0.3f, 0.3f));


		square0.drawMode = GL_TRIANGLE_STRIP;

		//Construct vao and vbos for the triangle
		RenderingEngine::assignBuffers(square0);

		//Send the triangle data to the GPU
		//Must be done every time the triangle is modified in any way, ex. verts, colors, normals, uvs, etc.
		RenderingEngine::setBufferData(square0);

		//Add the triangle to the scene objects
		objects.push_back(square0);
	}
	else {
		//Create a single triangle
		//Additional triangles can be created by pushing groups of three more vertices into the verts vector
		Geometry square0;
		square0.verts.push_back(glm::vec3(x, y, 1.0f));
		square0.verts.push_back(glm::vec3(x, y - 2 / pow(3, iter1), 1.0f));
		square0.verts.push_back(glm::vec3(x + 2 / pow(3, iter1), y, 1.0f));
		square0.verts.push_back(glm::vec3(x + 2 / pow(3, iter1), y - 2 / pow(3, iter1), 1.0f));


		//Colors are stored per vertex in the order of the vertices
		square0.colors.push_back(glm::vec3(0.0f, 0.0f, 0.4f));
		square0.colors.push_back(glm::vec3(0.0f, 0.0f, 0.4f));
		square0.colors.push_back(glm::vec3(0.0f, 0.0f, 0.4f));
		square0.colors.push_back(glm::vec3(0.0f, 0.0f, 0.4f));


		square0.drawMode = GL_TRIANGLE_STRIP;

		//Construct vao and vbos for the triangle
		RenderingEngine::assignBuffers(square0);

		//Send the triangle data to the GPU
		//Must be done every time the triangle is modified in any way, ex. verts, colors, normals, uvs, etc.
		RenderingEngine::setBufferData(square0);

		objects.push_back(square0);

		//Create a single triangle
		//Additional triangles can be created by pushing groups of three more vertices into the verts vector
		Geometry square1;

		square1.verts.push_back(glm::vec3(x + 2 / pow(3, iter1), y, 1.0f));
		square1.verts.push_back(glm::vec3(x + 2 / pow(3, iter1), y - 2 / pow(3, iter1), 1.0f));
		square1.verts.push_back(glm::vec3(x + 2 * (2 / pow(3, iter1)), y, 1.0f));
		square1.verts.push_back(glm::vec3(x + 2 * (2 / pow(3, iter1)), y - 2 / pow(3, iter1), 1.0f));

		//Colors are stored per vertex in the order of the vertices
		square1.colors.push_back(glm::vec3(0.4f, 0.4f, 0.4f));
		square1.colors.push_back(glm::vec3(0.4f, 0.4f, 0.4f));
		square1.colors.push_back(glm::vec3(0.4f, 0.4f, 0.4f));
		square1.colors.push_back(glm::vec3(0.4f, 0.4f, 0.4f));

		square1.drawMode = GL_TRIANGLE_STRIP;

		//Construct vao and vbos for the triangle
		RenderingEngine::assignBuffers(square1);

		//Send the triangle data to the GPU
		//Must be done every time the triangle is modified in any way, ex. verts, colors, normals, uvs, etc.
		RenderingEngine::setBufferData(square1);

		objects.push_back(square1);

		Geometry square2;

		square2.verts.push_back(glm::vec3(x + 2 * (2 / pow(3, iter1)), y, 1.0f));
		square2.verts.push_back(glm::vec3(x + 2 * (2 / pow(3, iter1)), y - 2 / pow(3, iter1), 1.0f));
		square2.verts.push_back(glm::vec3(x + 3 * (2 / pow(3, iter1)), y, 1.0f));
		square2.verts.push_back(glm::vec3(x + 3 * (2 / pow(3, iter1)), y - 2 / pow(3, iter1), 1.0f));


		//Colors are stored per vertex in the order of the vertices
		square2.colors.push_back(glm::vec3(0.4f, 0.0f, 0.0f));
		square2.colors.push_back(glm::vec3(0.4f, 0.0f, 0.0f));
		square2.colors.push_back(glm::vec3(0.4f, 0.0f, 0.0f));
		square2.colors.push_back(glm::vec3(0.4f, 0.0f, 0.0f));

		square2.drawMode = GL_TRIANGLE_STRIP;

		//Construct vao and vbos for the triangle
		RenderingEngine::assignBuffers(square2);

		//Send the triangle data to the GPU
		//Must be done every time the triangle is modified in any way, ex. verts, colors, normals, uvs, etc.
		RenderingEngine::setBufferData(square2);

		objects.push_back(square2);

		//Create a single triangle
		//Additional triangles can be created by pushing groups of three more vertices into the verts vector
		Geometry square3;
		square3.verts.push_back(glm::vec3(x, y - 2 * (2 / pow(3, iter1)), 1.0f));
		square3.verts.push_back(glm::vec3(x, y - 2 / pow(3, iter1), 1.0f));
		square3.verts.push_back(glm::vec3(x + 2 / pow(3, iter1), y - 2 * (2 / pow(3, iter1)), 1.0f));
		square3.verts.push_back(glm::vec3(x + 2 / pow(3, iter1), y - 2 / pow(3, iter1), 1.0f));





		//Colors are stored per vertex in the order of the vertices
		square3.colors.push_back(glm::vec3(0.4f, 0.4f, 0.4f));
		square3.colors.push_back(glm::vec3(0.4f, 0.4f, 0.4f));
		square3.colors.push_back(glm::vec3(0.4f, 0.4f, 0.4f));
		square3.colors.push_back(glm::vec3(0.4f, 0.4f, 0.4f));

		square3.drawMode = GL_TRIANGLE_STRIP;

		//Construct vao and vbos for the triangle
		RenderingEngine::assignBuffers(square3);

		//Send the triangle data to the GPU
		//Must be done every time the triangle is modified in any way, ex. verts, colors, normals, uvs, etc.
		RenderingEngine::setBufferData(square3);

		objects.push_back(square3);



		Geometry square4;

		square4.verts.push_back(glm::vec3(x + 2 * (2 / pow(3, iter1)), y - 2 * (2 / pow(3, iter1)), 1.0f));
		square4.verts.push_back(glm::vec3(x + 2 * (2 / pow(3, iter1)), y - 2 / pow(3, iter1), 1.0f));
		square4.verts.push_back(glm::vec3(x + 3 * (2 / pow(3, iter1)), y - 2 * (2 / pow(3, iter1)), 1.0f));
		square4.verts.push_back(glm::vec3(x + 3 * (2 / pow(3, iter1)), y - 2 / pow(3, iter1), 1.0f));




		//Colors are stored per vertex in the order of the vertices
		square4.colors.push_back(glm::vec3(0.4f, 0.4f, 0.4f));
		square4.colors.push_back(glm::vec3(0.4f, 0.4f, 0.4f));
		square4.colors.push_back(glm::vec3(0.4f, 0.4f, 0.4f));
		square4.colors.push_back(glm::vec3(0.4f, 0.4f, 0.4f));

		square4.drawMode = GL_TRIANGLE_STRIP;

		//Construct vao and vbos for the triangle
		RenderingEngine::assignBuffers(square4);

		//Send the triangle data to the GPU
		//Must be done every time the triangle is modified in any way, ex. verts, colors, normals, uvs, etc.
		RenderingEngine::setBufferData(square4);

		objects.push_back(square4);

		//Create a single triangle
		//Additional triangles can be created by pushing groups of three more vertices into the verts vector
		Geometry square5;
		square5.verts.push_back(glm::vec3(x, y - 3 * (2 / pow(3, iter1)), 1.0f));
		square5.verts.push_back(glm::vec3(x, y - 2 * (2 / pow(3, iter1)), 1.0f));
		square5.verts.push_back(glm::vec3(x + 2 / pow(3, iter1), y - 3 * (2 / pow(3, iter1)), 1.0f));
		square5.verts.push_back(glm::vec3(x + 2 / pow(3, iter1), y - 2 * (2 / pow(3, iter1)), 1.0f));

		//Colors are stored per vertex in the order of the vertices
		square5.colors.push_back(glm::vec3(0.3f, 0.0f, 0.4f));
		square5.colors.push_back(glm::vec3(0.3f, 0.0f, 0.4f));
		square5.colors.push_back(glm::vec3(0.3f, 0.0f, 0.4f));
		square5.colors.push_back(glm::vec3(0.3f, 0.0f, 0.4f));

		square5.drawMode = GL_TRIANGLE_STRIP;

		//Construct vao and vbos for the triangle
		RenderingEngine::assignBuffers(square5);

		//Send the triangle data to the GPU
		//Must be done every time the triangle is modified in any way, ex. verts, colors, normals, uvs, etc.
		RenderingEngine::setBufferData(square5);

		objects.push_back(square5);

		Geometry square6;

		square6.verts.push_back(glm::vec3(x + (2 / pow(3, iter1)), y - 3 * (2 / pow(3, iter1)), 1.0f));
		square6.verts.push_back(glm::vec3(x + (2 / pow(3, iter1)), y - 2 * (2 / pow(3, iter1)), 1.0f));
		square6.verts.push_back(glm::vec3(x + 2 * (2 / pow(3, iter1)), y - 3 * (2 / pow(3, iter1)), 1.0f));
		square6.verts.push_back(glm::vec3(x + 2 * (2 / pow(3, iter1)), y - 2 * (2 / pow(3, iter1)), 1.0f));

		//Colors are stored per vertex in the order of the vertices
		square6.colors.push_back(glm::vec3(0.4f, 0.4f, 0.4f));
		square6.colors.push_back(glm::vec3(0.4f, 0.4f, 0.4f));
		square6.colors.push_back(glm::vec3(0.4f, 0.4f, 0.4f));
		square6.colors.push_back(glm::vec3(0.4f, 0.4f, 0.4f));

		square6.drawMode = GL_TRIANGLE_STRIP;

		//Construct vao and vbos for the triangle
		RenderingEngine::assignBuffers(square6);

		//Send the triangle data to the GPU
		//Must be done every time the triangle is modified in any way, ex. verts, colors, normals, uvs, etc.
		RenderingEngine::setBufferData(square6);

		objects.push_back(square6);

		Geometry square7;

		square7.verts.push_back(glm::vec3(x + 2 * (2 / pow(3, iter1)), y - 3 * (2 / pow(3, iter1)), 1.0f));
		square7.verts.push_back(glm::vec3(x + 2 * (2 / pow(3, iter1)), y - 2 * (2 / pow(3, iter1)), 1.0f));
		square7.verts.push_back(glm::vec3(x + 3 * (2 / pow(3, iter1)), y - 3 * (2 / pow(3, iter1)), 1.0f));
		square7.verts.push_back(glm::vec3(x + 3 * (2 / pow(3, iter1)), y - 2 * (2 / pow(3, iter1)), 1.0f));

		//Colors are stored per vertex in the order of the vertices
		square7.colors.push_back(glm::vec3(0.0f, 0.4f, 0.0f));
		square7.colors.push_back(glm::vec3(0.0f, 0.4f, 0.0f));
		square7.colors.push_back(glm::vec3(0.0f, 0.4f, 0.0f));
		square7.colors.push_back(glm::vec3(0.0f, 0.4f, 0.0f));

		square7.drawMode = GL_TRIANGLE_STRIP;

		//Construct vao and vbos for the triangle
		RenderingEngine::assignBuffers(square7);

		//Send the triangle data to the GPU
		//Must be done every time the triangle is modified in any way, ex. verts, colors, normals, uvs, etc.
		RenderingEngine::setBufferData(square7);

		objects.push_back(square7);

	}

}

void Scene::changeToSierpTriangle(int iter){
	objects.clear();
	float currentX = 0.0f;
	float currentY = 1.0f;
	Geometry point;
	for (float u = 0; u < iter; u += 1)
	{

		int randInt = rand() % 3;

		if(randInt == 0){
			currentX = currentX/2;
			currentY = (currentY + 1.0f)/2;





		} else if(randInt == 1){
			currentX = (currentX + -1.0f)/2;
			currentY = (currentY + -1.0f)/2;

		} else {
			currentX = (currentX + 1.0f)/2;
			currentY = (currentY + -1.0f)/2;
		}

		point.verts.push_back(glm::vec3(currentX,currentY, 1.0f));
		point.colors.push_back(glm::vec3(1.0f, 0.0f, 0.0f));
		point.drawMode = GL_POINTS;

		//Construct vao and vbos for the triangle
		RenderingEngine::assignBuffers(point);

		//Send the triangle data to the GPU
		//Must be done every time the triangle is modified in any way, ex. verts, colors, normals, uvs, etc.
		RenderingEngine::setBufferData(point);

		objects.push_back(point);
	}
}


void Scene::iterationUp()
{

	if (sceneType == "TRIANGLE_SCENE")
	{
		changeToP1Level2();
	}
	else if (sceneType == "TRIANGLE_SCENE1")
	{
		changeToP1Level3();
	}
	else if (sceneType == "TRIANGLE_SCENE2")
	{
		changetoP1Level4();
	}
	else if (sceneType == "TRIANGLE_SCENE3")
	{
		changetoP1Level5();
	}
	else if (sceneType == "TRIANGLE_SCENE4")
	{
		changetoP1Level6();
	}
	else if (sceneType == "CIRCLE_SCENE")
	{
		changeToCircleScene(2);
	}
	else if (sceneType == "CIRCLE_SCENE1")
	{
		changeToCircleScene(3);
	}
	else if (sceneType == "CIRCLE_SCENE2")
	{
		changeToCircleScene(4);
	}
	else if (sceneType == "CIRCLE_SCENE4")
	{
		changeToCircleScene(5);
	}
	else if (sceneType == "MENGER_SCENE")
	{
		sceneType = "MENGER_SCENE1";
		makeMengerSquare(-1.0f, 1.0f, 1, 1);
	}
	else if (sceneType == "MENGER_SCENE1")
	{
		sceneType = "MENGER_SCENE2";
		makeMengerSquare(-1.0f, 1.0f, 2, 1);
	}
	else if (sceneType == "MENGER_SCENE2")
	{
		sceneType = "MENGER_SCENE3";
		makeMengerSquare(-1.0f, 1.0f, 3, 1);
	}
	else if (sceneType == "MENGER_SCENE3")
	{
		sceneType = "MENGER_SCENE4";
		makeMengerSquare(-1.0f, 1.0f, 4, 1);
	}
	else if (sceneType == "MENGER_SCENE4")
	{
		sceneType = "MENGER_SCENE5";
		makeMengerSquare(-1.0f, 1.0f, 5, 1);
	}
	else if (sceneType == "MENGER_SCENE5")
	{
		sceneType = "MENGER_SCENE6";
		makeMengerSquare(-1.0f, 1.0f, 6, 1);
	}
}

void Scene::iterationDown()
{
	if (sceneType == "TRIANGLE_SCENE1")
	{
		changeToP1Level1();
	}
	else if (sceneType == "TRIANGLE_SCENE2")
	{
		changeToP1Level1();
		changeToP1Level2();
	}

	else if (sceneType == "TRIANGLE_SCENE3")
	{
		changeToP1Level1();
		changeToP1Level2();
		changeToP1Level3();
	}
	else if (sceneType == "TRIANGLE_SCENE4")
	{
		changeToP1Level1();
		changeToP1Level2();
		changeToP1Level3();
		changetoP1Level4();
	}
	else if (sceneType == "TRIANGLE_SCENE5")
	{
		changeToP1Level1();
		changeToP1Level2();
		changeToP1Level3();
		changetoP1Level4();
		changetoP1Level5();
	}
	else if (sceneType == "CIRCLE_SCENE1")
	{
		changeToCircleScene(1);
	}
	else if (sceneType == "CIRCLE_SCENE2")
	{
		changeToCircleScene(2);
	}
	else if (sceneType == "CIRCLE_SCENE3")
	{
		changeToCircleScene(3);
	}
	else if (sceneType == "MENGER_SCENE1")
	{
		sceneType = "MENGER_SCENE";
		makeMengerSquare(-1.0f, 1.0f, 0, 1);
	}
	else if (sceneType == "MENGER_SCENE2")
	{
		sceneType = "MENGER_SCENE1";
		makeMengerSquare(-1.0f, 1.0f, 1, 1);
	}
	else if (sceneType == "MENGER_SCENE3")
	{
		sceneType = "MENGER_SCENE2";
		makeMengerSquare(-1.0f, 1.0f, 2, 1);
	}
	else if (sceneType == "MENGER_SCENE4")
	{
		sceneType = "MENGER_SCENE3";
		makeMengerSquare(-1.0f, 1.0f, 3, 1);
	}
	else if (sceneType == "MENGER_SCENE5")
	{
		sceneType = "MENGER_SCENE4";
		makeMengerSquare(-1.0f, 1.0f, 4, 1);
	}
	else if (sceneType == "MENGER_SCENE6")
	{
		sceneType = "MENGER_SCENE5";
		makeMengerSquare(-1.0f, 1.0f, 5, 1);
	}

}
