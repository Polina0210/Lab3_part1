#ifndef STRATEGY_H
#define STRATEGY_H
#include <QObject>

//Структура хранит информацию:
//Имя файла
//Размер файла
//доля в процентах
struct fileSizeInfo{
    QString fileName;
    qint64  size;
    float percent;

    fileSizeInfo(QString name_ = "No path there", qint64 size_ = 0, float percent_ = 0.00){
        fileName = name_;
        size = size_;
        percent = percent_;
    }
};


class Strategy
{
public:
    Strategy() {};
    virtual ~Strategy() {}
    //Считает размер содержимого в папке
    //На вход - строка - путь к папке,
    //Возвращает - имена файлов, размер и долю в процентах
    virtual QList<fileSizeInfo> SizeInfo(const QString &) = 0;
};

#endif // STRATEGY_H
