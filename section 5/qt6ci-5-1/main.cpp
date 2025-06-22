/*

    What
    QList

    Why
    Template container

    How
    Simple example
    Semplice linked list (anche QVector lo sarà)
    include :
        #include <QList>
    definizione :
        template <typename T>
        class QList
    ha un overload sull'insertion operator per cui per appendere
    posso fare lista << el1 << el2 etc;
    chiaramente posso usare anche lista.append(el);
    posso anche appendere un'altra lista di element analoghi
*/

#include <QCoreApplication>
#include <QList>
#include <QDebug>

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);


    QList<int> list;

    //Easy append
    list << 1 << 2 << 3;

    for(int i = 0; i < 5; i++)
    {
        list.append(i);
    }

    qInfo() << list;

    qInfo() << "Length" << list.length();
    qInfo() << "Size" << list.size();
    qInfo() << "Count" << list.count();
    qInfo() << "Count" << list.count(4);

    list.replace(2,99);
    list << 3 << 3 << 3;
    list.remove(3);

    foreach(int i, list)
    {
        qInfo() << i;
    }
    list.removeAll(3);

    for(int i = 0; i < list.length();i++)
    {
        qInfo() << i << "=" << list.at(i);
    }

    QList<int> slice  = list.sliced(2,3);

    qInfo() << "Slice" << slice;
    qInfo() << "List" << list;

    qInfo() << "Contains" << list.contains(6);
    qInfo() << "Indexof" << list.indexOf(6);
    list.clear();

    qInfo() << "Length" << list.length();
    qInfo() << "Size" << list.size();
    qInfo() << "Count" << list.count();


    return a.exec();
}
