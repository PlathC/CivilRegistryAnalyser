//
// Created by Platholl on 01/12/2020.
//

#ifndef CIVILREGISTRYANALYSER_SEGMENTATION_HPP
#define CIVILREGISTRYANALYSER_SEGMENTATION_HPP

#include "Model/TextSegmentation/Preprocessing.hpp"

namespace segmentation
{
    std::vector<cv::Rect> SegmentCivilStates(const cv::Mat& rawImage);
    std::vector<std::tuple<cv::Rect, cv::Mat>> DetectQuarters(const cv::Mat& img, const int stepDivider);
}

#endif //CIVILREGISTRYANALYSER_SEGMENTATION_HPP
