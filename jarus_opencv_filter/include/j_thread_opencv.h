#ifndef J_THREAD_OPENCV_H
#define J_THREAD_OPENCV_H


#include <opencv2/opencv.hpp>
#include <opencv2/imgproc/imgproc.hpp>
using namespace cv;
using namespace std;

BEGIN_DECLARE_EVENT_TYPES()
DECLARE_EVENT_TYPE(wxEVT_J_OPENCV, -1)
END_DECLARE_EVENT_TYPES()

class j_thread_opencv : public wxThread
{
    public:
        j_thread_opencv(wxEvtHandler* pParent1, int param1);
        wxEvtHandler* m_pParent1;
    protected:

    private:
        int m_param1;
        void* Entry();
};

#endif // J_THREAD_OPENCV_H
