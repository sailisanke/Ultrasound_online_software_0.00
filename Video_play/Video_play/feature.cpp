#include "feature.h"
#include <core\core_c.h>

const Mat getImageFeature(const Mat & grayImage, const Video_play::parametersSettings & currentParametersSettings)
{
	int imageColumnDistance = grayImage.cols/(currentParametersSettings.channelNumber + 1);
	int step = currentParametersSettings.windowLength-currentParametersSettings.overlap;
	int windowNumber = (grayImage.rows - currentParametersSettings.windowLength)/step + 1;
	Mat currentImageFeature( 2 * windowNumber,currentParametersSettings.channelNumber,CV_64F);
	for (int i = 0; i < currentParametersSettings.channelNumber; i ++)
	{
		int channelPosition = imageColumnDistance * (i + 1);
		Mat currentColumnData = grayImage.col(channelPosition);

		Mat currentColumnFeature(windowNumber,2,CV_64F);
		/*Mat currentColumnFeatureRow(1,2 * windowNumber,CV_8UC1);*/

		for (int j=0; j < windowNumber; j++ )
		{
			/*int aaa = j * step + 1;*/
			Mat windowData = currentColumnData(Range(j * step, j * step + currentParametersSettings.windowLength),Range::all());

			//判断使用哪种特征
			Mat windowFeature;
			if (currentParametersSettings.featureType == "mean and variance")
			{
				windowFeature = getWindowFeatureMeanVar(windowData);
			}
			else if(currentParametersSettings.featureType == "fitting coefficient")
			{
				windowFeature = getWindowFeatureCoefficient(windowData);
			}
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



//提取分析窗中的灰度值的均值和方差作为特征
const Mat getWindowFeatureMeanVar(const Mat & windowData)
{
	Mat windowMean,windowStd,windowFeature;
	meanStdDev(windowData,windowMean,windowStd);
	/*double dd = windowStd.at<double>(0,0);*/
	hconcat(windowMean,windowStd,windowFeature);
	return windowFeature;
}

//提取分析窗中灰度值的拟合系数作为特征
const Mat getWindowFeatureCoefficient(const Mat & windowData)
{
// 	double A=0,B=0,C=0,D=0;
// 	double tmp,k,b;
// 	/*int* pimg = (int*)(windowData.data);*/
// 	for (int i=1;i<=windowData.rows;i++)
// 	{
// 		A += i*i;
// 		B += i;
// 		uchar imgray = windowData.data[i-1];
// 		C += i*imgray;
// 		D += imgray;
// 	}
// 	tmp = A*windowData.rows-B*B; 
// 	k = (C*windowData.rows-B*D)/tmp; 
// 	b = (A*D-C*B)/tmp;
//  两种方法都可以
	double x_mean = (1+windowData.rows)/2.0;
	double y_mean,y_sum;
	for (int i=0;i<windowData.rows;i++)
	{
		y_sum += windowData.data[i];
	}
	y_mean = y_sum/windowData.rows;
	double lxy = 0,lxx = 0;
	for (int i=0;i<windowData.rows;i++)
	{
		uchar yi = windowData.data[i];
		lxy += ((i+1)-x_mean) * (yi-y_mean);
		lxx += ((i+1)-x_mean) * ((i+1)-x_mean);
	}

	double k = lxy/lxx;
	double b = y_mean - k*x_mean; 

	Mat windowFeature = (Mat_<double>(1,2) << k,b);

// 	Mat windowMean,windowStd,windowFeature;
// 	meanStdDev(windowData,windowMean,windowStd);
// 	/*double dd = windowStd.at<double>(0,0);*/
// 	hconcat(windowMean,windowStd,windowFeature);
// 	cvMul()
// 	Mat windowMean,windowStd,windowFeature;
// 	meanStdDev(windowData,windowMean,windowStd);
// 	/*double dd = windowStd.at<double>(0,0);*/
// 	hconcat(windowMean,windowStd,windowFeature);
	return windowFeature;
}

// const Mat & getFeatureVector(const Mat & grayImage, const Video_play::parametersSettings & currentParametersSettings)
// {
// 	int a = grayImage.cols;
// 	return grayImage;
// }