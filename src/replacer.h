#ifndef REPLACER_H
#define REPLACER_H

#include <QClipboard>
#include <QGuiApplication>
#include <QString>

class Replacer : public QObject
{
public:
    Replacer();

    void startListening(QString before, QString after, bool deleteEnter);
    void stopListening();

private:
    QClipboard *clipboard;
};

#endif // REPLACER_H
