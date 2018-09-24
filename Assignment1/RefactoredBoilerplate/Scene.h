/*
* Scene.h
*	Class for storing objects in a scene
*  Created on: Sep 10, 2018
*      Author: cb-ha
*/

#ifndef SCENE_H_
#define SCENE_H_

#include <vector>

#include "Geometry.h"

//Forward declaration of classes
//(note this is necessary because these are pointers and it allows the #include to appear in the .cpp file)
class RenderingEngine;

class Scene {
public:
	Scene(RenderingEngine* renderer);
	virtual ~Scene();

	//Send geometry to the renderer
	void displayScene();
	void changeToP1Level1();
	void changeToP1Level2();
	void changeToP1Level3();
	void changetoP1Level4();
	void changetoP1Level5();
	void changetoP1Level6();
	void changeToCircleScene(int iter);
	void makeMengerSquare(float x, float y, int iter, int iter1);
	void iterationUp();
	void iterationDown();

private:

	std::string sceneType;
	RenderingEngine * renderer;

	//list of objects in the scene
	std::vector<Geometry> objects;
};

#endif /* SCENE_H_ */
