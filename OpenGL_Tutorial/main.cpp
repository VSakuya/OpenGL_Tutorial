// OpenGL_Tutorial.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <GL/glew.h>
#include <GL/freeglut.h>

//#pragma comment(linker,"/subsystem:\"Windows\" /ENTRY:\"mainCRTStartup\"")

/*�� OpenGL �У��������ǵ�һ������ ��state�� ��������� ��state�� ��ԭ���ǣ���Ⱦ��һ�����ӵ����񣬲��ܹ���Դ�һ�����ܲ����ĺ������������õĺ���������̫�������һ���Դ���������Ҫȥָ�� shaders��buffers �͸��ֿ���Ӱ����Ⱦ���̵����ԡ����⣬��ᾭ����Ҫ�ü�����Ⱦ������ͬ�������ã����磬������δ������Ȳ��ԵĹ��ܣ��ǾͲ�����ÿ����Ⱦ���õ�ʱ��ȥ���������������Ϊʲô ���󲿷���Ⱦ������������ͨ������ OpenGL ״̬���ڵ����ԺͲ���ֵ����ɣ�����Ⱦ�������ʹ�ø����ƵĶ���ĸ����ͳ�ʼƫ�����йصĸ�������� ��ԭ���ڵ���һ��״̬�ı亯��֮�󣨸ı� OpenGL ��״̬�������״̬�����ֲ���ֱ���ò�ͬ�Ĳ���ֵ�ٴε��ô˺�����������������������������֡���棨������ܣ�ʱҪ�õ�����ɫ����ɫ���ĸ�ͨ����RGBA������������ָ��Ϊ 0.0 �C 1.0 ֮���׼����ֵ��*/
void RenderDisplay(void)
{

	glClearColor(0.0f, 0.0f, 0.0f, 0.0f);

	/*��һ�������Ĺ��ܽ����������֡���棨ʹ������������ָ��������ɫ�����ڶ�������������Ϊ�˸��� GLUT �� backbuffer �� frontbuffer ֮����н�������ͨ��֡�ص���������һ��ѭ���У����ǽ�������Ⱦ����ǰ�� frontbuffer �У��� backbuffer ������ʾ��*/
	glClear(GL_COLOR_BUFFER_BIT);
	glutSwapBuffers();
}

int main(int argc, char* argv[])
{
	/*���������Ϊ�˳�ʼ�� GLUT������Ĳ�������ֱ�Ӵ��������еõ���ͬʱ���԰����������õ�ѡ����� '-sync' �� '-gldebug'�����������Զ��ļ��GL�Ĵ��󲢶�������ʾ���ǡ�*/
	glutInit(&argc, argv);

	/*��������ѧϰ����һЩ GLUT �Ĳ�����GLUT_DOUBLE ����˫���壨double buffering������һ�� buffer ��ʾ��ʱ����һ�� buffer �������ƣ��� color buffer�������Ǵ������Ⱦ�����ĵط���������Ļ���������½������Ǿ����õ��������������Ĳ�����*/
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA);

	/*��Щ���������˴��ڵĲ������������ڴ�С������λ���Լ����ڱ��⣩���������ڡ�*/
	int WindowWidth = 1024;
	int WindowHeigth = 768;
	glutInitWindowSize(WindowWidth, WindowHeigth);
	int screenWidth = glutGet(GLUT_SCREEN_WIDTH);
	int screenHeight = glutGet(GLUT_SCREEN_HEIGHT);
	glutInitWindowPosition((screenWidth - WindowWidth) / 2, (screenHeight - WindowHeigth) / 2);
	glutCreateWindow("Tutorial 01");

	/*GLUT ���Ժͻ����Ĵ���ϵͳ���н����������ṩ������һЩ�ص����������������ǽ���ʹ����һ�����ص�������������ص����������һ֡�е�������Ⱦ��������������� GLUT �ڲ�ѭ�����ϵĵ��á�*/
	glutDisplayFunc(RenderDisplay);

	/*����������ý����ƴ��ݸ� GLUT�����ҿ��������Լ��ڲ���ѭ���������ѭ���У����������Դ���ϵͳ���¼���ͨ���������õĻص��������ݸ� GLUT���ڱ������У�GLUTֻ�������Ƕ���������ʾ���ڵĻص�������RenderDisplay������ʹ��������Ⱦ֡��*/
	glutMainLoop();

}


