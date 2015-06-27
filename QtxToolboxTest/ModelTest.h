#ifndef INITEST_H
#define INITEST_H

#include <QObject>

class ModelTest : public QObject
{
    Q_OBJECT

public:
     explicit ModelTest(QObject *parent = 0);

 private slots:
     void FirstTest();

};

#endif // INITEST_H
