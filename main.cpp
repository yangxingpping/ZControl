#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QList>
#include <QQmlContext>
#include "ZTwoDimension.h"
#include "Demo.h"



using TypeDemo = ZTwoDimension<Demo>;

Q_DECLARE_METATYPE(ZTwoDimension<Demo>);

int main(int argc, char* argv[])
{

	qRegisterMetaType<ZTwoDimension<Demo>>("Demo");

	QGuiApplication app(argc, argv);

	QQmlApplicationEngine engine;


	//engine.rootContext()->setContextProperty("abc", pdemo);
	QObject::connect(
		&engine,
		&QQmlApplicationEngine::objectCreationFailed,
		&app,
		[]() { QCoreApplication::exit(-1); },
		Qt::QueuedConnection);
	engine.loadFromModule("zControl", "Main");

	return app.exec();
}
