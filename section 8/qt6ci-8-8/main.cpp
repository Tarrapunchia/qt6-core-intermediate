/*

  What
  Writing files

  Why
  Put data into a file

  How
  QFile

 */

#include <QCoreApplication>
#include <QFile>
#include <QDateTime>


int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    QString filename = "test.txt"; // this will put it in the current directory

    QFile file(filename);
    if(file.open(QIODevice::Append))
    {
        QString now = QDateTime::currentDateTime().toString();

        QByteArray data;
        data.append(now.toLocal8Bit());
        data.append(" - ");
        data.append("Hello World");
        data.append("\r\n");

        file.write(data);
        file.close();

        qInfo() << "Wrote to the file";
    }
    else
    {
        qInfo() << file.errorString();
    }

    if (file.open(QIODevice::ReadOnly))
    {
        char buf[4096];
        while (file.readLine(buf, 4096) != -1)
        {
            qInfo() << buf;
        }
        file.close();
    }

    // più c like per roba embedded
    if (file.open(QIODevice::ReadOnly | QIODevice::Text)) {
        while (!file.atEnd()) {
            QByteArray line = file.readLine();
            qInfo() << line.trimmed(); // trimmed() rimuove \n e spazi finali
        }
        file.close();
    }

    // più qt idiomatic
    if (file.open(QIODevice::ReadOnly | QIODevice::Text)) {
        QTextStream in(&file);
            in.setEncoding(QStringConverter::Utf8);// importante per file multilingua
        while (!in.atEnd()) {
            QString line = in.readLine(); // già ottimizzato internamente
            qInfo() << line;
        }
        file.close();
    }



    return a.exec();
}
