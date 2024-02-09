#include "singletonclass.h"

SingletonClass::SingletonClass(QObject *parent) : QObject(parent)
{
}

// QJSValue SingletonClass::singletonProvider(QQmlEngine *engine, QJSEngine *scriptEngine)
// {
//     Q_UNUSED(scriptEngine);
//     int mValue = 5;

//     QJSValue jsValue = engine->newObject();
//     jsValue.setProperty("someProperty",mValue);

//     //Put in an array
//     QJSValue mArray = engine->newArray(3);
//     for (unsigned int i = 1; i <= 3; ++i) {
//         mArray.setProperty(i, i*5);
//     }

//     jsValue.setProperty("mArray",mArray);

//     return jsValue;
// }

QJSValue SingletonClass::getJsValue()
{
  auto engine = qmlEngine(this);
  static const int mValue = 5;

  // QJSEngine engine;
  QJSValue jsValue = engine->newObject();
  jsValue.setProperty("someProperty",QJSValue(mValue));

  //Put in an array
  QJSValue mArray = engine->newArray(3);
  for (unsigned int i = 1; i <= 3; ++i) {
    mArray.setProperty(QString::number(i), QJSValue(i*5));
  }

  jsValue.setProperty("mArray",mArray);

  return jsValue;
}
