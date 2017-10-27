// OpenGL_Tutorial.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <GL/glew.h>
#include <GL/freeglut.h>
#include "math_3d.h"

//#pragma comment(linker,"/subsystem:\"Windows\" /ENTRY:\"mainCRTStartup\"")
//#pragma comment(linker," /NODEFAULTLIB:libcmt.lib")
/*#pragma comment(lib, "glew32s.lib")*/

/*Vertex Buffer Object, We allocate a GLuint in the global part of the program to store the handle of the vertex buffer object. You will see later that most (if not all) OpenGL objects are accessed via a variable of GLuint type*/
GLuint VBO;

void RenderDisplay(void)
{
	glClear(GL_COLOR_BUFFER_BIT);

	/*In this tutorial we are not yet using any shader but the vertex position we have loaded into the buffer is treated as vertex attribute index 0 in the fixed function pipeline (which becomes active when there is no shader bound). You must enable each vertex attribute or else the data will not be accessible by the pipeline.*/
	glEnableVertexAttribArray(0);

	/*Here we bind our buffer again as we prepare for making the draw call. In this small program we only have one vertex buffer so making this call every frame is redundent but in more complex programs there are multiple buffers to store your various models and you must update the pipeline state with the buffer you intend to use.*/
	glBindBuffer(GL_ARRAY_BUFFER, VBO);

	/*This call tells the pipeline how to interpret the data inside the buffer. The first parameter specifies the index of the attribute. In our case we know that it is zero by default but when we start using shaders we will either need to explicitly set the index in the shader or query it. The second parameter is the number of components in the attribute (3 for X, Y and Z). The third parameter is the data type of each component. The next parameter indicates whether we want our attribute to be normalized before it is used in the pipeline. It our case we want the data to pass un-changed. The fifth parameter (called the 'stride') is the number of bytes between two instances of that attribute in the buffer. When there is only one attribute (e.g. the buffer contains only vertex positions) and the data is tightly packed we pass the value zero. If we have an array of structures that contain a position and normal (each one is a vector of 3 floats) we will pass the size of the structure in bytes (6 * 4 = 24). The last parameter is useful in the case of the previous example. We need to specify the offset inside the structure where the pipeline will find our attribute. In the case of the structure with the position and normal the offset of the position is zero while the offset of the normal is 12.*/
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, 0);

	glDrawArrays(GL_POINTS, 0, 1);

	glDisableVertexAttribArray(0);

	glutSwapBuffers();
}

/*Create vertex buffer, initialize its data*/
void CreateVertexBuffer() 
{
	Vector3f Vertices[1];

	Vertices[0] = Vector3f(0.0f, 0.0f, 0.0f);

	/*the first one specifies the number of objects you want to create and the second is the address of an array of GLuints to store the handles that the driver allocates for you*/
	glGenBuffers(1, &VBO);

	/*In OpenGL we bind the handle to a target name and then execute commands on that target. These commmands affect the bounded handle until another one is bound in its stead or the call above takes zero as the handle.*/
	glBindBuffer(GL_ARRAY_BUFFER, VBO);

	/*GL_STATIC_DRAW. The opposite will be GL_DYNAMIC_DRAW. While this is only a hint to OpenGL it is a good thing to give some thought as to the proper flag to use. The driver can rely on it for optimization heuristics (such as what is the best place in memory to store the buffer).*/
	glBufferData(GL_ARRAY_BUFFER, sizeof(Vertices), Vertices, GL_STATIC_DRAW);

}

int main(int argc, char* argv[])
{
	glutInit(&argc, argv);

	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA);

	int WindowWidth = 1024;
	int WindowHeigth = 768;
	glutInitWindowSize(WindowWidth, WindowHeigth);
	int screenWidth = glutGet(GLUT_SCREEN_WIDTH);
	int screenHeight = glutGet(GLUT_SCREEN_HEIGHT);
	glutInitWindowPosition((screenWidth - WindowWidth) / 2, (screenHeight - WindowHeigth) / 2);
	glutCreateWindow("Tutorial 02");

	glutDisplayFunc(RenderDisplay);

	/*Init Glew*/
	GLenum result = glewInit();
	if (result != GLEW_OK)
	{
		fprintf(stderr, "Error: '%s'", glewGetErrorString(result));
	}



	CreateVertexBuffer();

	glutMainLoop();

	return 0;
}


