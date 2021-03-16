#include <QCoreApplication>
#include "Strategy.h"
#include "FolderSrategy.h"
#include "TypeStrategy.h"
#include "math.h"

QString console(QList<fileSizeInfo> info)
{
    QString res;
    for(auto it = info.begin(); it != info.end(); it++)
    {
        res+= it -> fileName + ", size in percents: ";
        if(it->percent < 0.01 && it->percent != 0)
        {
            res += "<0.01%\n";
        }
        else
        {
            res+= QString::number(round((it->percent)*100)/100) + "%\n";
        }
    }
    return res;
}

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    Strategy *choose_strategy;
    QTextStream cout(stdout), cin(stdin);
    QString path("C:/Users/polin/Desktop/Tests/Test1");
    //Цикл для перебора всех тестов
    for(int i = 1; i<6; i++)
    {
        if(i == 5)
        {
            path[33] = QChar('0' + i);
            path.append(".txt");
        }
        else
        {
            path[33] = QChar('0' + i);
        }
        //вывод результатов на консоль
        cout<<path<<endl;
        choose_strategy = new FolderStrategy();
        cout<<"Group by folder:"<<endl;
        cout<<console(choose_strategy->SizeInfo(path))<<endl;
        delete choose_strategy;
        choose_strategy = new TypeStrategy();
        cout<<"Group by type:"<<endl;
        cout<<console(choose_strategy->SizeInfo(path))<<endl;
        delete choose_strategy;

}
    return a.exec();
}
