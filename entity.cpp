#include "entity.h"
#include <QDebug>

entity::entity()
{
    dxf = new dxfRW("file.dxf");
//    exportVersion = DRW::Version;
    if (dxf==NULL) {
        printf("Cannot open file 'myfile.dxf' \
               for writing.");
    }
}

void entity::startDXF(dxfRW *dxf)
{
//    dw->sectionEnd();
//    dw->sectionEntities();
}

void entity::createWall(float l, float h,
                        float x, float y, QString layer, int color,
                        int width, QString lineType)
{
    DRW_Line *line;
    line->basePoint.x = 10;
    line->basePoint.y = 20;
    line->secPoint.x = 30;
    line->secPoint.y = 30;
    qDebug() << line->basePoint.x;

    dxf->writeLine(line);

//    dxf->writeLine(*dw, DL_LineData(x, y, 0.0, x+l, y, 0.0),
//                   DL_Attributes(layer, color, width, lineType));
//    dxf->writeLine(*dw, DL_LineData(x+l, y, 0.0, x+l, y+h, 0.0),
//                   DL_Attributes(layer, color, width, lineType));
//    dxf->writeLine(*dw, DL_LineData(x+l, y+h, 0.0, x, y+h, 0.0),
//                   DL_Attributes(layer, color, width, lineType));
//    dxf->writeLine(*dw, DL_LineData(x, y+h, 0.0, x, y, 0.0),
//                   DL_Attributes(layer, color, width, lineType));
}

void entity::createFlange(dxfRW *dxf, float r, float cx, float cy)
{
//    dxf->writeCircle(*dw, DL_CircleData(cx, cy, 0.0, r),
//                     DL_Attributes("flange", 255, 1, "CONTINUOUS"));
//    dxf->writeCircle(*dw, DL_CircleData(cx, cy, 0.0, r+20),
//                     DL_Attributes("flange", 255, 1, "CONTINUOUS"));
    float theta = 0;
    float radius = 3;
    cy = cy + r - 50;
    cx = cx + r - 30;
    for (int i=0; i<8; i++)
    {
        cx = cx + r * cos(theta);
        cy = cy + r * sin(theta);
//        dxf->writeCircle(*dw, DL_CircleData(cx, cy, 0.0, radius),
//                         DL_Attributes("flange", 255, 1, "CONTINUOUS"));
        theta +=2 * M_PI / 8;
    }
}

void entity::closeDXF()
{
//    dw->sectionEnd();
//    dw->dxfEOF();
//    dw->close();
}

dxfRW* entity::return_dxf(){
    return dxf;
}

//DL_WriterA* entity::return_dw(){
//    return dw;
//}

entity::~entity()
{
//    delete dw;
    delete dxf;
}
