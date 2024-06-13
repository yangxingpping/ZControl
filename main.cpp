#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QList>
#include <QQmlContext>
#include "ZTwoDimensionImpl.h"
#include "ZTableModelImpl.h"
#include "ZButtonMdelInfo.h"
#include "ZConfig.h"


int main(int argc, char* argv[])
{
	//qRegisterMetaType<ZTwoDimension>("ZTwoDimension");

	QGuiApplication app(argc, argv);
	QQmlEngine* p2 = new QQmlEngine(&app);
	QQmlApplicationEngine engine;
	//ZConfig* pconf = p2->singletonInstance<ZConfig*>("zControl", "ZConfig");
	auto pdemo = new ZTwoDimensionImpl<ZButtonMdelInfo>({}, &app);
	pdemo->_data.push_back(std::make_unique<ZButtonMdelInfo>());
	pdemo->_data.push_back(std::make_unique<ZButtonMdelInfo>());
    pdemo->_data.push_back(std::make_unique<ZButtonMdelInfo>());
    pdemo->_data.push_back(std::make_unique<ZButtonMdelInfo>());
	engine.rootContext()->setContextProperty("abc", pdemo);
	
	auto cc = new ZTableModelImpl<ZButtonMdelInfo>({ {Qt::DisplayRole, "display"} }, &app);
	cc->_data.push_back(std::make_unique<ZButtonMdelInfo>());
	cc->_data.push_back(std::make_unique<ZButtonMdelInfo>());
	cc->_data.push_back(std::make_unique<ZButtonMdelInfo>());
	cc->_data.push_back(std::make_unique<ZButtonMdelInfo>());
	engine.rootContext()->setContextProperty("cc", cc);

	QTimer::singleShot(1000, &app, [&]() {
		//ZConfig* pconf = engine.singletonInstance<ZConfig*>("zControl", "ZConfig");
		//pconf->color({ 0,0,255 });
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
