#include "MainWindow.h"
#include <QtWidgets/QApplication>

#include <osgViewer/Viewer>
#include <osgDB/ReadFile>

#include "CommonLibrary.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

	QString appDir = QCoreApplication::applicationDirPath();

	osgViewer::Viewer viewer;
	osg::Node *node = new osg::Node;

	std::string modelFile = QString(appDir + "/data/" + "glider.osg").toStdString();
	node = osgDB::readNodeFile(modelFile);
	viewer.setSceneData(node);
	viewer.run();

    MainWindow w;
    w.show();
    return a.exec();
	
}
