#include "singletonclass.h"

SingletonClass::SingletonClass(QObject *parent) : QObject(parent)
{
}

QJSValue SingletonClass::singletonProvider(QQmlEngine *engine, QJSEngine *scriptEngine)
{
    Q_UNUSED(scriptEngine);
    int mValue = 5;

    QJSValue jsValue = engine->newObject();
    jsValue.setProperty("someProperty",mValue);

    //Put in an array
    QJSValue mArray = engine->newArray(3);
    for (unsigned int i = 1; i <= 3; ++i) {
        mArray.setProperty(i, i*5);
    }

    jsValue.setProperty("mArray",mArray);

    return jsValue;
}
