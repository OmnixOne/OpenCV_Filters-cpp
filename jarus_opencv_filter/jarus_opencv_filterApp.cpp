/***************************************************************
 * Name:      jarus_opencv_filterApp.cpp
 * Purpose:   Code for Application Class
 * Author:    jarus (surajsingh999898@gmail.com)
 * Created:   2019-10-07
 * Copyright: jarus ()
 * License:
 **************************************************************/

#include "wx_pch.h"
#include "jarus_opencv_filterApp.h"

//(*AppHeaders
#include "jarus_opencv_filterMain.h"
#include <wx/image.h>
//*)

IMPLEMENT_APP(jarus_opencv_filterApp);

bool jarus_opencv_filterApp::OnInit()
{
    //(*AppInitialize
    bool wxsOK = true;
    wxInitAllImageHandlers();
    if ( wxsOK )
    {
    	jarus_opencv_filterFrame* Frame = new jarus_opencv_filterFrame(0);
    	Frame->Show();
    	SetTopWindow(Frame);
    }
    //*)
    return wxsOK;

}
        