#include <stdio.h>
#include <string.h>
#include <windows.h>
#include <stdlib.h>

#include <osgViewer/Viewer>
#include <osgDB/ReadFile>

#include "CommonLibrary.h"

int main(int argc, char *argv[])
{
	/*
	≥¨º∂÷∏’Î£∫osg::ref_ptr
	*/

	osg::ref_ptr<osgViewer::Viewer> viewer = new osgViewer::Viewer;
	osg::ref_ptr<osg::Node> node = new osg::Node;

	std::string modelFile = "../../bin/data/glider.osg";
	node = osgDB::readNodeFile(modelFile);
	 
	viewer->setSceneData(node);
	viewer->run();

	return 0;
}
