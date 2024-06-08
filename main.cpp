#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QList>
#include <QQmlContext>
#include "ZTwoDimension.h"

class Demo
{
public:
	enum class ClientRole
	{
		Role1,
		Role2,
	};

	QVariant getSys(int role)
	{
		return "name";
	}
	QVariant getUser(ClientRole role)
	{
		return "age";
	}
};

//using TypeDemo = ZTwoDimension<Demo>;

int main(int argc, char* argv[])
{

	//qRegisterMetaType<ZTwoDimension<Demo>>("TypeDemo");

	QGuiApplication app(argc, argv);

	QQmlApplicationEngine engine;

	//auto pdemo = new TypeDemo({}, &app);
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
