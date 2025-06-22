/*

  What
  QScopedPointer

  Why
  Manual memory management is error prone

  How
  See below
  Sono puntatori scoped, semplicemente
  Incluso in :
    #include <QScopedPointer>
  dichiarazione :
    template <typename T, typename Cleanup = QScopedPointerDeleter<T>>
    class QScopedPointer {...}

  a questo pounto l'arrow op accede direttamente ai metodi dell'oggetto puntato
  non dello smart ptr come in c++ (non servono get o set via)
*/

#include <QCoreApplication>
#include <QScopedPointer>
#include "test.h"

void test()
{
    QScopedPointer<Test> sp(new Test());
    sp->setObjectName("My Test");

    qInfo() << "Scoped Pointer" << &sp;
    qInfo() << "Pointer Data" << sp.data();
    qInfo() << sp->objectName();

}

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    test();

    return a.exec();
}
