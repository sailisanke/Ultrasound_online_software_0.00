#include "feature.h"

const Mat getImageFeature(const Mat & grayImage, const Video_play::parametersSettings & currentParametersSettings)
{
	
	int imageColumnDistance = grayImage.cols/(currentParametersSettings.channelNumber + 1);
	int step = currentParametersSettings.windowLength-currentParametersSettings.overlap;
	int windowNumber = (grayImage.rows - currentParametersSettings.windowLength)/step + 1;
	Mat currentImageFeature( 2 * windowNumber,currentParametersSettings.channelNumber,CV_64FC1);
	for (int i = 0; i < currentParametersSettings.channelNumber; i ++)
	{
		int channelPosition = imageColumnDistance * (i + 1);
		Mat currentColumnData = grayImage.col(channelPosition);
		Mat currentColumnFeature(windowNumber,2,CV_64FC1);
		/*Mat currentColumnFeatureRow(1,2 * windowNumber,CV_8UC1);*/

		for (int j=0; j < windowNumber; j++ )
		{
			/*int aaa = j * step + 1;*/
			Mat windowData = currentColumnData(Range(j * step, j * step + currentParametersSettings.windowLength),Range::all());
			Mat windowFeature = getWindowFeature(windowData);
			/*double ff = windowFeature.at<double>(0,0);*/
			windowFeature.copyTo(currentColumnFeature.row(j));
			/*double gg = currentColumnFeature.at<double>(0,0);*/
			/*hconcat(currentColumnFeature,windowFeature,currentColumnFeature);*/
// 			Mat R(4, 3, CV_32F); // [4 rows x 3 cols] with float values
// 			mat1.copyTo(R.col(0));
// 			mat2.copyTo(R.col(1));
// 			mat3.copyTo(R.col(2));
// 			vector aa = windowData.data;
		}
		
		/*vconcat(currentColumnFeature.row(1),currentColumnFeature.row(2),currentColumnFeatureRow);*/
		Mat currentColumnFeatureRow = currentColumnFeature.reshape(1,2 * windowNumber);
		/*double gg = currentColumnFeatureRow.at<double>(0,0);*/
		/*hconcat(currentImageFeature,currentColumnFeatureRow,currentImageFeature);*/
		currentColumnFeatureRow.copyTo(currentImageFeature.col(i));
		/*vconcat(currentImageFeature,currentColumnFeatureRow,currentImageFeature);*/
	}
	
	return currentImageFeature.reshape(1,currentImageFeature.rows*currentImageFeature.cols).t();
}

const Mat getWindowFeature(const Mat & windowData)
{
	Mat windowMean,windowStd,windowFeature;
	meanStdDev(windowData,windowMean,windowStd);
	/*double dd = windowStd.at<double>(0,0);*/
	hconcat(windowMean,windowStd,windowFeature);
	return windowFeature;
}

// const Mat & getFeatureVector(const Mat & grayImage, const Video_play::parametersSettings & currentParametersSettings)
// {
// 	int a = grayImage.cols;
// 	return grayImage;
// }