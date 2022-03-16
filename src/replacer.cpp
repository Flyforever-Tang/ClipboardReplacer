#include "replacer.h"

Replacer::Replacer()
{
    clipboard = QGuiApplication::clipboard();
}

void Replacer::startListening(QString before, QString after, bool deleteEnter)
{
    auto replaceLambda = [=]()
    {
        static QString lastStr = "";

        if(clipboard->text() == "" || clipboard->text() == lastStr)
        {
            return;
        }

        QString text = clipboard->text();
        text = text.replace(before, after);

        if(deleteEnter)
        {
            text = text.replace("\n", " ");
        }

        lastStr = text;
        clipboard->setText(text);
    };

    disconnect(clipboard, &QClipboard::dataChanged, this, nullptr);
    connect(clipboard, &QClipboard::dataChanged, this, replaceLambda, Qt::QueuedConnection);
}

void Replacer::stopListening()
{
    disconnect(clipboard, &QClipboard::dataChanged, this, nullptr);
}
