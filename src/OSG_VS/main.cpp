#include <stdio.h>
#include <string.h>
#include <windows.h>
#include <stdlib.h>

#include <osgViewer/Viewer>
#include <osgDB/ReadFile>
#include <osgGA/GUIEventAdapter>
#include <osgViewer/ViewerEventHandlers>

#include "CommonLibrary.h"

//ģ��һ���¼��࣬��Ӧ����h
class PrintName :public osgGA::GUIEventHandler
{
public:
	bool handle(const osgGA::GUIEventAdapter &ea, osgGA::GUIActionAdapter &aa)
	{
		return false;
	}
	virtual void getUsage(osg::ApplicationUsage &usage) const
	{
		usage.addKeyboardMouseBinding("hello", "world");
	}
};

int main(int argc, char *argv[])
{
	/*
	����ָ�룺osg::ref_ptr
	*/

	osg::ref_ptr<osgViewer::Viewer> viewer = new osgViewer::Viewer;
	osg::ref_ptr<osg::Node> node = new osg::Node;

	std::string modelFile = "../../bin/data/glider.osg";
	node = osgDB::readNodeFile(modelFile);
	 
	//��Ӱ����¼�
	viewer->addEventHandler(new PrintName);
	viewer->addEventHandler(new osgViewer::HelpHandler);	//h,����
	viewer->addEventHandler(new osgViewer::StatsHandler);	//s,֡��
	viewer->addEventHandler(new osgViewer::WindowSizeHandler);
	viewer->addEventHandler(new osgViewer::ScreenCaptureHandler);

	viewer->setSceneData(node);
	viewer->run();

	return 0;
}
