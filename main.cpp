#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QList>
#include <QQmlContext>
#include "ZTwoDimensionImpl.h"
#include "ZButtonMdelInfo.h"
#include "ZConfig.h"


int main(int argc, char* argv[])
{
	//qRegisterMetaType<ZTwoDimension>("ZTwoDimension");

	QGuiApplication app(argc, argv);

	QQmlApplicationEngine engine;

	auto pdemo = new ZTwoDimensionImpl<ZButtonMdelInfo>({}, &app);
	pdemo->_data.push_back(std::make_unique<ZButtonMdelInfo>());
	pdemo->_data.push_back(std::make_unique<ZButtonMdelInfo>());
    pdemo->_data.push_back(std::make_unique<ZButtonMdelInfo>());
    pdemo->_data.push_back(std::make_unique<ZButtonMdelInfo>());
	engine.rootContext()->setContextProperty("abc", pdemo);

	QTimer::singleShot(3000, &app, [&]() {
		ZConfig* pconf = engine.singletonInstance<ZConfig*>("zControl", "ZConfig");
		pconf->color({ 0,0,255 });
		int i = 1;
		});

	QObject::connect(
		&engine,
		&QQmlApplicationEngine::objectCreationFailed,
		&app,
		[]() { QCoreApplication::exit(-1); },
		Qt::QueuedConnection);
	engine.loadFromModule("zControl", "Main");

	return app.exec();
}
