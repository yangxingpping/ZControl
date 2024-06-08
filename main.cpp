#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QList>
#include <QQmlContext>
#include "ZTwoDimensionImpl.h"
#include "Demo.h"



int main(int argc, char* argv[])
{


	QGuiApplication app(argc, argv);

	QQmlApplicationEngine engine;

	auto pdemo = new ZTwoDimensionImpl<Demo>({}, &app);
	pdemo->_data.insert({ 0, std::make_unique<Demo>() });
	pdemo->_data.insert({ 1, std::make_unique<Demo>() });
	engine.rootContext()->setContextProperty("abc", pdemo);
	QObject::connect(
		&engine,
		&QQmlApplicationEngine::objectCreationFailed,
		&app,
		[]() { QCoreApplication::exit(-1); },
		Qt::QueuedConnection);
	engine.loadFromModule("zControl", "Main");

	return app.exec();
}
