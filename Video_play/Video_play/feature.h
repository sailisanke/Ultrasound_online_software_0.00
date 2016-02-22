#include <core.hpp>
#include <imgproc.hpp>
#include <highgui.hpp>
#include "video_play.h"

using namespace cv;



const Mat getImageFeature(const Mat & ,const Video_play::parametersSettings & );
const Mat getWindowFeatureMeanVar(const Mat & windowData);
const Mat getWindowFeatureCoefficient(const Mat & windowData);


