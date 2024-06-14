#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QList>
#include <QQmlContext>
#include "ZTwoDimensionImpl.h"
#include "ZTableModelImpl.h"
#include "ZButtonMdelInfo.h"
#include "ZTableModelInfo.h"
#include "ZTableModelFinal.h"
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
	
	auto cc = new ZTableModelImpl<ZTableModelInfo>({ {Qt::DisplayRole, "display"}, {Qt::EditRole, "edit"} }, &app);
	cc->_data.push_back(std::make_unique<ZTableModelInfo>());
	cc->_data.push_back(std::make_unique<ZTableModelInfo>());
	cc->_data.push_back(std::make_unique<ZTableModelInfo>());
	cc->_data.push_back(std::make_unique<ZTableModelInfo>());
	engine.rootContext()->setContextProperty("cc1", cc);

	auto dd = new ZTableModelFinal(&app);
	dd->_v.push_back("first");
	dd->_v.push_back("second");
	engine.rootContext()->setContextProperty("cc", dd);

	QTimer::singleShot(3000, &app, [&]() {
		//ZConfig* pconf = engine.singletonInstance<ZConfig*>("zControl", "ZConfig");
		//pconf->color({ 0,0,255 });
		auto indx = cc->index(0, 0);
		cc->setData(indx, "next", Qt::DisplayRole);
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
