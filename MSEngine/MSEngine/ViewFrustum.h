/* MANTAS */

#pragma once

#include "ResourceManager.h"
#include "Camera.h"

class Camera;

class ViewFrustum{
protected:
public:
	ViewFrustum();
	~ViewFrustum();
	void culling(Camera* camera);
};

