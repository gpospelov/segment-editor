#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQmlContext>
#include <QScopedPointer>

#include <segment-editor/segment_model.h>
#include <segment-editor/backend.h>

int main(int argc, char *argv[])
{
  QScopedPointer<mvvm::Backend> backend(new mvvm::Backend);

  QGuiApplication app(argc, argv);

  mvvm::SegmentModel model;
  for(int i=0; i<9; ++i)
  {
    model.addSegment(mvvm::Segment(QString("segment%0").arg(i)));
  }

  QQmlApplicationEngine engine;

  qmlRegisterSingletonInstance("coa.pspseditor.backend", 1, 0, "MyBackend", backend.get());

  engine.rootContext()->setContextProperty("segment_model", &model);
  engine.load(QStringLiteral("qrc:/main.qml"));

  return app.exec();
}
