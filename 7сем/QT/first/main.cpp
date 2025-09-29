#include <QApplication>
#include <QPushButton>
#include <QLabel>
#include <QDate>
#include <QTime>
#include <QTimer>
#include <QFile>
#include <QBuffer>
#include <QTextStream>
#include <QDebug>

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    int x = 50;   // начальная координата X
    int y = 50;   // начальная координата Y
    int step = 100; // расстояние между элементами
    QSize widgetSize(250, 60); // общий размер для кнопок и меток

    // 1. Кнопка "Hello, World"
    QPushButton helloButton("Hello, World");
    helloButton.resize(widgetSize);
    helloButton.move(x, y);
    helloButton.setWindowTitle("task1");
    helloButton.show();

    // 2. QLabel с указателем
    y += step;
    QLabel *labelWithPointer = new QLabel("Hello, Qt! (с указателем)");
    labelWithPointer->resize(widgetSize);
    labelWithPointer->move(x, y);
    labelWithPointer->setWindowTitle("task2");
    labelWithPointer->show();

    // 3. QLabel без указателя
    y += step;
    QLabel labelWithoutPointer("Hello, Qt! (без указателя)");
    labelWithoutPointer.resize(widgetSize);
    labelWithoutPointer.move(x, y);
    labelWithoutPointer.setWindowTitle("task3");
    labelWithoutPointer.show();

    // 4. Кнопка "Quit"
    y += step;
    QPushButton *quitButton = new QPushButton("Quit");
    quitButton->resize(widgetSize);
    quitButton->move(x, y);
    quitButton->setWindowTitle("task4");
    QObject::connect(quitButton, &QPushButton::clicked, &app, &QApplication::quit);
    quitButton->show();

    // 5. Дата и время
    y += step;
    QDate currentDate = QDate::currentDate();
    QTime currentTime = QTime::currentTime();
    QString dateTimeString = QString("Дата: %1\nВремя: %2")
                                 .arg(currentDate.toString("dd.MM.yyyy"))
                                 .arg(currentTime.toString("hh:mm:ss"));

    QLabel *dateTimeLabel = new QLabel(dateTimeString);
    dateTimeLabel->resize(widgetSize);
    dateTimeLabel->move(x, y);
    dateTimeLabel->setWindowTitle("task5");
    dateTimeLabel->show();

    // 6. Мигающая метка
    y += step;
    QLabel *blinkLabel = new QLabel("Blink");
    blinkLabel->resize(widgetSize);
    blinkLabel->move(x, y);
    blinkLabel->setWindowTitle("task6");
    blinkLabel->show();

    QTimer *timer = new QTimer();
    QObject::connect(timer, &QTimer::timeout, [blinkLabel]() {
        static bool showText = true;
        blinkLabel->setText(showText ? "Blink" : "");
        showText = !showText;
    });
    timer->start(200);

    // 7. Работа с файлами - копирование блоками по 2 символа
    QFile sourceFile("source.bin");
    QFile destFile("destination.bin");

    if (sourceFile.open(QIODevice::ReadOnly) && destFile.open(QIODevice::WriteOnly)) {
        while (!sourceFile.atEnd()) {
            QByteArray buffer = sourceFile.read(2);
            destFile.write(buffer);
        }
        sourceFile.close();
        destFile.close();
        qDebug() << "Файл скопирован блоками по 2 символа";
    } else {
        qDebug() << "Проблема при открытии файла";
    }

    // 8. Копирование с использованием QByteArray
    QFile sourceFile2("source.bin");
    QFile destFile2("destination2.bin");

    if (sourceFile2.open(QIODevice::ReadOnly) && destFile2.open(QIODevice::WriteOnly)) {
        QByteArray fileData = sourceFile2.readAll();
        destFile2.write(fileData);
        sourceFile2.close();
        destFile2.close();
        qDebug() << "Файл скопирован с использованием QByteArray";
    }

    // 9. QBuffer - вывод строки в консоль
    QBuffer buffer;
    buffer.open(QIODevice::WriteOnly);
    buffer.write("Текстовая строка для вывода в консоль");
    buffer.close();

    buffer.open(QIODevice::ReadOnly);
    QTextStream in(&buffer);
    qDebug() << "QBuffer содержимое:" << in.readAll();
    buffer.close();

    // 10. QTextStream - построчное чтение файла
    QFile textFile("textfile.txt");
    if (textFile.open(QIODevice::ReadOnly | QIODevice::Text)) {
        QTextStream textStream(&textFile);
        while (!textStream.atEnd()) {
            QString line = textStream.readLine();
            qDebug() << "Строка:" << line;
        }
        textFile.close();
    }

    // 11. Чтение всего файла и запись с форматированием
    QFile readFile("read.txt");
    QFile writeFile("write.txt");

    if (readFile.open(QIODevice::ReadOnly | QIODevice::Text) &&
        writeFile.open(QIODevice::WriteOnly | QIODevice::Text)) {

        QTextStream readStream(&readFile);
        QTextStream writeStream(&writeFile);

        QString content = readStream.readAll();
        qDebug() << "Все содержимое:" << content;

        writeStream << "Форматированный текст:\n";
        writeStream << "====================\n";
        writeStream << content;
        writeStream << "\n====================\n";
        writeStream << "Конец файла";

        readFile.close();
        writeFile.close();
    }

    return app.exec();
}
