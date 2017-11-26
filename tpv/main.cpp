#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include "parser.h"
#include <QFile>
#include <QTextStream>
#include <QQuickView>
#include <QStringList>

#include <qqmlengine.h>
#include <qqmlcontext.h>
#include <qqml.h>
#include <QtQuick/qquickitem.h>
#include <QtQuick/qquickview.h>



int main(int argc, char ** argv)
{
    QGuiApplication app(argc, argv);

    Parser parsejador;

    QStringList resultat = parsejador.myParser();

    QQuickView view;
    QQmlContext *ctxt = view.rootContext();
    ctxt->setContextProperty("dadesParser", QVariant::fromValue(resultat));

    view.setSource(QUrl("qrc:main.qml"));
    view.show();

    return app.exec();
}
