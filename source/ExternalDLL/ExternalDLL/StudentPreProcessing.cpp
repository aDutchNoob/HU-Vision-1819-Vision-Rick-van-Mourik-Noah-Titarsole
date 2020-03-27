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
	// Gaussian
	cv::Mat image_matrix;
	HereBeDragons::HerLoveForWhoseDearLoveIRiseAndFall(image, image_matrix)

	std::vector<std::vector<int>> blur = {	{1, 2, 1}, 
						{2, 4, 2}, 
						{1, 2, 1} };
	/*std::vector<int> blur_x = {1, 2, 1};
	std::vector<int> blur_y = {1, 2, 1};*/

	for (int i = 1; i < image_matrix.size() - 1; i++) {
		for (int j = 1; j < image_matrix[i].size() - 1; j++) {
			int new_val = (	blur[0][0] * image_matrix[i-1][j-1] + blur[0][1] * image_matrix[i][j-1] + blur[0][2] * image_matrix[i+1][j-1] + 
					blur[1][0] * image_matrix[i-1][j] + blur[1][1] * image_matrix[i][j] + blur[1][2] * image_matrix[i+1][j] + 
					blur[2][0] * image_matrix[i-1][j+1] + blur[2][1] * image_matrix[i][j+1] + blur[2][2] * image_matrix[i+1][j+1]
				      ) / 16;
			
			image_matrix[i][j] = new_val;
			
		}
	}
	return nullptr;
}

IntensityImage * StudentPreProcessing::stepThresholding(const IntensityImage &image) const {
	return nullptr;
}
