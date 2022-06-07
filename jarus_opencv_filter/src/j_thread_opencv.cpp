#include "j_thread_opencv.h"

DEFINE_EVENT_TYPE(wxEVT_J_OPENCV)


j_thread_opencv::j_thread_opencv(wxEvtHandler* pParent1, int param1) : wxThread(wxTHREAD_JOINABLE), m_pParent1(pParent1)
{
    m_param1 = param1;
}

void* j_thread_opencv::Entry()
{
    wxCommandEvent mpuEvt(wxEVT_J_OPENCV, GetId());
    //VideoCapture j_webcam("/home/suraj/Desktop/Workbench_Program/diamond_pic_vid/diamond1.avi");
    VideoCapture j_webcam(0);
    j_webcam.set(CV_CAP_PROP_FPS, 1);
    j_webcam.set(CAP_PROP_BUFFERSIZE, 1);

    if(j_webcam.isOpened())
    {
        mpuEvt.SetId(0);
        string error = "can't open camera";
        mpuEvt.SetClientData(error);
        this->Exit();
        //cout << "Error opening video stream" << endl;
    }

    int frame_width = j_webcam.get(CV_CAP_PROP_FRAME_WIDTH);
    int frame_height = j_webcam.get(CV_CAP_PROP_FRAME_HEIGHT);
    int num[2];
    num[0] = frame_width;
    num[1] = frame_height;
    mpuEvt.SetId(0);
    mpuEvt.SetClientData(num);
    wxPostEvent(m_pParent1, mpuEvt);

    mpuEvt.SetId(1);
    Mat global_mat;
    while(true)
    {
        if(this->TestDestroy())
        {
            j_webcam.release();
            this->Exit();
        }

        j_webcam >> global_mat;
        if (!global_mat.empty())
        {
            mpuEvt.SetClientData(&global_mat);
            wxPostEvent(m_pParent1, mpuEvt);
        }
    }
    return 0;

}
