/***************************************************************
 * Name:      jarus_opencv_filterMain.cpp
 * Purpose:   Code for Application Frame
 * Author:    jarus (surajsingh999898@gmail.com)
 * Created:   2019-10-07
 * Copyright: jarus ()
 * License:
 **************************************************************/

#include "wx_pch.h"
#include "jarus_opencv_filterMain.h"
#include <wx/msgdlg.h>

//(*InternalHeaders(jarus_opencv_filterFrame)
#include <wx/string.h>
#include <wx/intl.h>
//*)

//helper functions
enum wxbuildinfoformat {
    short_f, long_f };

wxString wxbuildinfo(wxbuildinfoformat format)
{
    wxString wxbuild(wxVERSION_STRING);

    if (format == long_f )
    {
#if defined(__WXMSW__)
        wxbuild << _T("-Windows");
#elif defined(__UNIX__)
        wxbuild << _T("-Linux");
#endif

#if wxUSE_UNICODE
        wxbuild << _T("-Unicode build");
#else
        wxbuild << _T("-ANSI build");
#endif // wxUSE_UNICODE
    }

    return wxbuild;
}

//(*IdInit(jarus_opencv_filterFrame)
const long jarus_opencv_filterFrame::ID_STATICBITMAP1 = wxNewId();
const long jarus_opencv_filterFrame::ID_PANEL2 = wxNewId();
const long jarus_opencv_filterFrame::ID_TEXTCTRL7 = wxNewId();
const long jarus_opencv_filterFrame::ID_BUTTON1 = wxNewId();
const long jarus_opencv_filterFrame::ID_BUTTON2 = wxNewId();
const long jarus_opencv_filterFrame::ID_BUTTON3 = wxNewId();
const long jarus_opencv_filterFrame::ID_STATICTEXT12 = wxNewId();
const long jarus_opencv_filterFrame::ID_STATICTEXT10 = wxNewId();
const long jarus_opencv_filterFrame::ID_STATICTEXT11 = wxNewId();
const long jarus_opencv_filterFrame::ID_STATICTEXT7 = wxNewId();
const long jarus_opencv_filterFrame::ID_SLIDER7 = wxNewId();
const long jarus_opencv_filterFrame::ID_STATICTEXT9 = wxNewId();
const long jarus_opencv_filterFrame::ID_SLIDER8 = wxNewId();
const long jarus_opencv_filterFrame::ID_STATICTEXT8 = wxNewId();
const long jarus_opencv_filterFrame::ID_SLIDER9 = wxNewId();
const long jarus_opencv_filterFrame::ID_RADIOBUTTON1 = wxNewId();
const long jarus_opencv_filterFrame::ID_RADIOBUTTON2 = wxNewId();
const long jarus_opencv_filterFrame::ID_STATICTEXT1 = wxNewId();
const long jarus_opencv_filterFrame::ID_SLIDER1 = wxNewId();
const long jarus_opencv_filterFrame::ID_TEXTCTRL1 = wxNewId();
const long jarus_opencv_filterFrame::ID_STATICTEXT2 = wxNewId();
const long jarus_opencv_filterFrame::ID_SLIDER2 = wxNewId();
const long jarus_opencv_filterFrame::ID_TEXTCTRL2 = wxNewId();
const long jarus_opencv_filterFrame::ID_STATICTEXT3 = wxNewId();
const long jarus_opencv_filterFrame::ID_SLIDER3 = wxNewId();
const long jarus_opencv_filterFrame::ID_TEXTCTRL3 = wxNewId();
const long jarus_opencv_filterFrame::ID_STATICTEXT4 = wxNewId();
const long jarus_opencv_filterFrame::ID_SLIDER4 = wxNewId();
const long jarus_opencv_filterFrame::ID_TEXTCTRL5 = wxNewId();
const long jarus_opencv_filterFrame::ID_STATICTEXT5 = wxNewId();
const long jarus_opencv_filterFrame::ID_SLIDER5 = wxNewId();
const long jarus_opencv_filterFrame::ID_TEXTCTRL4 = wxNewId();
const long jarus_opencv_filterFrame::ID_STATICTEXT6 = wxNewId();
const long jarus_opencv_filterFrame::ID_SLIDER6 = wxNewId();
const long jarus_opencv_filterFrame::ID_TEXTCTRL6 = wxNewId();
const long jarus_opencv_filterFrame::ID_PANEL3 = wxNewId();
const long jarus_opencv_filterFrame::ID_PANEL1 = wxNewId();
const long jarus_opencv_filterFrame::idMenuQuit = wxNewId();
const long jarus_opencv_filterFrame::idMenuAbout = wxNewId();
const long jarus_opencv_filterFrame::ID_STATUSBAR1 = wxNewId();
//*)

