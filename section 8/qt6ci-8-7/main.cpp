/*

  What
  QIODevice

  Why
  QIODevice is the base class of all IO devices

  How
  QBuffer which is a simple IO Device interface for a QByteArray

    1. passo iniziale è l'apertura con .open() del device
 */

#include <QCoreApplication>
#include <QIODevice>
#include <QBuffer>
#include <QDebug>

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    QBuffer buffer;
    if(buffer.open(QIODevice::ReadWrite))
        // [override virtual] bool QBuffer::open(QIODeviceBase::OpenMode mode)
    {
        qInfo() << "Device is open";

        QByteArray data("Hello world");
        for(int i = 0; i < 5; i ++)
        {
            buffer.write(data);
            buffer.write("\r\n");
        }
        // non c'è in un QBuffer perchè è tutto in memoria
        //buffer.flush();

        buffer.seek(0);
        qInfo() << buffer.readAll();

        qInfo() << "Closing buffer...";
        buffer.close();
    }
    else
    {
        qInfo() << "Could not open the device";
    }

    qInfo() << "Finished";

    return a.exec();
}
