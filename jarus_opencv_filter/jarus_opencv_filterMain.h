/***************************************************************
 * Name:      jarus_opencv_filterMain.h
 * Purpose:   Defines Application Frame
 * Author:    jarus (surajsingh999898@gmail.com)
 * Created:   2019-10-07
 * Copyright: jarus ()
 * License:
 **************************************************************/

#ifndef JARUS_OPENCV_FILTERMAIN_H
#define JARUS_OPENCV_FILTERMAIN_H

//(*Headers(jarus_opencv_filterFrame)
#include <wx/sizer.h>
#include <wx/button.h>
#include <wx/menu.h>
#include <wx/radiobut.h>
#include <wx/panel.h>
#include <wx/slider.h>
#include <wx/statusbr.h>
#include <wx/frame.h>
#include <wx/stattext.h>
#include <wx/textctrl.h>
#include <wx/statbmp.h>
//*)

#include "j_thread_opencv.h"
#include <string>
#include <opencv2/opencv.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <iostream>
#include <fstream>
#include <boost/algorithm/string.hpp>

using namespace cv;
using namespace std;

class jarus_opencv_filterFrame: public wxFrame
{
    public:

        jarus_opencv_filterFrame(wxWindow* parent,wxWindowID id = -1);
        virtual ~jarus_opencv_filterFrame();

    private:

        //(*Handlers(jarus_opencv_filterFrame)
        void OnQuit(wxCommandEvent& event);
        void OnAbout(wxCommandEvent& event);
        void OnRadioButton1Select(wxCommandEvent& event);
        void OnTextCtrl1TextEnter(wxCommandEvent& event);
        void OnSlider1CmdScrollChanged(wxScrollEvent& event);
        void Onbtn_saveClick(wxCommandEvent& event);
        void Onbtn_openClick(wxCommandEvent& event);
        void Onbtn_resetClick(wxCommandEvent& event);
        //*)

        //(*Identifiers(jarus_opencv_filterFrame)
        static const long ID_STATICBITMAP1;
        static const long ID_PANEL2;
        static const long ID_TEXTCTRL7;
        static const long ID_BUTTON1;
        static const long ID_BUTTON2;
        static const long ID_BUTTON3;
        static const long ID_STATICTEXT12;
        static const long ID_STATICTEXT10;
        static const long ID_STATICTEXT11;
        static const long ID_STATICTEXT7;
        static const long ID_SLIDER7;
        static const long ID_STATICTEXT9;
        static const long ID_SLIDER8;
        static const long ID_STATICTEXT8;
        static const long ID_SLIDER9;
        static const long ID_RADIOBUTTON1;
        static const long ID_RADIOBUTTON2;
        static const long ID_STATICTEXT1;
        static const long ID_SLIDER1;
        static const long ID_TEXTCTRL1;
        static const long ID_STATICTEXT2;
        static const long ID_SLIDER2;
        static const long ID_TEXTCTRL2;
        static const long ID_STATICTEXT3;
        static const long ID_SLIDER3;
        static const long ID_TEXTCTRL3;
        static const long ID_STATICTEXT4;
        static const long ID_SLIDER4;
        static const long ID_TEXTCTRL5;
        static const long ID_STATICTEXT5;
        static const long ID_SLIDER5;
        static const long ID_TEXTCTRL4;
        static const long ID_STATICTEXT6;
        static const long ID_SLIDER6;
        static const long ID_TEXTCTRL6;
        static const long ID_PANEL3;
        static const long ID_PANEL1;
        static const long idMenuQuit;
        static const long idMenuAbout;
        static const long ID_STATUSBAR1;
        //*)

        //(*Declarations(jarus_opencv_filterFrame)
        wxTextCtrl* text_color6;
        wxButton* btn_reset;
        wxPanel* Panel1;
        wxRadioButton* RadioButton1;
        wxSlider* Slider4;
        wxSlider* Slider3;
        wxStatusBar* StatusBar1;
        wxSlider* Slider8;
        wxStaticText* val_contour;
        wxStaticText* s_col2_StaticText;
        wxStaticText* e_col2_StaticText;
        wxTextCtrl* text_color5;
        wxStaticText* StaticText1;
        wxPanel* Panel2;
        wxSlider* Slider5;
        wxStaticText* e_col3_StaticText;
        wxStaticText* StaticText3;
        wxSlider* Slider9;
        wxButton* btn_save;
        wxStaticText* e_col1_StaticText;
        wxRadioButton* RadioButton2;
        wxPanel* Panel3;
        wxStaticText* s_col1_StaticText;
        wxSlider* Slider7;
        wxTextCtrl* TextCtrl1;
        wxStaticText* StaticText4;
        wxButton* btn_open;
        wxSlider* Slider2;
        wxStaticText* StaticText5;
        wxStaticText* StaticText2;
        wxStaticBitmap* StaticBitmap1;
        wxSlider* Slider1;
        wxStaticText* s_col3_StaticText;
        wxTextCtrl* text_color3;
        wxTextCtrl* text_color4;
        wxSlider* Slider6;
        wxTextCtrl* text_color2;
        wxTextCtrl* text_color1;
        //*)

        int frame_width, frame_height;
        long color_space_value[3];

        bool rgb, hsv, bed;
        int j_blur, j_erode, j_dilate;
        int filter_parameter[18];       // 6(0-5) RGB , 6(6-11) HSV, 6(12-17) BED
        int color_rgb[3];
        int color_hsv[3];
        int color_bed[3];
        bool b_RGB_HSV;

        j_thread_opencv* ptr_opencv_thread;
        Mat apply_filter(Mat src_img);
        void func_opencv_thread(wxCommandEvent& event);

        DECLARE_EVENT_TABLE()
};

#endif // JARUS_OPENCV_FILTERMAIN_H
                        