BEGIN_EVENT_TABLE(jarus_opencv_filterFrame,wxFrame)
    //(*EventTable(jarus_opencv_filterFrame)
    //*)
END_EVENT_TABLE()

jarus_opencv_filterFrame::jarus_opencv_filterFrame(wxWindow* parent,wxWindowID id)
{
    //(*Initialize(jarus_opencv_filterFrame)
    wxMenuItem* MenuItem2;
    wxMenuItem* MenuItem1;
    wxFlexGridSizer* FlexGridSizer1;
    wxFlexGridSizer* FlexGridSizer2;
    wxBoxSizer* BoxSizer3;
    wxMenu* Menu1;
    wxBoxSizer* BoxSizer2;
    wxBoxSizer* BoxSizer4;
    wxBoxSizer* BoxSizer1;
    wxMenuBar* MenuBar1;
    wxMenu* Menu2;
    wxBoxSizer* BoxSizer6;
    wxBoxSizer* BoxSizer5;

    Create(parent, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxDEFAULT_FRAME_STYLE, _T("wxID_ANY"));
    SetClientSize(wxSize(1500,1000));
    BoxSizer1 = new wxBoxSizer(wxHORIZONTAL);
    Panel1 = new wxPanel(this, ID_PANEL1, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL, _T("ID_PANEL1"));
    BoxSizer2 = new wxBoxSizer(wxHORIZONTAL);
    Panel2 = new wxPanel(Panel1, ID_PANEL2, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL, _T("ID_PANEL2"));
    Panel2->SetBackgroundColour(wxColour(78,228,224));
    StaticBitmap1 = new wxStaticBitmap(Panel2, ID_STATICBITMAP1, wxNullBitmap, wxPoint(16,0), wxDefaultSize, wxSIMPLE_BORDER, _T("ID_STATICBITMAP1"));
    StaticBitmap1->SetBackgroundColour(wxColour(233,38,50));
    BoxSizer2->Add(Panel2, 2, wxALL|wxEXPAND, 5);
    Panel3 = new wxPanel(Panel1, ID_PANEL3, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL, _T("ID_PANEL3"));
    Panel3->SetBackgroundColour(wxColour(179,215,225));
    BoxSizer3 = new wxBoxSizer(wxVERTICAL);
    BoxSizer6 = new wxBoxSizer(wxHORIZONTAL);
    TextCtrl1 = new wxTextCtrl(Panel3, ID_TEXTCTRL7, _("Text"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_TEXTCTRL7"));
    BoxSizer6->Add(TextCtrl1, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    btn_save = new wxButton(Panel3, ID_BUTTON1, _("save"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_BUTTON1"));
    BoxSizer6->Add(btn_save, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    btn_open = new wxButton(Panel3, ID_BUTTON2, _("open"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_BUTTON2"));
    BoxSizer6->Add(btn_open, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    btn_reset = new wxButton(Panel3, ID_BUTTON3, _("Reset"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_BUTTON3"));
    BoxSizer6->Add(btn_reset, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    BoxSizer3->Add(BoxSizer6, 1, wxALL|wxEXPAND, 5);
    BoxSizer5 = new wxBoxSizer(wxHORIZONTAL);
    StaticText5 = new wxStaticText(Panel3, ID_STATICTEXT12, _("temp"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT12"));
    BoxSizer5->Add(StaticText5, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    StaticText4 = new wxStaticText(Panel3, ID_STATICTEXT10, _("Total contour:- "), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT10"));
    BoxSizer5->Add(StaticText4, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    val_contour = new wxStaticText(Panel3, ID_STATICTEXT11, _("0"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT11"));
    BoxSizer5->Add(val_contour, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    BoxSizer3->Add(BoxSizer5, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    FlexGridSizer2 = new wxFlexGridSizer(3, 2, 0, 0);
    FlexGridSizer2->AddGrowableCol(1);
    StaticText1 = new wxStaticText(Panel3, ID_STATICTEXT7, _("Blur"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT7"));
    FlexGridSizer2->Add(StaticText1, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    Slider7 = new wxSlider(Panel3, ID_SLIDER7, 0, 0, 100, wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_SLIDER7"));
    FlexGridSizer2->Add(Slider7, 1, wxALL|wxEXPAND, 5);
    StaticText3 = new wxStaticText(Panel3, ID_STATICTEXT9, _("Erode"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT9"));
    FlexGridSizer2->Add(StaticText3, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    Slider8 = new wxSlider(Panel3, ID_SLIDER8, 0, 0, 20, wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_SLIDER8"));
    FlexGridSizer2->Add(Slider8, 1, wxALL|wxEXPAND, 5);
    StaticText2 = new wxStaticText(Panel3, ID_STATICTEXT8, _("Dilate"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT8"));
    FlexGridSizer2->Add(StaticText2, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    Slider9 = new wxSlider(Panel3, ID_SLIDER9, 0, 0, 20, wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_SLIDER9"));
    FlexGridSizer2->Add(Slider9, 1, wxALL|wxEXPAND, 5);
    BoxSizer3->Add(FlexGridSizer2, 1, wxALL|wxEXPAND, 5);
    BoxSizer4 = new wxBoxSizer(wxHORIZONTAL);
    RadioButton1 = new wxRadioButton(Panel3, ID_RADIOBUTTON1, _("RGB"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_RADIOBUTTON1"));
    BoxSizer4->Add(RadioButton1, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    RadioButton2 = new wxRadioButton(Panel3, ID_RADIOBUTTON2, _("HSV"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_RADIOBUTTON2"));
    BoxSizer4->Add(RadioButton2, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    BoxSizer3->Add(BoxSizer4, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    FlexGridSizer1 = new wxFlexGridSizer(6, 3, 0, 0);
    FlexGridSizer1->AddGrowableCol(1);
    s_col1_StaticText = new wxStaticText(Panel3, ID_STATICTEXT1, _("s_RED"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT1"));
    FlexGridSizer1->Add(s_col1_StaticText, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    Slider1 = new wxSlider(Panel3, ID_SLIDER1, 0, 0, 255, wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_SLIDER1"));
    FlexGridSizer1->Add(Slider1, 5, wxALL|wxEXPAND, 5);
    text_color1 = new wxTextCtrl(Panel3, ID_TEXTCTRL1, _("0"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_TEXTCTRL1"));
    FlexGridSizer1->Add(text_color1, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    e_col1_StaticText = new wxStaticText(Panel3, ID_STATICTEXT2, _("e_RED"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT2"));
    FlexGridSizer1->Add(e_col1_StaticText, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    Slider2 = new wxSlider(Panel3, ID_SLIDER2, 255, 0, 255, wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_SLIDER2"));
    FlexGridSizer1->Add(Slider2, 1, wxALL|wxEXPAND, 5);
    text_color2 = new wxTextCtrl(Panel3, ID_TEXTCTRL2, _("0"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_TEXTCTRL2"));
    FlexGridSizer1->Add(text_color2, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    s_col2_StaticText = new wxStaticText(Panel3, ID_STATICTEXT3, _("s_GRE"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT3"));
    FlexGridSizer1->Add(s_col2_StaticText, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    Slider3 = new wxSlider(Panel3, ID_SLIDER3, 0, 0, 255, wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_SLIDER3"));
    FlexGridSizer1->Add(Slider3, 1, wxALL|wxEXPAND, 5);
    text_color3 = new wxTextCtrl(Panel3, ID_TEXTCTRL3, _("0"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_TEXTCTRL3"));
    FlexGridSizer1->Add(text_color3, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    e_col2_StaticText = new wxStaticText(Panel3, ID_STATICTEXT4, _("e_GRE"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT4"));
    FlexGridSizer1->Add(e_col2_StaticText, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    Slider4 = new wxSlider(Panel3, ID_SLIDER4, 255, 0, 255, wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_SLIDER4"));
    FlexGridSizer1->Add(Slider4, 1, wxALL|wxEXPAND, 5);
    text_color4 = new wxTextCtrl(Panel3, ID_TEXTCTRL5, _("0"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_TEXTCTRL5"));
    FlexGridSizer1->Add(text_color4, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    s_col3_StaticText = new wxStaticText(Panel3, ID_STATICTEXT5, _("s_BLU"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT5"));
    FlexGridSizer1->Add(s_col3_StaticText, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    Slider5 = new wxSlider(Panel3, ID_SLIDER5, 0, 0, 255, wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_SLIDER5"));
    FlexGridSizer1->Add(Slider5, 1, wxALL|wxEXPAND, 5);
    text_color5 = new wxTextCtrl(Panel3, ID_TEXTCTRL4, _("0"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_TEXTCTRL4"));
    FlexGridSizer1->Add(text_color5, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    e_col3_StaticText = new wxStaticText(Panel3, ID_STATICTEXT6, _("e_BLU"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT6"));
    FlexGridSizer1->Add(e_col3_StaticText, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    Slider6 = new wxSlider(Panel3, ID_SLIDER6, 255, 0, 255, wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_SLIDER6"));
    FlexGridSizer1->Add(Slider6, 1, wxALL|wxEXPAND, 5);
    text_color6 = new wxTextCtrl(Panel3, ID_TEXTCTRL6, _("0"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_TEXTCTRL6"));
    FlexGridSizer1->Add(text_color6, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    BoxSizer3->Add(FlexGridSizer1, 0, wxEXPAND, 5);
    Panel3->SetSizer(BoxSizer3);
    BoxSizer3->Fit(Panel3);
    BoxSizer3->SetSizeHints(Panel3);
    BoxSizer2->Add(Panel3, 1, wxALL|wxEXPAND, 5);
    Panel1->SetSizer(BoxSizer2);
    BoxSizer2->Fit(Panel1);
    BoxSizer2->SetSizeHints(Panel1);
    BoxSizer1->Add(Panel1, 1, wxALL|wxEXPAND, 5);
    SetSizer(BoxSizer1);
    MenuBar1 = new wxMenuBar();
    Menu1 = new wxMenu();
    MenuItem1 = new wxMenuItem(Menu1, idMenuQuit, _("Quit\tAlt-F4"), _("Quit the application"), wxITEM_NORMAL);
    Menu1->Append(MenuItem1);
    MenuBar1->Append(Menu1, _("&File"));
    Menu2 = new wxMenu();
    MenuItem2 = new wxMenuItem(Menu2, idMenuAbout, _("About\tF1"), _("Show info about this application"), wxITEM_NORMAL);
    Menu2->Append(MenuItem2);
    MenuBar1->Append(Menu2, _("Help"));
    SetMenuBar(MenuBar1);
    StatusBar1 = new wxStatusBar(this, ID_STATUSBAR1, 0, _T("ID_STATUSBAR1"));
    int __wxStatusBarWidths_1[1] = { -1 };
    int __wxStatusBarStyles_1[1] = { wxSB_NORMAL };
    StatusBar1->SetFieldsCount(1,__wxStatusBarWidths_1);
    StatusBar1->SetStatusStyles(1,__wxStatusBarStyles_1);
    SetStatusBar(StatusBar1);
    SetSizer(BoxSizer1);
    Layout();

    Connect(ID_BUTTON1,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&jarus_opencv_filterFrame::Onbtn_saveClick);
    Connect(ID_BUTTON2,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&jarus_opencv_filterFrame::Onbtn_openClick);
    Connect(ID_BUTTON3,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&jarus_opencv_filterFrame::Onbtn_resetClick);
    Connect(ID_SLIDER7,wxEVT_COMMAND_SLIDER_UPDATED,(wxObjectEventFunction)&jarus_opencv_filterFrame::OnSlider1CmdScrollChanged);
    Connect(ID_SLIDER8,wxEVT_COMMAND_SLIDER_UPDATED,(wxObjectEventFunction)&jarus_opencv_filterFrame::OnSlider1CmdScrollChanged);
    Connect(ID_SLIDER9,wxEVT_COMMAND_SLIDER_UPDATED,(wxObjectEventFunction)&jarus_opencv_filterFrame::OnSlider1CmdScrollChanged);
    Connect(ID_RADIOBUTTON1,wxEVT_COMMAND_RADIOBUTTON_SELECTED,(wxObjectEventFunction)&jarus_opencv_filterFrame::OnRadioButton1Select);
    Connect(ID_RADIOBUTTON2,wxEVT_COMMAND_RADIOBUTTON_SELECTED,(wxObjectEventFunction)&jarus_opencv_filterFrame::OnRadioButton1Select);
    Connect(ID_SLIDER1,wxEVT_COMMAND_SLIDER_UPDATED,(wxObjectEventFunction)&jarus_opencv_filterFrame::OnSlider1CmdScrollChanged);
    Connect(ID_SLIDER2,wxEVT_COMMAND_SLIDER_UPDATED,(wxObjectEventFunction)&jarus_opencv_filterFrame::OnSlider1CmdScrollChanged);
    Connect(ID_SLIDER3,wxEVT_COMMAND_SLIDER_UPDATED,(wxObjectEventFunction)&jarus_opencv_filterFrame::OnSlider1CmdScrollChanged);
    Connect(ID_SLIDER4,wxEVT_COMMAND_SLIDER_UPDATED,(wxObjectEventFunction)&jarus_opencv_filterFrame::OnSlider1CmdScrollChanged);
    Connect(ID_SLIDER5,wxEVT_COMMAND_SLIDER_UPDATED,(wxObjectEventFunction)&jarus_opencv_filterFrame::OnSlider1CmdScrollChanged);
    Connect(ID_SLIDER6,wxEVT_COMMAND_SLIDER_UPDATED,(wxObjectEventFunction)&jarus_opencv_filterFrame::OnSlider1CmdScrollChanged);
    Connect(idMenuQuit,wxEVT_COMMAND_MENU_SELECTED,(wxObjectEventFunction)&jarus_opencv_filterFrame::OnQuit);
    Connect(idMenuAbout,wxEVT_COMMAND_MENU_SELECTED,(wxObjectEventFunction)&jarus_opencv_filterFrame::OnAbout);
    //*)
    Connect(idMenuAbout,wxEVT_COMMAND_MENU_SELECTED,(wxObjectEventFunction)&jarus_opencv_filterFrame::OnAbout);

    ptr_opencv_thread = new j_thread_opencv(this, 5);
    ptr_opencv_thread->Create();
    ptr_opencv_thread->Run();
    Connect(wxID_ANY, wxEVT_J_OPENCV, wxCommandEventHandler(jarus_opencv_filterFrame::func_opencv_thread));
    for (int myLoop = 0; myLoop < 18; myLoop++)
    {
        filter_parameter[myLoop] = 0;
    }

    j_erode = 0;
    j_dilate = 0;
    rgb = true;
    hsv = false;
    bed = false;




}

jarus_opencv_filterFrame::~jarus_opencv_filterFrame()
{
    ptr_opencv_thread->Delete();
    ptr_opencv_thread->Wait();
    delete ptr_opencv_thread;
    //(*Destroy(jarus_opencv_filterFrame)
    //*)
}

void jarus_opencv_filterFrame::OnQuit(wxCommandEvent& event)
{
    Close();
}

void jarus_opencv_filterFrame::OnAbout(wxCommandEvent& event)
{
    wxString msg = wxbuildinfo(long_f);
    wxMessageBox(msg, _("Welcome to..."));
}
string type2str(int type) {
  string r;

  uchar depth = type & CV_MAT_DEPTH_MASK;
  uchar chans = 1 + (type >> CV_CN_SHIFT);

  switch ( depth ) {
    case CV_8U:  r = "8U"; break;
    case CV_8S:  r = "8S"; break;
    case CV_16U: r = "16U"; break;
    case CV_16S: r = "16S"; break;
    case CV_32S: r = "32S"; break;
    case CV_32F: r = "32F"; break;
    case CV_64F: r = "64F"; break;
    default:     r = "User"; break;
  }

  r += "C";
  r += (chans+'0');

  return r;
}
Mat jarus_opencv_filterFrame::apply_filter(Mat src_img)
{
    Mat blur_img;
    blur( src_img, blur_img, Size(1+j_blur,1+j_blur), Point(-1, -1));

    Mat colorspace_changed;
    Mat inRangeImage;

    if(rgb)
    {
        colorspace_changed = blur_img;
    }
    else if(hsv)
    {
        cvtColor(blur_img, colorspace_changed, CV_BGR2HSV);
    }
    inRange(colorspace_changed,  Scalar(Slider1->GetValue(),Slider3->GetValue(),Slider5->GetValue()),
                                 Scalar(Slider2->GetValue(),Slider4->GetValue(),Slider6->GetValue()),  inRangeImage);
   //Threshold -> adaptive, normal, inRange


    int ero_dil_type[2] = {MORPH_ELLIPSE, MORPH_ELLIPSE};
    int ero_dil_size[2] = {0, 0};

    ero_dil_size[0] = j_erode;
    ero_dil_size[1] = j_dilate;

    Mat matDilate, matErode;
    Mat element = getStructuringElement( ero_dil_type[0],
                                     Size( 2*ero_dil_size[0] + 1, 2*ero_dil_size[0]+1 ),
                                     Point( ero_dil_size[0], ero_dil_size[0] ) );

    erode(inRangeImage, matErode, element);
    element = getStructuringElement( ero_dil_type[1],
                                     Size( 2*ero_dil_size[1] + 1, 2*ero_dil_size[1]+1 ),
                                     Point( ero_dil_size[1], ero_dil_size[1] ) );

    dilate(matErode, matDilate, element);

//  StaticText1->SetLabel(  type2str(dst.type()) );
//  object shoule be white and bcackgrung black
//  find some method for inverting image



  Mat img_gray = matDilate;
  for (int x = 0; x < img_gray.size().width; x++)
  {
    for (int y = 0; y < img_gray.size().height; y++)
    {
      Scalar intensity = img_gray.at<uchar>(Point(x, y));
      img_gray.at<uchar>(Point(x, y)) = 255 - img_gray.at<uchar>(Point(x, y));
    }
  }

    Mat src = img_gray;

    vector<vector<Point> > contours;
    vector<Vec4i> hierarchy;

    findContours( src, contours, hierarchy, CV_RETR_CCOMP, CV_CHAIN_APPROX_SIMPLE );
    val_contour->SetLabel(  to_string(  contours.size() ));

    vector<Moments> mu( contours.size() );  for( int i = 0; i < contours.size(); i++ )  { mu[i] = moments( contours[i], false ); }
    vector<Point2f> mc( contours.size() );  for( int i = 0; i < contours.size(); i++ )  { mc[i] = Point2f( mu[i].m10/mu[i].m00 , mu[i].m01/mu[i].m00 ); }

    Mat dst = Mat::zeros(img_gray.size(), CV_8UC1);
    Scalar color = Scalar( 255, 255, 255);
    for( size_t i = 0; i< contours.size(); i++ )
    {
        drawContours( dst, contours, (int)i, color, 2, LINE_8, hierarchy, 0 );
        circle( dst, mc[i], 4, color, -1, 8, 0 );

        if(i == 1)
        {
            string str = to_string((int)mc[1].y) + " " +to_string((int)mc[1].x);
            StaticText5->SetLabel(str);
        }
    }

    Mat cgray;
    cvtColor(dst, cgray, CV_GRAY2BGR);

    Mat mat_return;
    vconcat(src_img, cgray, mat_return);
    return mat_return;
}
void jarus_opencv_filterFrame::func_opencv_thread(wxCommandEvent& event)
{
    if(event.GetId() == 0)
    {
        int *num1 = (int*)event.GetClientData();
        frame_width = num1[0];
        frame_height = num1[1];
    }
    else
    {
        Mat *frame = (Mat*) event.GetClientData();
        Mat filterd = apply_filter(*frame);
        Mat bitmap_mat;
        cvtColor(filterd , bitmap_mat, COLOR_BGR2RGB);

        wxImage Image( frame_width, 2*frame_height, bitmap_mat.data, TRUE );
        wxSize panel_size = Panel2->GetSize();
        Image.Rescale( panel_size.GetWidth(), panel_size.GetHeight()); //panel_size.GetHeight()/j_ratio//int j_ratio; j_ratio = frame_height / frame_width ;
        StaticBitmap1->SetBitmap(Image);
    }
}

void jarus_opencv_filterFrame::OnRadioButton1Select(wxCommandEvent& event)
{
    rgb = RadioButton1->GetValue();
    hsv = RadioButton2->GetValue();

    if( rgb )
    {
        s_col1_StaticText->SetLabel("s_RED");
        e_col1_StaticText->SetLabel("e_RED");

        s_col2_StaticText->SetLabel("s_GREEN");
        e_col2_StaticText->SetLabel("e_GREEN");

        s_col3_StaticText->SetLabel("s_BLUE");
        e_col3_StaticText->SetLabel("e_BLUE");
    }
    if( hsv )
    {
        s_col1_StaticText->SetLabel("s_HUE");
        e_col1_StaticText->SetLabel("e_HUE");

        s_col2_StaticText->SetLabel("s_SAT");
        e_col2_StaticText->SetLabel("e_SAT");

        s_col3_StaticText->SetLabel("s_LIGHT");
        e_col3_StaticText->SetLabel("e_LIGHT");
    }

}

void jarus_opencv_filterFrame::OnTextCtrl1TextEnter(wxCommandEvent& event)
{

/*
    if( text_color1->GetValue().ToLong( &color_space_value[0]  )) { Slider1->SetValue(  (int) color_space_value[0]  ); }
    if( text_color2->GetValue().ToLong( &color_space_value[1]  )) { Slider2->SetValue(  (int) color_space_value[1]  ); }
    if( text_color3->GetValue().ToLong( &color_space_value[2]  )) { Slider3->SetValue(  (int) color_space_value[2]  ); }
*/
}

void jarus_opencv_filterFrame::OnSlider1CmdScrollChanged(wxScrollEvent& event)
{

    int num = 0;

    if(rgb)
    {
        num = 0;
        text_color1->SetValue(  to_string(  filter_parameter[num + 0] = Slider1->GetValue() )  );
        text_color2->SetValue(  to_string(  filter_parameter[num + 1] = Slider2->GetValue() )  );
        text_color3->SetValue(  to_string(  filter_parameter[num + 2] = Slider3->GetValue() )  );
        text_color4->SetValue(  to_string(  filter_parameter[num + 3] = Slider4->GetValue() )  );
        text_color5->SetValue(  to_string(  filter_parameter[num + 4] = Slider5->GetValue() )  );
        text_color6->SetValue(  to_string(  filter_parameter[num + 5] = Slider6->GetValue() )  );
    }
    else if (hsv)
    {
        num = 6;
        text_color1->SetValue(  to_string(  filter_parameter[num + 0] = Slider1->GetValue() )  );
        text_color2->SetValue(  to_string(  filter_parameter[num + 1] = Slider2->GetValue() )  );
        text_color3->SetValue(  to_string(  filter_parameter[num + 2] = Slider3->GetValue() )  );
        text_color4->SetValue(  to_string(  filter_parameter[num + 3] = Slider4->GetValue() )  );
        text_color5->SetValue(  to_string(  filter_parameter[num + 4] = Slider5->GetValue() )  );
        text_color6->SetValue(  to_string(  filter_parameter[num + 5] = Slider6->GetValue() )  );

    }
    j_blur  = Slider7->GetValue();
    j_erode = Slider8->GetValue();
    j_dilate= Slider9->GetValue();



    /*
    color_space_value[0] =
    color_space_value[1] = Slider2->GetValue();
    color_space_value[2] = Slider3->GetValue();

    text_color1->SetValue(  to_string(color_space_value[0])  );
    text_color2->SetValue(  to_string(color_space_value[1])  );
    text_color3->SetValue(  to_string(color_space_value[2])  );
*/
}


void jarus_opencv_filterFrame::Onbtn_openClick(wxCommandEvent& event)
{


    wxString direc = TextCtrl1->GetLabelText();
    direc = "jarus.j";
    ifstream myfile;
    myfile.open(direc);
    if (!myfile.is_open())
    {
        cout << "jarus:- Error opening file" << endl; //return 0;
    }
    else
    {

        string str_filter_values;
        myfile >> str_filter_values;
        myfile.close();
        TextCtrl1->ChangeValue(str_filter_values);

        vector<string> parameters;
        boost::split(parameters, str_filter_values, boost::is_any_of(","));


        Slider1->SetValue(stoi( parameters[0] ));
        Slider2->SetValue(stoi( parameters[1] ));

        Slider3->SetValue(stoi( parameters[2] ));
        Slider4->SetValue(stoi( parameters[3] ));

        Slider5->SetValue(stoi( parameters[4] ));
        Slider6->SetValue(stoi( parameters[5] ));

        Slider7->SetValue(stoi( parameters[6] ));
        Slider8->SetValue(stoi( parameters[7] ));
        Slider9->SetValue(stoi( parameters[8] ));

    }



}

void jarus_opencv_filterFrame::Onbtn_saveClick(wxCommandEvent& event)
{
    ofstream myfile;
    myfile.open("jarus.j");
    if (!myfile.is_open()) {/*problem found*/}

    string str_filter_values =
          to_string(Slider1->GetValue()) + "," +
          to_string(Slider2->GetValue()) + "," +
          to_string(Slider3->GetValue()) + "," +
          to_string(Slider4->GetValue()) + "," +
          to_string(Slider5->GetValue()) + "," +
          to_string(Slider6->GetValue()) + "," +
          to_string(Slider7->GetValue()) + "," +
          to_string(Slider8->GetValue()) + "," +
          to_string(Slider9->GetValue());
    myfile << str_filter_values;
    myfile.close();
}

void jarus_opencv_filterFrame::Onbtn_resetClick(wxCommandEvent& event)
{
    Slider1->SetValue(0);
    Slider2->SetValue(255);
    Slider3->SetValue(0);
    Slider4->SetValue(255);
    Slider5->SetValue(0);
    Slider6->SetValue(255);

    Slider7->SetValue(2);
    Slider8->SetValue(2);
    Slider9->SetValue(2);
}
