#include <stdio.h>
#include <string.h>
#include <windows.h>
#include <stdlib.h>

#include <osgViewer/Viewer>
#include <osgDB/ReadFile>
#include <osgGA/GUIEventAdapter>
#include <osgViewer/ViewerEventHandlers>

#include "CommonLibrary.h"

//模拟一个事件类，响应单击h
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
	超级指针：osg::ref_ptr
	*/

	osg::ref_ptr<osgViewer::Viewer> viewer = new osgViewer::Viewer;
	osg::ref_ptr<osg::Node> node = new osg::Node;

	std::string modelFile = "../../bin/data/glider.osg";
	node = osgDB::readNodeFile(modelFile);
	 
	//添加帮助事件
	viewer->addEventHandler(new PrintName);
	viewer->addEventHandler(new osgViewer::HelpHandler);	//h,帮助
	viewer->addEventHandler(new osgViewer::StatsHandler);	//s,帧速
	viewer->addEventHandler(new osgViewer::WindowSizeHandler);
	viewer->addEventHandler(new osgViewer::ScreenCaptureHandler);

	viewer->setSceneData(node);
	viewer->run();

	return 0;
}
