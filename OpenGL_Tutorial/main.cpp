// OpenGL_Tutorial.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <GL/glew.h>
#include <GL/freeglut.h>

//#pragma comment(linker,"/subsystem:\"Windows\" /ENTRY:\"mainCRTStartup\"")

/*在 OpenGL 中，这是我们第一次遇到 ‘state’ 这个概念。提出 ‘state’ 的原因是：渲染是一个复杂的任务，不能够像对待一个接受参数的函数命令（设计良好的函数不会有太多参数）一样对待它。你需要去指定 shaders、buffers 和各种可以影响渲染过程的属性。此外，你会经常需要让几个渲染操作有同样的设置（比如，如果你从未禁用深度测试的功能，那就不用在每次渲染调用的时候去设置它）。这就是为什么 “大部分渲染操作的配置是通过设置 OpenGL 状态机内的属性和参数值来完成，而渲染命令仅能使用跟绘制的顶点的个数和初始偏移量有关的个别参数” 的原因。在调用一个状态改变函数之后（改变 OpenGL 的状态），这个状态将保持不变直到用不同的参数值再次调用此函数。上面这个函数是用来设置清除帧缓存（后面介绍）时要用到的颜色。颜色有四个通道（RGBA），而且它被指定为 0.0 – 1.0 之间标准化的值。*/
void RenderDisplay(void)
{

	glClearColor(0.0f, 0.0f, 0.0f, 0.0f);

	/*第一个函数的功能仅仅就是清除帧缓存（使用我们在上面指定过的颜色）。第二个函数调用是为了告诉 GLUT 在 backbuffer 和 frontbuffer 之间进行交换。在通过帧回调函数的下一个循环中，我们将场景渲染到当前的 frontbuffer 中，而 backbuffer 将被显示。*/
	glClear(GL_COLOR_BUFFER_BIT);
	glutSwapBuffers();
}

int main(int argc, char* argv[])
{
	/*这个函数是为了初始化 GLUT。里面的参数可以直接从命令行中得到，同时可以包含其他有用的选项比如 '-sync' 和 '-gldebug'，这样可以自动的检查GL的错误并独立的显示它们。*/
	glutInit(&argc, argv);

	/*现在我们学习设置一些 GLUT 的参数，GLUT_DOUBLE 设置双缓冲（double buffering，即当一个 buffer 显示的时候，另一个 buffer 用来绘制）和 color buffer，后者是大多数渲染结束的地方（比如屏幕）。后面章节中我们经常用到这两个和其他的参数。*/
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA);

	/*这些函数设置了窗口的参数（包括窗口大小、窗口位置以及窗口标题）并创建窗口。*/
	int WindowWidth = 1024;
	int WindowHeigth = 768;
	glutInitWindowSize(WindowWidth, WindowHeigth);
	int screenWidth = glutGet(GLUT_SCREEN_WIDTH);
	int screenHeight = glutGet(GLUT_SCREEN_HEIGHT);
	glutInitWindowPosition((screenWidth - WindowWidth) / 2, (screenHeight - WindowHeigth) / 2);
	glutCreateWindow("Tutorial 01");

	/*GLUT 可以和基本的窗口系统进行交互，并且提供给我们一些回调函数。在这里我们仅仅使用了一个主回调函数，这个主回调函数完成了一帧中的所有渲染工作。这个函数被 GLUT 内部循环不断的调用。*/
	glutDisplayFunc(RenderDisplay);

	/*这个函数调用将控制传递给 GLUT，并且开启了它自己内部的循环。在这个循环中，它监听来自窗口系统的事件并通过我们设置的回调函数传递给 GLUT。在本例子中，GLUT只调用我们定义用来显示窗口的回调函数（RenderDisplay），以使我们能渲染帧。*/
	glutMainLoop();

}


