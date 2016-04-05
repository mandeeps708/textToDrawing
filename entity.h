#ifndef ENTITY_H
#define ENTITY_H

#include <libdxfrw0/libdxfrw.h>
#include <QString>
#include <stdio.h>
#include <qmath.h>

class entity
{
public:
    entity();
    ~entity();
    void createWall(float, float, float, float,
                    QString, int, int, QString);
    //void createFlower(dxfRW *, DL_WriterA*, float, float, float);
    void createFlange(dxfRW *, float, float, float);
    void startDXF(dxfRW *);
    void closeDXF();

    dxfRW *return_dxf();
//    DL_WriterA *return_dw();

    dxfRW *dxf;
    DRW::Version exportVersion;
//    DL_WriterA* dw;
};

#endif // ENTITY_H
