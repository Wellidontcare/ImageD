/************************************
 *   added:     16.04.2019          *
 *   author:    David Eilenstein    *
 *   contact:   D.Eilenstein@gsi.de *
 *   project:   ImageD              *
 *   facility:  GSI Darmstadt, Ger  *
 ************************************/

#ifndef D_VISDAT_OBJ_H
#define D_VISDAT_OBJ_H

//own
#include <d_enum.h>
#include <d_error_handler.h>
#include <d_visdat_header.h>
#include <d_visdat_dim.h>
#include <d_visdat_range.h>
#include <d_visdat_slice_2d.h>

//Qt
#include <QDateTime>
#include <QString>
#include <QStringList>

//Qt::Charts

//general
#include <iostream>
#include <sstream>
#include <fstream>
#include <vector>
#include <algorithm>

//openCV
#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>

//namespaces
using namespace std;
using namespace cv;

class D_VisDat_Obj
{
public:
    D_VisDat_Obj();
    D_VisDat_Obj(double init_val);
    D_VisDat_Obj(D_VisDat_Dim dim, int mat_typ = CV_8UC1);
    D_VisDat_Obj(D_VisDat_Dim dim, int mat_typ, double init_val);
    D_VisDat_Obj(D_VisDat_Header Header);


    Mat             MA_full         ()                              {return MA_Data;}
    Mat*            pMA_full        ()                              {return &MA_Data;}
    Mat             MA_2dMat        (D_VisDat_Slice_2D Slice_2d);
    Mat             MA_SubMat       (D_VisDat_Range RG);

    int             size_PixelCount ();
    int             size_BitPerPixel();
    int             size_Bit        ();
    int             size_Byte       ();
    D_VisDat_Dim    Dim             ()                              {return VD_Dim;}
    D_VisDat_Dim*   pDim            ()                              {return &VD_Dim;}

    int             type            ()                              {return MA_Type;}

    QString         info            ();
    QString         info_short      ();
    QString         Info_Dims       ();
    QString         Info_Type       (bool more_detail = false);
    QString         Info_TypeDetail ();

    D_VisDat_Dim    VD_Dim;
    Mat             MA_Data;            //6D + Channels
    int             MA_Type = CV_8UC1;

    QString         QS_Name = "VD_obj";

private:

    void            Init(double val = 200);


};

#endif // D_VISDAT_OBJ_H
