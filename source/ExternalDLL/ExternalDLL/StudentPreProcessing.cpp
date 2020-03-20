#include "StudentPreProcessing.h"
#include <vector>

#include "ImageIO.h"
#include "GrayscaleAlgorithm.h"
#include "ImageFactory.h"
#include "HereBeDragons.h"


IntensityImage * StudentPreProcessing::stepToIntensityImage(const RGBImage &image) const {
	return nullptr;
}

IntensityImage * StudentPreProcessing::stepScaleImage(const IntensityImage &image) const {
	return nullptr;
}

IntensityImage * StudentPreProcessing::stepEdgeDetection(const IntensityImage &image) const {
	//std::vector<int> a = cv::getGaussianKernel(9, 1.0);
	//std::vector<std::vector<float>> a = { {0.01, 0.08, 0.01}, {0.08, 0.64, 0.08}, {0.01, 0.08, 0.01} }

	//for (int i = 0; i < a.size() - 1; i++) {
	//	std::cout << a[i];
	//}

	std::vector<std::vector<int>> blur = {	{1, 2, 1}, 
											{2, 4, 2}, 
											{1, 2, 1} };
	/*std::vector<int> blur_x = {1, 2, 1};
	std::vector<int> blur_y = {1, 2, 1};*/

	/*std::vector<std::vector<int>> result;
	std::vector<std::vector<int>> result_x;
	std::vector<std::vector<int>> result_y;*/

	for (int i = 1; i < image.getHeight - 1; i++) {
		for (int j = 1; j < image.getWidth - 1; j++) {
			int new_val = 0;
			std::vector<int> tmp_res = 
			{	blur[0][0] * image.getPixel(j - 1, i -1),	blur[0][1] * image.getPixel(j , i - 1), blur[0][2] * image.getPixel(j + 1, i - 1),
				blur[1][0] * image.getPixel(j - 1, i),		blur[1][1] * image.getPixel(j , i),		blur[1][2] * image.getPixel(j + 1 , i),
				blur[2][0] * image.getPixel(j - 1, i + 1),	blur[2][1] * image.getPixel(j , i + 1),	blur[2][2] * image.getPixel(j + 1, i + 1) };
			for (unsigned int i = 0; i < tmp_res.size(); i++) {
				new_val += tmp_res[i];
			}
			//image.setPixel(j, i, new_val);
		}
	}
	return nullptr;
}

IntensityImage * StudentPreProcessing::stepThresholding(const IntensityImage &image) const {
	return nullptr;
}